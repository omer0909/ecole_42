NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cp libft/libft.a libftprintf.a
	ar -rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) $< -o $@ -c -g

clean:
	rm -rf $(OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

norm:
	@norminette *.[ch] */*.[ch] | grep ': OK!' -v || printf '\nHepsi doğru!\n\n'

.PHONY: all clean fclean re norm
