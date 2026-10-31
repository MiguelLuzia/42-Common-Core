*This project has been created as part of the 42 curriculum by mitavare.*

# Libft

## Description
Libft is the first project in the 42 Common Core.\
It involves recoding a few functions from the C standard library, as well as some other utility functions that will be used throughout the whole curriculum.\
The project produces a static library, `libft.a`, which can be reused in other C programs.


### Library Contents

#### Character checks and conversions

- `ft_isalpha` checks whether a character is a letter (`A-Z` or `a-z`).
- `ft_isdigit` checks whether a character is a decimal digit (`0-9`).
- `ft_isalnum` checks whether a character is a letter or a digit.
- `ft_isascii` checks whether a character is in the ASCII range (`0-127`).
- `ft_isprint` checks whether a character is printable (`32-126`).
- `ft_toupper` converts a lowercase letter to uppercase; other characters are returned unchanged.
- `ft_tolower` converts an uppercase letter to lowercase; other characters are returned unchanged.

#### Memory functions

- `ft_memset` fills the first `n` bytes of a memory area with a given byte and returns the area.
- `ft_bzero` sets the first `n` bytes of a memory area to zero.
- `ft_memcpy` copies `n` bytes from a source to a destination area. The areas must not overlap.
- `ft_memmove` copies `n` bytes from a source to a destination area and handles overlapping areas correctly.
- `ft_memchr` searches the first `n` bytes of a memory area for a given byte and returns a pointer to its first occurrence, or `NULL` if not found.
- `ft_memcmp` compares the first `n` bytes of two memory areas and returns the difference between the first pair of bytes that differ, or `0` if they are equal.
- `ft_calloc` allocates memory for `nmemb` elements of `size` bytes each, initializes it to zero, and returns `NULL` if the allocation fails.

#### String functions

- `ft_strlen` returns the number of characters in a string, excluding the terminating `'\0'`.
- `ft_strlcpy` copies a string into a buffer of `size` bytes, always null-terminating the result (if `size` is not zero), and returns the length of the source string.
- `ft_strlcat` appends a string to the end of another within a buffer of `size` bytes, always null-terminating the result, and returns the total length it tried to create.
- `ft_strchr` returns a pointer to the first occurrence of a character in a string, or `NULL` if not found.
- `ft_strrchr` returns a pointer to the last occurrence of a character in a string, or `NULL` if not found.
- `ft_strnstr` locates the first occurrence of a substring within a string, searching at most `len` characters, and returns `NULL` if not found.
- `ft_strncmp` compares at most `n` characters of two strings and returns the difference between the first pair that differ, or `0` if they are equal.
- `ft_strdup` returns a newly allocated copy of a string.
- `ft_substr` returns a newly allocated substring of a string, starting at index `start` and with a maximum length of `len`.
- `ft_strjoin` returns a newly allocated string resulting from the concatenation of two strings.
- `ft_strtrim` returns a newly allocated copy of a string with all characters belonging to a given set removed from its beginning and end.
- `ft_split` splits a string using a given delimiter character and returns a newly allocated `NULL`-terminated array of strings.
- `ft_strmapi` returns a newly allocated string created by applying a function to each character (and its index) of a string.
- `ft_striteri` applies a function to each character (and its index) of a string, modifying it in place.
- `ft_atoi` converts the initial portion of a string to an `int`, skipping leading whitespace and handling an optional sign.
- `ft_itoa` returns a newly allocated string representing an integer.

#### File descriptor output

- `ft_putchar_fd` writes a character to a given file descriptor.
- `ft_putstr_fd` writes a string to a given file descriptor.
- `ft_putendl_fd` writes a string followed by a newline to a given file descriptor.
- `ft_putnbr_fd` writes an integer to a given file descriptor.

#### Singly linked lists

- `ft_lstnew` creates a new node containing the given content, with `next` set to `NULL`.
- `ft_lstadd_front` adds a node to the beginning of a list.
- `ft_lstadd_back` adds a node to the end of a list.
- `ft_lstsize` counts the nodes in a list.
- `ft_lstlast` returns the last node of a list.
- `ft_lstdelone` frees a single node's content using the provided `del` function, then frees the node itself.
- `ft_lstclear` deletes and frees a node and all the nodes after it, using `del` on their content, and sets the list pointer to `NULL`.
- `ft_lstiter` applies a function to the content of each node in a list.
- `ft_lstmap` creates a new list by applying a function to the content of each node. It uses the provided `del` function to free content and already-created nodes if an allocation fails.




## Instructions
Clone the repository and enter the project directory:
```sh
git clone <repository-url> libft
cd libft
```
Build the library with:
```sh
make
```
This creates the static library `libft.a`. To use it in a C program, include
`libft.h` and link the library when compiling:
```sh
cc -Wall -Wextra -Werror -I. main.c ./libft.a -o program
```
Run the compiled program with:
```sh
./program
```
Use `make clean` to remove object files, `make fclean` to remove object files and the library, and `make re` to rebuild the library.

## Resources
- The official Libft project subject and instructions.
- The `man` pages for standard C functions.
- C language documentation and references for standard library functions.

### AI Usage
AI was used as a support tool to clarify project requirements, identify potential errors in the code and improve the wording of this README. The implementation and final verification of the project were carried out by the author.
