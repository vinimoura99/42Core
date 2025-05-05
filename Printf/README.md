# 🖨️ ft_printf

A custom re-implementation of the C standard library's `printf` function.  
Built as part of the 42 School curriculum, this project was designed to deepen understanding of formatted output, variadic functions, and manual data formatting in C.

> 📦 Part of [vinimoura99/42core](https://github.com/vinimoura99/42core)

---

## 🎯 Goal

Recreate `printf` from scratch using only a limited set of allowed functions:  
`write`, `malloc`, `free`, and `va_*` from `<stdarg.h>`.

The final result is a fully functional, modular, and norm-compliant version of `printf`, capable of handling multiple format specifiers.

---

## ✅ Supported Conversions

| Specifier | Output                          |
|----------:|----------------------------------|
| `%c`      | Character                        |
| `%s`      | String                           |
| `%p`      | Pointer (memory address)         |
| `%d`/`%i` | Signed integer                   |
| `%u`      | Unsigned integer                 |
| `%x`/`%X` | Hexadecimal (lowercase/uppercase)|
| `%%`      | Literal `%` character            |

---

## 🛠️ Building the Project

Clone the repository and build the static library:

```bash
git clone https://github.com/vinimoura99/42core.git
cd 42core/Printf
make
````

This generates `libftprintf.a`, which you can link to in your projects.

---

## 📄 Example Usage

```c
#include "ft_printf.h"

int main(void)
{
    int count = ft_printf("Hello %s! Value: %d\n", "world", 42);
    ft_printf("Printed %d characters.\n", count);
    return 0;
}
```

Compile with:

```bash
gcc main.c libftprintf.a -Iincludes
```

---

## 🧱 Project Structure

```
Printf/
├── includes/
│   └── ft_printf.h          # Function declarations and macros
├── src/
│   ├── ft_printf.c          # Core parser and dispatcher
│   ├── ft_putnbr_base.c     # Number to base string conversions
│   └── str_utils.c          # Custom string functions
├── Makefile                 # Build rules for the static lib
└── .gitignore               # Standard ignore rules
```

---

## 🧠 Highlights

* Manual number and pointer formatting (hex, decimal)
* Variadic argument handling with `stdarg.h`
* Fully modular code with separate utility files
* 100% compliant with the [42 Norm](https://github.com/42School/norminette)

---

## 📘 Notes

* This implementation doesn't cover all GNU `printf` flags or width/precision — only the mandatory part of the project.
* Clean, understandable codebase to serve as a base for learning or extension.

---

## 📜 License

This project is shared for learning and reference purposes.
Feel free to explore, learn from it, or use it to inspire your own implementation.

---



