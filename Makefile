CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT	= libft/libft.a
# Mandatory
NAME = push_swap
BONUS = checker
SRC = mandatory/push_swap.c mandatory/args_utils.c \
	mandatory/global_utils.c shared/stack_utils.c \
	mandatory/min_sorting.c mandatory/finders.c \
	shared/stack_operations.c mandatory/sorting_utils.c \
	mandatory/max_sorting.c \

SRC_B = bonus/push_swap_bonus.c bonus/args_utils_bonus.c bonus/utils_bonus.c \
	shared/stack_utils.c shared/stack_operations.c bonus/extra_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBFT)

$(BONUS): $(LIBFT) $(OBJ_B)
	$(CC) $(CFLAGS) $(OBJ_B) -o $@ $(LIBFT)

$(LIBFT):
		make -C libft
		make bonus -C libft

clean:
	rm -f $(OBJ) $(OBJ_B)
	make clean -C libft 

fclean: clean
	rm -f libft/libft.a $(NAME) $(BONUS) 
	make fclean -C libft 

re: fclean all

.PHONY: all bonus clean fclean re libft
