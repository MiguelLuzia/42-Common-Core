NAME = libftprintf.a

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
INCLUDES = -I. -I$(LIBFTDIR)

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	dispatch.c \
	fill_cdus.c \
	fill_hexp.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(LIBFT):
	$(MAKE) all -C $(LIBFTDIR)

%.o: %.c ft_printf.h $(LIBFTDIR)/libft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
