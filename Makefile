LIBFT = libft/libft.a
LIBFT_MAKE = make --no-print-directory -C libft #Para no printear lo que hay dentro del directorio


NAME = pipex

SRC = pipex.c \
	  pipex_utils.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

CC = cc

RM = rm -f

INCLUDE = pipex.h Makefile

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): libft $(OBJ)
		$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)

libft: 
	$(LIBFT_MAKE)

clean:
		$(RM) $(OBJ)
		$(LIBFT_MAKE) clean

fclean: clean
		$(RM) $(NAME)
		$(LIBFT_MAKE) fclean

re: fclean all

.PHONY: all clean fclean re libft
