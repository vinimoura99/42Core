# Minitalk Project Guide

## 🚀 Introduction

Welcome to Minitalk! This project is a fascinating exercise in understanding low-level inter-process communication (IPC) on UNIX-like systems. The goal is to create a client program that sends a string message to a server program, using only two UNIX signals: `SIGUSR1` and `SIGUSR2`.

This project will help you grasp:
*   The fundamentals of UNIX signals.
*   Basic client-server architecture.
*   How data (like characters) can be represented and transmitted bit by bit.
*   The importance of synchronization in communication.

## 🧠 Core Concepts

Before diving into the implementation, let's understand the key concepts Minitalk revolves around:

1.  **UNIX Signals (`SIGUSR1`, `SIGUSR2`):**
    *   Signals are a limited form of asynchronous IPC used in UNIX systems. They notify a process of an event.
    *   `SIGUSR1` and `SIGUSR2` are user-defined signals, meaning they have no predefined system action and are available for applications to use for their own purposes. In Minitalk, we use them to represent binary digits (bits).

2.  **Inter-Process Communication (IPC):**
    *   Minitalk demonstrates a very basic form of IPC. The client and server are separate processes that need to exchange information (the message string).

3.  **Bitwise Operations & Data Representation:**
    *   Computers store all data, including characters, in binary format (as a sequence of 0s and 1s).
    *   To send a character, Minitalk breaks it down into its individual bits. For example, the character 'A' (ASCII 65) is `01000001` in binary.
    *   The server then reconstructs these bits back into characters.

4.  **Process IDs (PID):**
    *   Each running process on a UNIX system has a unique Process ID.
    *   The client needs to know the server's PID to send signals specifically to that server process.

## 🛠️ How It Works: The Communication Protocol

The magic of Minitalk lies in its communication protocol, which defines how the client and server talk to each other using only `SIGUSR1` and `SIGUSR2`.

### Client-Side Logic

1.  **Input:** The client program takes two arguments: the server's PID and the message string to send.
2.  **Character by Character:** The client processes the input message one character at a time.
3.  **Bit by Bit Transmission:** For each character:
    *   It converts the character into its 8-bit binary representation.
    *   It iterates through these 8 bits (typically from the most significant bit to the least significant bit).
    *   If a bit is `1`, the client sends `SIGUSR1` to the server's PID.
    *   If a bit is `0`, the client sends `SIGUSR2` to the server's PID.
4.  **Synchronization Pause:** After sending each bit (each signal), the client pauses for a very short duration (e.g., using `usleep`). This tiny delay is crucial! It gives the server a moment to process the received signal before the next one arrives, reducing the chance of signals being missed or overwhelming the server.
5.  **End of Message:** After all characters in the message string have been sent, the client sends one final character: the null terminator (`\0`). This special character, also sent bit by bit, signals to the server that the entire message has been transmitted.

### Server-Side Logic

1.  **Startup:** When the server starts, it first prints its own PID to the console. The client will use this PID.
2.  **Signal Handling Setup:** The server configures itself to "listen" for `SIGUSR1` and `SIGUSR2`. It does this by setting up a special function, called a signal handler, that will be automatically executed whenever one of these signals arrives.
3.  **Waiting for Signals:** The server then enters an infinite loop, typically using the `pause()` system call. `pause()` puts the server to sleep until a signal is received.
4.  **The Signal Handler - Reconstructing the Message:** This is where the core logic resides:
    *   **Bit Accumulation:** The server maintains a temporary buffer (e.g., a `char` variable) to build the current character and a counter for the number of bits received for that character.
    *   When `SIGUSR1` arrives, the server knows the current bit is a `1` and sets the corresponding bit in its character buffer.
    *   When `SIGUSR2` arrives, the server knows the current bit is a `0`. (Often, if the character buffer is initialized to zeros, no explicit action is needed for a '0' bit, as the bit is already zero).
    *   The bit counter is incremented.
    *   **Character Completion:** Once 8 bits have been received (the bit counter reaches 8):
        *   A complete character has been reconstructed.
        *   **End of Message Check:** If this reconstructed character is the null terminator (`\0`), it means the entire message has been received. The server then:
            *   Prints the fully assembled message string to the console.
            *   Resets its state (clears the message string buffer, bit counter, and character buffer) to be ready for a new message from a client.
        *   **Append Character:** If the character is not `\0`, it's part of the ongoing message. The server appends this character to a dynamically growing string that holds the complete message received so far.
        *   The temporary character buffer and bit counter are reset to prepare for the next 8 bits (the next character).

