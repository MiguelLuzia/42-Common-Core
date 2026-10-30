*This project has been created as part of the 42 curriculum by mitavare.*

# Libft

## Description
Libft is the first project in the 42 Common Core.\
It involves recoding a few functions from the C standard library, as well as some other utility functions that will be used throughout the whole curriculum.\
The project produces a static library, `libft.a`, which can be reused in other C programs.


### Library Contents

#### Character checks and conversions

- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii` and `ft_isprint`
  classify characters.
- `ft_toupper` and `ft_tolower` convert letters to uppercase and lowercase, respectively.

#### Memory functions

- `ft_memset` fills a memory area with a specific byte; `ft_bzero` sets it to zero.
- `ft_memcpy` copies memory without handling overlapping areas;
  `ft_memmove` supports overlapping areas.
- `ft_memchr` searches a memory area; `ft_memcmp` compares two memory areas.
- `ft_calloc` allocates zero-initialized memory.

#### String functions

- `ft_strlen` measures a string.
- `ft_strlcpy` and `ft_strlcat`, respectively, copy and concatenate strings with size limits.
- `ft_strchr` and `ft_strrchr` search for a character; `ft_strnstr` searches for a substring within a specified length.
- `ft_strncmp` compares strings up to a specified number of characters.
- `ft_strdup` creates a duplicate of a string.
- `ft_substr`, `ft_strjoin`, `ft_strtrim` and `ft_split` create or divide strings.
- `ft_strmapi` creates a new string by applying a function to each character;
  `ft_striteri` applies a function to each character in place.
- `ft_atoi` converts a string to an integer; `ft_itoa` converts an integer to a string.

#### File descriptor output

`ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd` and `ft_putnbr_fd` write a character, string, string followed by a newline, and integer, respectively, to a specified file descriptor.

#### Singly linked lists

- `ft_lstnew` creates a new node containing the given content.
- `ft_lstadd_front` and `ft_lstadd_back` add a node to the beginning or end of a list, respectively.
- `ft_lstsize` counts the nodes in a list; `ft_lstlast` returns its last node.
- `ft_lstdelone` deletes one node and its content; `ft_lstclear` deletes all nodes and sets the list pointer to `NULL`.
- `ft_lstiter` applies a function to the content of each node.
- `ft_lstmap` applies a function to each node’s content and creates a new list from the results. It uses the provided del function to free content if node allocation fails.




## Instructions
Clone the repository and enter the project directory:
```sh
git clone <repository-url>
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
