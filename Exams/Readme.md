# Exams

The **Exams** folder contains the final projects for the 42 School curriculum. Each project corresponds to an **exam rank**, where each exam tests a different set of skills and programming concepts in C, C++, and system-level programming.

> 📦 Part of [vinimoura99/42core](https://github.com/vinimoura99/42core)  
> Explore other projects: [`libft`](https://github.com/vinimoura99/42core/tree/main/libft), [`ft_printf`](https://github.com/vinimoura99/42core/tree/main/printf), [`get_next_line`](https://github.com/vinimoura99/42core/tree/main/Get_Next_Line)

---

## 🎯 Exam Structure

### **Exam Rank 2: Libft**
- **Objective**: Implement your own C library, `libft`, with commonly used functions like string manipulation, memory allocation, and more.
- **Focus**: Memory management, C standard library functions, and creating reusable utilities.
- **Skills Tested**: 
  - Memory management (`malloc`, `free`)
  - String manipulation
  - Data structures and algorithms

### **Exam Rank 3: ft_printf or Get Next Line**
- **Objective**:
  - **`ft_printf`**: Recreate the `printf` function, handling different types of format specifiers.
  - **`Get Next Line`**: Implement `get_next_line()` to read one line from a file descriptor at a time.
- **Focus**: Formatted output or file I/O.
- **Skills Tested**: 
  - Variable argument handling (`printf`)
  - Efficient file I/O and memory management (`get_next_line`)

### **Exam Rank 4: Minishell**
- **Objective**: Create a simple shell program that mimics basic shell functionality like command execution, piping, and redirection.
- **Focus**: Process control, system calls, and handling shell commands.
- **Skills Tested**:
  - Process creation and management (`fork()`, `exec()`)
  - Shell input/output redirection
  - Signal handling and command parsing

### **Exam Rank 5: C++ (up to C++03)**
- **Objective**: Transition from C to C++ by implementing object-oriented solutions using classes, inheritance, and polymorphism.
- **Focus**: Object-oriented programming and memory management in C++.
- **Skills Tested**: 
  - Class design and abstraction
  - Memory management in C++ (`new`, `delete`)
  - Operator overloading and inheritance

### **Exam Rank 6: Miniserver**
- **Objective**: Build a simple HTTP web server that can handle client requests, serve files, and manage connections.
- **Focus**: Networking, system-level programming, and HTTP protocols.
- **Skills Tested**:
  - Socket programming and handling client-server communication
  - HTTP request parsing and response generation
  - Multi-client handling and concurrency

---

## 📂 Project Structure

```

Exams/
├── includes/
│   └── exam\_utils.h            # Utility functions used across tasks
├── src/
│   ├── rank\_2\_libft.c          # Rank 2 - Libft implementation
│   ├── rank\_3\_printf.c         # Rank 3 - ft\_printf implementation
│   ├── rank\_3\_get\_next\_line.c  # Rank 3 - Get Next Line implementation
│   ├── rank\_4\_minishell.c      # Rank 4 - Minishell implementation
│   ├── rank\_5\_cpp.cpp          # Rank 5 - C++ implementation
│   └── rank\_6\_miniserver.c     # Rank 6 - Miniserver implementation
├── Makefile                    # Build instructions for compiling all tasks
└── .gitignore                  # Git ignore rules for unnecessary files

````

---

## 🚀 Getting Started

### 1. Clone and Build

```bash
git clone https://github.com/vinimoura99/42core.git
cd 42core/Exams
make
````

This will compile all the exam tasks for **Rank 2**, **Rank 3**, **Rank 4**, **Rank 5**, and **Rank 6**.

### 2. Example Usage

```c
#include "exam_utils.h"

int main(void)
{
    // Example usage for Rank 2 - Libft
    rank_2_libft();
    return 0;
}
```

Compile your program with:

```bash
gcc main.c -Iincludes -o exam_program
```

---

## 🧠 Key Concepts

* **Rank 2**: Low-level programming, memory management, and creating utility functions.
* **Rank 3**: Formatted output and file I/O handling.
* **Rank 4**: System-level programming, creating a shell, process management, and redirection.
* **Rank 5**: Object-oriented programming in C++.
* **Rank 6**: Networking, HTTP protocols, and building a simple web server.

---

## 📜 Notes

* Each exam rank has its own focus and difficulty level, starting from basic C skills (Rank 2) to advanced topics like multi-threading and web servers (Rank 6).
* **Rank 2** and **Rank 3** are heavily focused on C, while **Rank 5** and **Rank 6** introduce C++ and system-level programming concepts.
* All exams must be done individually and within a specified time limit.

---

## 📌 License

This project is part of the 42 curriculum and is for educational purposes only.
Feel free to explore, use it for reference, or contribute!

---

```

---

### 🧹 Key Features:
- **Structured Overview**: Each exam rank is clearly defined with its objective, focus, and skills tested.
- **Clean Project Layout**: The project structure is easy to navigate, with each rank clearly separated.
- **Clear Instructions**: Step-by-step instructions for compiling and running the projects.


