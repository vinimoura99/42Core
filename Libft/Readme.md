# Libft

Welcome to the **Libft** project! This project involves recreating a set of standard C library functions from scratch. The purpose is to gain a deeper understanding of how low-level functions work in C and improve memory management and pointer manipulation skills.

---

## 📝 Table of Contents

* [About Libft](#about-libft)
* [Functions Implemented](#functions-implemented)
* [Compiling Libft](#compiling-libft)
* [Testing Libft](#testing-libft)
* [Contributing](#contributing)
* [License](#license)

---

## 🧐 About Libft

The goal of **Libft** is to create a custom C library by implementing a set of standard C functions that are commonly used in programming. These functions include memory management routines, string manipulation functions, and more.

You will implement various functions such as:

* `malloc()`
* `free()`
* `strdup()`
* `memcpy()`
* And others

By completing this project, you will strengthen your understanding of **pointers**, **memory management**, and **low-level C programming**.

---

## ⚙️ Functions Implemented

Here’s a list of some of the functions implemented in **Libft**:

* **Memory management functions**:

  * `malloc()`
  * `free()`
  * `calloc()`
  * `realloc()`

* **String manipulation functions**:

  * `strlen()`
  * `strdup()`
  * `strcpy()`
  * `strcat()`
  * `strcmp()`
  * `strchr()`

* **Character classification functions**:

  * `isdigit()`
  * `isalpha()`
  * `isalnum()`

* **Other utility functions**:

  * `bzero()`
  * `memset()`
  * `memcpy()`
  * `strstr()`

Each function is tested individually to ensure that it works as expected, and they are implemented without using the equivalent standard library functions.

---

## 💻 Compiling Libft

To compile **Libft**, follow the steps below:

1. **Clone the repository** (if you haven't already):

   ```bash
   git clone https://github.com/vinimoura99/42core.git
   ```

2. **Navigate to the `libft` directory**:

   ```bash
   cd 42core/libft
   ```

3. **Run `make` to compile the library**:

   ```bash
   make
   ```

   This will generate a `libft.a` static library.

4. **To clean up compiled files**, run:

   ```bash
   make clean
   ```

5. **To remove all compiled objects (including the `.a` file)**, run:

   ```bash
   make fclean
   ```

---

## 🧪 Testing Libft

To test your implementation of the library, you can create a simple program that includes your custom library and tests each function.

1. **Create a `main.c` file** in the `libft` directory and include the necessary headers for your functions.

2. **Compile the `main.c` file** with `libft.a`:

   ```bash
   gcc -o test_program main.c libft.a
   ```

3. **Run the test program** to check that all functions work as expected:

   ```bash
   ./test_program
   ```

Feel free to add more tests as necessary for additional coverage.

---

## 🤝 Contributing

We welcome contributions to the **Libft** project! If you have any improvements, bug fixes, or new features to contribute, feel free to fork this repository and submit a pull request.

### How to Contribute:

1. **Fork** the repository
2. **Clone** your forked repository to your local machine
3. **Make your changes** or improvements
4. **Submit a pull request** with a detailed description of your changes

Please ensure that your contributions align with the **[42 coding standards](https://github.com/42School/coding-standards)**.

---

## 📜 License

This repository is licensed under the MIT License. See the [LICENSE](../../LICENSE) file for more details.


