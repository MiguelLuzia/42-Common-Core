*This project has been created as part of the 42 curriculum by mitavare.*

# get_next_line

## Description

**get_next_line** is a C function that reads a file descriptor and returns **one line at a time**, each time it is called. A "line" is everything up to and including the next `\n` (or up to the end of the file, if the last line has no trailing newline).

```c
char *get_next_line(int fd);
```

- **Returns** the line that was read (including the `\n`, if there is one), or `NULL` when there is nothing left to read or an error occurs.
- Works with files, standard input, and any other valid file descriptor.
- The size of the read buffer is set at compile time with `-D BUFFER_SIZE=n`, and the function must behave correctly for any positive value (`1`, `42`, `10000000`, ...).
- Allowed external functions: `read`, `malloc`, `free`.

The goal of the project is to learn about **static variables**, **file descriptors**, **buffered reading**, and careful **dynamic memory management** in C, while respecting the 42 Norm.

### Files

| File | Content |
|---|---|
| `get_next_line.c` | `get_next_line` and its static helper functions |
| `get_next_line_utils.c` | `ft_strlen`, `ft_strchr`, `ft_strdup`, `ft_strjoin_free` |
| `get_next_line.h` | Prototypes, includes and the default `BUFFER_SIZE` |

## Instructions

### Compilation

The function is meant to be compiled together with your own `main`. The buffer size is passed at compile time:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

If `-D BUFFER_SIZE` is not given, the header falls back to a default value of `42`.

### Usage example

```c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

The caller owns the returned string and **must `free` it**.

### Testing

Try several buffer sizes and edge cases (empty file, file with only `\n`, last line without `\n`, very long lines), and check for leaks:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c -o gnl
valgrind --leak-check=full ./gnl
```

Repeat with `BUFFER_SIZE=42` and `BUFFER_SIZE=10000000`.

## Algorithm

### Overview

The core problem is that `read()` does not care about lines: it copies up to `BUFFER_SIZE` bytes, which may contain **zero, one, or several** `\n`. A call can therefore read *more* than the line we need, and that extra data must not be lost between calls.

The solution is a **static "stash"**: a `static char *` that keeps everything that has been read from the file but not yet returned. Because it is `static`, it survives between calls to `get_next_line`.

Each call does three steps, each one in its own helper function:

```
        ┌───────────────┐     ┌───────────────┐     ┌───────────────┐
 fd ──▶ │ read_to_stash │ ──▶ │ extract_line  │ ──▶ │  trim_stash   │
        └───────────────┘     └───────────────┘     └───────────────┘
         read & append until   copy stash up to      keep only what comes
         stash has a '\n'      the '\n' (included)   after the '\n'
         or EOF is reached     → returned line       → new stash
```

1. **`read_to_stash`** allocates a temporary buffer of `BUFFER_SIZE + 1` bytes and calls `read()` in a loop. Each chunk is null-terminated and appended to the stash with `ft_strjoin_free` (which frees the old stash, avoiding leaks). The loop stops when the stash contains a `\n`, when `read()` returns `0` (EOF), or when it returns `-1` (error, in which case everything is freed and `NULL` is returned). If the stash already contains a `\n` from a previous call, `read()` is **not called at all**.
2. **`extract_line`** scans the stash up to the first `\n` (or the end of the string), allocates exactly the needed size, and copies the line, including the `\n`. If the stash is empty, it returns `NULL`, which signals EOF to the caller.
3. **`trim_stash`** finds the same `\n` and creates a new stash with only what comes after it, freeing the old one. If nothing remains (last line, or no `\n`), the stash is freed and set to `NULL`.

### Why this design

- **Correctness with any `BUFFER_SIZE`:** the line and the leftover are both derived from the same string (the stash), so one never corrupts the other. With `BUFFER_SIZE=1` the loop simply runs more times; with a huge `BUFFER_SIZE` one `read` may bring many lines, and the leftover is kept for the next calls.
- **No data loss:** everything read beyond the `\n` stays in the static stash instead of being discarded.
- **Correct EOF handling:** a last line with no `\n` is returned normally, and `NULL` is returned only when the stash is empty and `read` returned `0`.
- **Heap-allocated buffer:** the read buffer is allocated with `malloc` instead of being a local array, so large values like `BUFFER_SIZE=10000000` do not overflow the stack.
- **Small, single-purpose functions:** each helper does one thing, which keeps every function within the Norm's 25-line limit and makes the code easy to test and explain.
- **Memory safety:** every allocation has a clear owner. The stash is freed and replaced by `ft_strjoin_free` / `trim_stash`, the temporary buffer is freed before returning, and the returned line is freed by the caller.

### Complexity and limitations

- Each `read` appends to the stash through `ft_strjoin_free`, which copies the whole stash again. For a line of length `L`, that gives roughly `O(L² / BUFFER_SIZE)` copying in the worst case (very small buffers and very long lines). For normal inputs and reasonable buffer sizes this is negligible, and the simplicity was preferred over a more complex scheme.
- Searching for `\n` with `ft_strchr` after each read re-scans the stash from the start, which has the same kind of cost.
- This version uses **a single static stash**, so it is meant to be used with **one file descriptor at a time**. Supporting several file descriptors at once (the bonus part) would require one stash per fd, for example a static array indexed by `fd`.

## Resources

### References

- [`read(2)` – Linux manual page](https://man7.org/linux/man-pages/man2/read.2.html)
- [`malloc(3)` / `free(3)` – Linux manual page](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [Valgrind User Manual](https://valgrind.org/docs/manual/manual.html)

### Use of AI

AI was used as a support tool to clarify project requirements, identify potential errors in the code and improve the wording of this README. The implementation and final verification of the project were carried out by the author.
