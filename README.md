*This project has been created as part of the 42 curriculum by alesferr.*

# ft_printf

## Description

`ft_printf` is a custom implementation of the standard C `printf()` function. The goal of this project is to recreate one of the most commonly used functions from the C Standard Library while gaining a deeper understanding of:

* Variadic functions (`stdarg.h`)
* Formatted output
* Recursive algorithms
* Low-level output using `write()`
* Modular program design

The implementation reproduces the behavior of the original `printf()` for the mandatory conversion specifiers without using the standard library implementation.

---

# Supported Conversions

| Specifier | Description              |
| --------- | ------------------------ |
| `%c`      | Character                |
| `%s`      | String                   |
| `%p`      | Pointer address          |
| `%d`      | Signed decimal integer   |
| `%i`      | Signed integer           |
| `%u`      | Unsigned decimal integer |
| `%x`      | Hexadecimal (lowercase)  |
| `%X`      | Hexadecimal (uppercase)  |
| `%%`      | Percent sign             |

---

# Project Structure

```text
ft_printf/
├── ft_printf.c
├── ft_putchar.c
├── ft_putstr.c
├── ft_putnbr.c
├── ft_putnbr_unsigned.c
├── ft_puthex.c
├── ft_putptr.c
├── ft_printf.h
├── Makefile
└── README.md
```

---

# Instructions

## Clone the repository

```bash
git clone https://github.com/your_username/ft_printf.git
cd ft_printf
```

Replace `your_username` with your GitHub username.

---

## Compile

Compile the library using:

```bash
make
```

This generates:

```text
libftprintf.a
```

Available Makefile rules:

```bash
make
make clean
make fclean
make re
```

---

## Using the library

Include the header:

```c
#include "ft_printf.h"
```

Compile your project with the library:

```bash
cc main.c libftprintf.a
```

Example:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "42");
    ft_printf("Character: %c\n", 'A');
    ft_printf("Number: %d\n", 42);
    ft_printf("Unsigned: %u\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", &main);

    return (0);
}
```

---

# Algorithm

The implementation uses a **dispatcher-based parsing algorithm**.

The function `ft_printf()` reads the format string one character at a time.

* If the current character is not `%`, it is printed immediately using `ft_putchar()`.
* When a `%` is found, the next character is interpreted as a format specifier.
* The specifier and the variadic argument list are passed to `ft_check_str()`.
* `ft_check_str()` determines which conversion is requested and calls the appropriate helper function.
* Each helper function prints its corresponding value and returns the number of printed characters.
* `ft_printf()` accumulates these values and returns the total number of printed characters.

The execution flow is illustrated below:

```text
Format String
      │
      ▼
Read next character
      │
      ├───────────────┐
      │               │
      ▼               ▼
Normal char          '%'
      │               │
      ▼               ▼
ft_putchar()    ft_check_str()
                      │
     ┌────────────────┼─────────────────────┐
     ▼                ▼                     ▼
ft_putstr()     ft_putnbr()          ft_puthex()
     │                │                     │
     └────────────────┴─────────────────────┘
                      │
                      ▼
           Return printed characters
```

This modular approach separates parsing from printing, making the implementation easier to understand, test, and maintain.

---

# Helper Functions

The project is divided into specialized helper functions, each responsible for a single task.

| Function               | Responsibility                                                             |
| ---------------------- | -------------------------------------------------------------------------- |
| `ft_putchar()`         | Prints a single character                                                  |
| `ft_putstr()`          | Prints a string                                                            |
| `ft_putnbr()`          | Prints signed integers                                                     |
| `ft_putnbr_unsigned()` | Prints unsigned integers                                                   |
| `ft_puthex()`          | Prints hexadecimal numbers                                                 |
| `ft_putptr()`          | Prints memory addresses                                                    |
| `ft_check_str()`       | Identifies the format specifier and dispatches the correct helper function |

This modular design follows the **Single Responsibility Principle**, reducing complexity and making future maintenance easier.

---

# Data Structure

This project intentionally relies on simple C data structures.

The main elements used are:

* `char *` for the format string.
* `va_list` from `<stdarg.h>` to access a variable number of arguments.
* Primitive integer types (`int`, `unsigned int`, `unsigned long`) for numeric conversions.
* The program's call stack, used by recursive functions during number conversion.

No dynamic memory allocation is required, resulting in a lightweight and memory-efficient implementation.

---

# Technical Choices

Several design decisions were made during development:

* Parsing and printing responsibilities are separated.
* `ft_check_str()` works as a dispatcher between the parser and the helper functions.
* Each conversion specifier has its own dedicated function.
* Numeric values are converted recursively instead of using temporary buffers.
* All output is performed with the `write()` system call.
* Every helper function returns the number of printed characters, allowing `ft_printf()` to accurately reproduce the behavior of the standard `printf()`.

---

# Resources

## Documentation

* The C Programming Language — Brian W. Kernighan & Dennis M. Ritchie
* Linux Manual Pages (`man printf`, `man stdarg`, `man write`)
* The GNU C Library Documentation
* cppreference.com

## Tutorials

* Understanding Variadic Functions in C
* Recursive Number Printing
* Number Base Conversion
* Hexadecimal Representation

---

# AI Usage

Artificial Intelligence (ChatGPT) was used exclusively as a learning and documentation assistant.

AI assisted with:

* Explaining variadic functions (`stdarg.h`);
* Clarifying the behavior of the original `printf()`;
* Explaining recursive algorithms;
* Reviewing code for possible improvements;
* Answering conceptual questions during development;
* Assisting in writing and organizing the project documentation (README).

All implementation, debugging, testing, and final design decisions were completed independently by the project author.

---

# Learning Outcomes

Through this project I strengthened my understanding of:

* Variadic functions
* Recursive algorithms
* String parsing
* Number conversion
* Hexadecimal representation
* Pointer formatting
* Modular software design
* Static libraries
* Low-level output using the `write()` system call

---
