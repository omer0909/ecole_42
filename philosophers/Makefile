NAME = philo
CC = gcc
CFLAGS = -pthread -Wall -Wextra -Werror #-fsanitize=thread -fPIE -g
SRC = philo.c philo_utils_a.c philo_utils_b.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(OBJ)

re: fclean all

norm:
	@norminette *.[ch] | grep ': OK!' -v || printf '\nAll True!\n\n'

.PHONY: all fclean clean re norm