## 📁 Project Structure

A typical Minitalk project will have the following files:

*   `server` (or `server.c`): The source code for the server program.
*   `client` (or `client.c`): The source code for the client program.
*   `minitalk.h` (or similar): A header file containing common function prototypes, includes, and possibly macro definitions used by both client and server.
*   `utils.c` (or similar, possibly part of a `libft`): Contains utility functions that might be shared, such as:
    *   Functions to print characters or strings (`ft_putchar`, `ft_putstr`).
    *   A function to convert a string to an integer (`ft_atoi`), used by the client to parse the server PID.
    *   Possibly string manipulation functions if the server builds the message string dynamically.
*   `Makefile`: A script to automate the compilation of the server and client executables.

## ⚙️ Compilation and Usage

### Compilation

1.  Navigate to your Minitalk project directory in the terminal.
2.  Run the command `make`.
    *   This will use the `Makefile` to compile your `server.c` and `client.c` (along with any utility files) into executable files, typically named `server` and `client`.
    *   The compilation usually includes flags like `-Wall -Wextra -Werror` to catch common coding errors.

### Running Minitalk

1.  **Start the Server:**
    *   In a terminal window, execute: `./server`
    *   The server will start and print its PID. For example: `Server PID: 12345`
    *   Note down this PID. The server will now wait patiently for signals.

2.  **Run the Client:**
    *   Open another terminal window (or use a terminal multiplexer like `tmux` or `screen`).
    *   Execute the client with the server's PID and your desired message:
        `./client <SERVER_PID> "Your message here"`
    *   Replace `<SERVER_PID>` with the actual PID you noted from the server's output.
    *   Replace `"Your message here"` with the string you want to send. Make sure to enclose messages with spaces in quotes.
    *   Example: `./client 12345 "Hello Minitalk from 42!"`

3.  **Observe the Outcome:**
    *   If everything works correctly, the message sent by the client will appear in the server's terminal window.

## 🎓 Key Learnings & Educational Value

This project is more than just sending strings; it's a practical dive into:
*   **Signal Handling:** You'll learn how to define and register signal handlers and how processes react to signals.
*   **Low-Level Data Representation:** Understanding that characters are just sequences of bits and how to manipulate them.
*   **Basic IPC:** Getting a feel for how separate processes can communicate, even with simple tools.
*   **Synchronization:** Realizing the need for timing and coordination (like `usleep`) when processes interact asynchronously.
*   **Problem Solving:** Debugging issues related to signal loss, incorrect bit manipulation, or faulty server state management.
*   **Dynamic Memory Management:** If your server dynamically allocates memory to store the incoming message, you'll practice `malloc` and `free`.

## ✨ Potential Challenges and Enhancements (Bonus Considerations)

While the basic Minitalk is a great learning tool, you might encounter or consider these:

*   **Signal Loss:** UNIX signals are not always guaranteed to be delivered, especially if sent too rapidly or if the system is under heavy load. The `usleep` in the client helps but isn't foolproof.
*   **Acknowledgment (ACK) System:** For more robust communication, the server could send a signal back to the client (an "acknowledgment") after successfully receiving each bit or character. This would allow the client to wait for confirmation before sending the next piece of data, greatly improving reliability.
*   **`signal()` vs. `sigaction()`:** While `signal()` is simpler to use, `sigaction()` is the more modern, portable, and powerful way to handle signals. It offers more control and can provide information about the sender of the signal (useful for an ACK system or handling multiple clients).
*   **Handling Multiple Clients:** The basic server described typically handles one message from one client at a time. If multiple clients try to send messages simultaneously, their bits might interleave, corrupting the messages. A more advanced server might use client PIDs (obtained via `sigaction` and `siginfo_t`) to differentiate messages or implement a queuing system.
*   **Efficiency of String Building:** If the server appends characters one by one to a dynamically growing string by reallocating memory each time, it can become inefficient for very long messages. More advanced string-building techniques could be explored.
*   **Unicode/UTF-8 Support:** The basic Minitalk usually handles ASCII characters. Extending it to support multi-byte UTF-8 characters would be a significant challenge, requiring a more complex protocol to handle variable-length character encodings.

Happy coding, and enjoy the journey into the world of signals with Minitalk!