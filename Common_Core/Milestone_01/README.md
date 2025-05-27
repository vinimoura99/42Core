# Milestone 1 — Core Projects

This repository contains the foundational projects completed during the first milestone at 42 Porto.  
These projects focus on mastery of C fundamentals, memory management, and standard library reimplementation.

---

## 📁 Projects Included

### 🔧 Born to Be Root

This is the initial system-level project where you get introduced to UNIX-like systems, shell usage, permissions, and basic tools.  
It’s the first step in understanding how everything works underneath a higher-level programming language.

### 🖨️ ft_printf

Reimplementation of the standard `printf` function in C.  
Handles various conversions and flags, formatted output, and variadic arguments.

**Features:**
- `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`
- Custom formatting parser
- Uses `write` only — no standard library I/O functions

Directory: `Printf/`

### 📄 Get Next Line

Reads a file line-by-line, returning one line at a time per call.

**Features:**
- Efficient buffer management
- Works with any file descriptor
- Supports reading from multiple FDs simultaneously

**Functions:**
- `get_next_line`
- `get_next_line_utils`

Directory: `get_next_line/`

---

## 🧰 Build Instructions

Each project contains its own `Makefile`.

Navigate into each folder and run:

```bash
make
```

To clean or rebuild:

```bash
make clean     # remove object files
make fclean    # remove objects + binary
make re        # full rebuild
```

---

## 🧪 Testing

Each project can be compiled into a test binary or included in larger projects (e.g., your Libft or exam environment).  
Refer to each folder’s documentation or header files for function signatures and usage.

---

## 👤 Author

- GitHub: [vinimoura99](https://github.com/vinimoura99)

---

## 🏫 School

- [42 Porto](https://42porto.com)

---