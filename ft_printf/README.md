*This project has been created as part of the 42 curriculum by mitavare.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C standard library function `printf`. The goal of the project is to learn how variadic functions work in C (`<stdarg.h>`) and to build a small, well-structured formatting tool that can later be reused in other 42 projects.

The function has the following prototype:

```c
int ft_printf(const char *format, ...);
```

It writes the formatted output to the standard output and returns the number of characters printed, exactly like the original `printf`.

The project is built as a static library, `libftprintf.a`, which also contains the functions of my own [Libft](./libft) so that only one library is needed at link time.

### Supported conversions

| Conversion | Description                                             |
|:----------:|---------------------------------------------------------|
| `%c`       | A single character                                      |
| `%s`       | A string (prints `(null)` if the pointer is `NULL`)     |
| `%p`       | A pointer in hexadecimal, with `0x` prefix (`(nil)` for `NULL`) |
| `%d`       | A signed decimal integer                                |
| `%i`       | A signed decimal integer (same as `%d`)                 |
| `%u`       | An unsigned decimal integer                             |
| `%x`       | An unsigned integer in lowercase hexadecimal            |
| `%X`       | An unsigned integer in uppercase hexadecimal            |
| `%%`       | A literal percent sign                                  |

### Behavior notes

- The return value is the total number of characters written.
- A `%` at the very end of the format string is ignored.
- An unknown conversion (for example `%z`) prints the character itself and consumes no argument. This is undefined behavior in the real `printf`, so it is not tested by the subject.
- `%p` with a `NULL` pointer prints `(nil)`, matching glibc on Linux.
- Errors from `write` are not handled, so the function never returns `-1`.
- The bonus part (flags, width and precision) is not implemented.

### Project structure

| Function        | Role                                                                 |
|-----------------|----------------------------------------------------------------------|
| `ft_printf`     | Loops over the format string, prints plain characters and delegates conversions |
| `ft_dispatch`   | Reads the next argument with the correct type and calls the right helper |
| `fill_c`        | Prints a character (also used for plain text and `%%`)               |
| `fill_d`        | Prints a signed integer                                              |
| `fill_u`        | Prints an unsigned integer                                           |
| `fill_s`        | Prints a string                                                      |
| `fill_hex`      | Prints an unsigned number in base 16 (lowercase or uppercase)        |
| `fill_p`        | Prints a pointer address                                             |

Every `fill_*` function returns the number of characters it printed, and `ft_dispatch` forwards that value to `ft_printf`.

## Instructions

### Requirements

- A C compiler (`cc`) and `make`
- The `libft` folder at the root of the repository (it contains `libft.h` and its own Makefile)

### Compilation

```sh
make        # builds libft and then libftprintf.a
make clean  # removes the object files (also in libft)
make fclean # removes the object files and the libraries
make re     # fclean followed by all
```

The project is compiled with `-Wall -Wextra -Werror`.

### Usage

Include the header in your code and link against `libftprintf.a`:

```c
#include "ft_printf.h"

int	main(void)
{
	int	len;

	len = ft_printf("Hello %s! %d + %d = %d | %x | %p\n",
			"world", 2, 3, 5, 255, &len);
	ft_printf("printed %d characters\n", len);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```

### Testing

Each conversion can be tested by calling the real `printf` and `ft_printf` with the same arguments and comparing both the output and the returned value. Edge cases worth testing include `0`, `INT_MIN`, `INT_MAX`, `UINT_MAX`, `-1` with `%x`, `NULL` with `%s` and `%p`, `%c` with `0`, and `%%`.

## Algorithm and data structures

### Single pass over the format string

`ft_printf` walks through the format string once, from left to right (time complexity O(n) in the length of the output). Plain characters are written directly. When a `%` is found and there is a character after it, that character is handed to `ft_dispatch`, and the loop skips over it. A `%` at the end of the string is ignored, which avoids reading past the terminating `'\0'`.

### Dispatching with `ft_dispatch`

The conversion character selects the helper function and the type that `va_arg` must read. Keeping this in a separate function has two benefits: `ft_printf` stays short and readable (and within the 25 lines imposed by the Norm), and adding a new conversion only requires one new line in the dispatcher.

The types passed to `va_arg` are chosen according to C's default argument promotions:

- `%c` reads an `int`, because a `char` passed through `...` is promoted to `int`. Reading it as `char` would be undefined behavior.
- `%d` and `%i` read an `int`.
- `%u`, `%x` and `%X` read an `unsigned int`.
- `%s` reads a `char *`.
- `%p` reads a `void *`, which is then cast to `unsigned long`, large enough to hold an address on a 64-bit system.

The `va_list` is passed to `ft_dispatch` **by pointer** (`va_list *`). According to the C standard, a `va_list` passed by value to another function and used with `va_arg` there is indeterminate in the caller afterwards. Passing a pointer guarantees that every `va_arg` advances the caller's list, so the next conversion reads the next argument.

### Converting numbers with recursion

Numbers are printed with a recursive function that divides by the base:

```c
if (n >= base)
	count += fill(n / base);
print the digit n % base
```

The recursion first reaches the most significant digit and prints digits on the way back, so they come out in the correct order. This removes the need for a temporary buffer, for `malloc`, or for reversing a string. The depth is small and bounded: at most 10 calls for a 32-bit decimal number and 16 for a 64-bit hexadecimal one.

- `fill_hex` uses a base string (`"0123456789abcdef"` or `"0123456789ABCDEF"`) as a lookup table, so the same function handles `%x`, `%X` and `%p`.
- `fill_u` works directly on `unsigned int`, so values above `INT_MAX` are printed correctly instead of becoming negative.
- `fill_d` prints the `-` sign, negates the value and then prints the digits. `INT_MIN` is handled as a special case, because `-INT_MIN` does not fit in an `int` and would overflow.

### Counting characters

The standard `printf` returns the number of characters printed, so every helper returns how many characters it wrote, and the callers add them up. This avoids global variables and keeps each function independent. The constant counts for `(null)` (6) and `(nil)` (5) are returned directly.

### Data structures

No custom data structure is needed. The only structures involved are the format string, which is read sequentially, and the `va_list`, which provides sequential access to the variadic arguments. Because the implementation never allocates memory, there are no memory leaks and no cleanup to worry about.

### Libft in the final library

The Makefile first builds `libft.a`, copies it to `libftprintf.a`, and then adds the `ft_printf` object files with `ar rcs`. As a result, `libftprintf.a` contains both libraries and the user only has to link one file.

## Resources

### References

- [`printf(3)` manual page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [`stdarg(3)` manual page](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [GNU C Library manual: Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- [cppreference: Variadic arguments](https://en.cppreference.com/w/c/variadic)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- ISO/IEC 9899 (the C standard): sections on variable arguments (`<stdarg.h>`) and on the `fprintf` conversion specifiers

### AI Usage

AI was used as a support tool to clarify project requirements, identify potential errors in the code and improve the wording of this README. The implementation and final verification of the project were carried out by the author.
