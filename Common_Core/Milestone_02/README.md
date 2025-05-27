# Milestone 2 — Intermediate Projects

This repository contains the second set of core projects completed at 42 Porto, designed to strengthen algorithmic thinking, event-driven programming, and interprocess communication.

---

## 🎮 so_long

A 2D graphical game project using the MiniLibX library.  
You must create a simple top-down game where the player collects items and reaches an exit, all while rendering the game map and handling input.

**Features:**
- Reads `.ber` maps (validated)
- Renders a 2D tile-based environment
- Player movement (keyboard controls)
- Enemies and collectibles (optional for bonus)
- Exit after collecting all items

Directory: `so_long/`

---

## 📡 minitalk

Implements client-server communication using UNIX signals (`SIGUSR1`, `SIGUSR2`).  
The client sends a string to the server, one bit at a time, through signals.

**Features:**
- Bit-level signal encoding
- Server receives and prints messages
- Bonus: Acknowledgements, extended features

Directory: `minitalk/`

---

## 🔀 push_swap

A sorting algorithm project where you must sort integers using two stacks and a limited set of operations.

**Features:**
- Efficient sorting with custom algorithm
- Limited commands (`sa`, `ra`, `pb`, etc.)
- Optimized for fewest moves
- Checker (bonus): validates instruction sequences

Directory: `push_swap/`

---

## 🧰 Build Instructions

Each project has its own `Makefile`. Inside each folder, run:

```bash
make
```

To clean or rebuild:

```bash
make clean
make fclean
make re
```

---

## 🧪 Testing

Use provided test maps, test cases, and checker scripts (especially for `push_swap`).  
Refer to each project’s README or source code for detailed usage instructions.

---

## 👤 Author

- GitHub: [vinimoura99](https://github.com/vinimoura99)

---

## 🏫 School

- [42 Porto](https://42porto.com)

---