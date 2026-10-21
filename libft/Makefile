CC = cc
FLAGS = -Wall -Wextra -Werror
FILES = $(wildcard *.c)
OBJECTS = $(FILES:.c=.o)

all: libft.a

libft.a: $(OBJECTS)
	ar rc libft.a $(OBJECTS)
	ranlib libft.a

%o: %c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f libft.a

re: fclean all

.PHONY: all clean fclean re