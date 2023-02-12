CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT	= libft/libft.a
# Mandatory
NAME = push_swap
SRC = mandatory/push_swap.c mandatory/args_utils.c \
	mandatory/global_utils.c mandatory/stack_utils.c \
	mandatory/min_sorting.c mandatory/finders.c \
	mandatory/stack_operations.c mandatory/sorting_utils.c \
	mandatory/max_sorting.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBFT)

$(LIBFT):
		make -C libft
		make bonus -C libft

clean:
	rm -f $(OBJ)
	make clean -C libft 

fclean: clean
	rm -f libft/libft.a $(NAME)
	make fclean -C libft 

re: fclean all

.PHONY: all bonus clean fclean re libft
