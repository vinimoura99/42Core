# get_next_line

A C project from the [42 School](https://42.fr/en/homepage/) curriculum.  
The goal is to create a function that reads a line from a file descriptor, managing memory and efficiently handling input from both files and standard input (`stdin`).

> 📦 Part of [vinimoura99/42core](https://github.com/vinimoura99/42core)  
> Explore other projects: [`libft`](https://github.com/vinimoura99/42core/tree/main/libft), [`ft_printf`](https://github.com/vinimoura99/42core/tree/main/printf)

---

## 🎯 Objective

The task is to implement the `get_next_line` function that:
- Reads one line at a time from a file descriptor (`stdin` or any file).
- Handles large input efficiently with proper dynamic memory management.
- Ensures that all the content from the file is read correctly, even with multiple calls.

---

## 📂 Project Structure

```

Get\_Next\_Line/
├── includes/
│   └── get\_next\_line.h         # Header with function prototypes and necessary includes
├── src/
│   ├── get\_next\_line.c         # Main logic for reading lines
│   └── get\_next\_line\_utils.c   # Helper functions (buffering, memory management)
├── Makefile                    # Build rules to compile the static lib
└── .gitignore                  # Git ignore rules for unnecessary files

````

---

## 🚀 Getting Started

### 1. Clone and Build

```bash
git clone https://github.com/vinimoura99/42core.git
cd 42core/Get_Next_Line
make
````

This compiles the static library `libft.a` (if needed) and the `get_next_line.a` object file.

### 2. Example Usage

```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("my_file.txt", O_RDONLY);
    char *line;

    while (get_next_line(fd, &line) > 0)
    {
        printf("%s\n", line);  // Print each line
        free(line);  // Free after use
    }
    close(fd);
    return 0;
}
```

Compile your program:

```bash
gcc main.c get_next_line.a -Iincludes -o my_program
```

---

## 🧠 Key Concepts

* **Memory Management**: Dynamically allocating and freeing memory for each line.
* **Buffered Input**: Efficiently handling buffered input for reading large files or streams.
* **File Descriptors**: Support for reading from both files and standard input.

---

## 📜 Notes

* The function reads lines until the end of file (`EOF`) or the end of the line.
* It works with `stdin` as well as regular files.
* The implementation focuses on **efficiency**, handling multiple file descriptors and avoiding memory leaks.

---

## 📌 License

This project is part of the 42 curriculum and is for educational purposes only.
Feel free to explore, use it for reference, or contribute!

---

```

---

### 🧹 Final Touches:
- **Unified Format**: Matches the style and tone of your `ft_printf` and other `README` files.
- **Clean and Simple**: Clear structure, easy-to-read formatting.
- **Direct and To the Point**: Focuses on what the user needs without being too verbose.


