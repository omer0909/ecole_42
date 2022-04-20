NAME= minishell
CC= gcc
CFLAGS= -Wall -Wextra -Werror -I/goinfre/ooz/homebrew/opt/readline/include
SRC= main.c exec.c ft_split_quote.c builtin.c environment.c error.c files.c in_quote.c main.c setup_process.c signal.c string_edit.c change_dir.c free.c
OBJ= $(SRC:.c=.o)
LIB = libft/libft.a


all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -L/goinfre/ooz/homebrew/opt/readline/lib -lreadline $^ $(LIB) -o $@ $(CFLAGS) -g 

$(LIB):
	make -C libft/
fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

clean:
	make clean -C libft
	rm -rf $(OBJ)

re: fclean $(NAME)
	make re -C libft

norm:
	@norminette *.[ch] */*.[ch] | grep ': OK!' -v || printf '\nAll True!\n\n'

.PHONY: fclean clean re libft norm
