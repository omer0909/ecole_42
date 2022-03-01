NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c push_swap_commands.c push_swap_commands_other.c random_search.c push_swap_others.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(OBJ) libft/libft.a $(CFLAGS) -o $(NAME)

clean:
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

norm:
	@norminette *.[ch] | grep ': OK!' -v || printf '\nAll true!\n\n'

re: fclean all

.PHONY: all clean fclean re norm
