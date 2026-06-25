*This project has been created as part of the 42 curriculum by alesferr.*

## Description
The **ft_printf** project is a fundamental milestone in the 42 school curriculum. The main objective is to recode the standard C library function `printf()`, providing an excellent opportunity to discover and master variadic functions in C.

A successful implementation relies on a well-structured and extensible architecture. Unlike the original libc function, this version does not implement buffer management. It focuses on parsing the format string and mimicking the exact output behavior of the standard `printf()` for a specific set of conversion specifiers.

### Supported Conversions
The function handles the following standard format specifiers:
* `%c` - Prints a single character.
* `%s` - Prints a string (following the common C convention).
* `%p` - Prints a void pointer argument in hexadecimal format.git@github.com:alef-moura/ft_printf.git
* `%d` - Prints a decimal (base 10) number.
* `%i` - Prints an integer in base 10.
* `%u` - Prints an unsigned decimal (base 10) number.
* `%x` - Prints a number in hexadecimal (base 16) lowercase format.
* `%X` - Prints a number in hexadecimal (base 16) uppercase format.
* `%%` - Prints a percent sign[: 1].

---

## Instructions

### Compilation
The project compiles into a library archive named `libftprintf.a`, which is created at the root of the repository. Compilation is handled via a `Makefile` using `cc` with the strict flags `-Wall -Wextra -Werror`. The library must be generated using the `ar` command, as `libtool` is explicitly forbidden.

To compile the library, run the following command in your terminal:
```bash
make