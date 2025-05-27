# Libft

**Libft** is a fundamental library written in C, developed as part of the curriculum at **42 Porto**.  
It reimplements key functions from the standard C library as well as some utility functions, all coded from scratch following strict project guidelines.

## 📦 Description

The goal of this project is to understand the inner workings of common C functions, learn how to handle memory manually, and structure a reusable library.  
All functions are implemented without using any external libraries, except for `write`, `malloc`, and `free`.

---

## ✅ Functions Implemented

### Part 1 — Libc Functions

- `ft_isalpha`  
- `ft_isdigit`  
- `ft_isalnum`  
- `ft_isascii`  
- `ft_isprint`  
- `ft_strlen`  
- `ft_memset`  
- `ft_bzero`  
- `ft_memcpy`  
- `ft_memmove`  
- `ft_strlcpy`  
- `ft_strlcat`  
- `ft_toupper`  
- `ft_tolower`  
- `ft_strchr`  
- `ft_strrchr`  
- `ft_strncmp`  
- `ft_memchr`  
- `ft_memcmp`  
- `ft_strnstr`  
- `ft_atoi`  
- `ft_calloc`  
- `ft_strdup`

### Part 2 — Additional Functions

- `ft_substr`  
- `ft_strjoin`  
- `ft_strtrim`  
- `ft_split`  
- `ft_itoa`  
- `ft_strmapi`  
- `ft_striteri`  
- `ft_putchar_fd`  
- `ft_putstr_fd`  
- `ft_putendl_fd`  
- `ft_putnbr_fd`

### Bonus — Linked List Functions (if implemented)

- `ft_lstnew`  
- `ft_lstadd_front`  
- `ft_lstsize`  
- `ft_lstlast`  
- `ft_lstadd_back`  
- `ft_lstdelone`  
- `ft_lstclear`  
- `ft_lstiter`  
- `ft_lstmap`

---

## 📁 Structure

```
libft/
├── ft_*.c            # Source files for each function
├── libft.h           # Header file with all function prototypes
├── Makefile          # For compilation
└── README.md         # This file
```

---

## 🧪 Compilation & Usage

### Compile the library:

```bash
make
```

This produces `libft.a`, a static library ready to be linked in your C projects.

### Clean or rebuild:

```bash
make clean     # removes object files
make fclean    # removes object files and libft.a
make re        # rebuilds everything
```

### Example usage:

```c
#include "libft.h"

int main(void)
{
    char str[] = "Hello 42";
    ft_putstr_fd(str, 1);
    return 0;
}
```

Compile with:

```bash
gcc main.c -L. -lft
```

---

## 📜 License

This library was created as a project at [42 Porto](https://42porto.com) and is meant for educational purposes only.

---

## 👤 Author

- GitHub: [vinimoura99](https://github.com/vinimoura99)

---
