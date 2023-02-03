CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT	= libft/libft.a
# Mandatory
NAME = push_swap
SRC = mandatory/push_swap.c mandatory/args_utils.c mandatory/global_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBFT)

$(LIBFT):
		make -C libft

clean:
	rm -f $(OBJ)
	make clean -C libft 

fclean: clean
	rm -f libft/libft.a $(NAME)
	make fclean -C libft 

re: fclean all

.PHONY: all bonus clean fclean re libft
