CC = gcc
CFLAGS = -Wall -Werror -Wextra -Ilibft

CLIENT = client
SERVER = server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

NAME = $(CLIENT) $(SERVER)
LIBFT = Libft/libft.a

all: $(NAME)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT): minitalk/client.c $(LIBFT)
	$(CC) $(CFLAGS) minitalk/client.c $(LIBFT) -o $(CLIENT)

$(SERVER): minitalk/server.c $(LIBFT)
	$(CC) $(CFLAGS) minitalk/server.c $(LIBFT) -o $(SERVER)

$(SERVER_BONUS): bonus/server_bonus.c $(LIBFT)
	$(CC) $(CFLAGS) bonus/server_bonus.c $(LIBFT) -o server

$(CLIENT_BONUS): bonus/client_bonus.c $(LIBFT)
	$(CC) $(CFLAGS) bonus/client_bonus.c $(LIBFT) -o client

$(LIBFT): $(shell find libft/ -name "*.c" -type f)
	$(MAKE) -C Libft 

clean:
	$(MAKE) -C Libft clean

fclean: clean
	$(MAKE) -C Libft fclean
	rm -rf $(NAME) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

norm:
	@norminette */*.[ch] | grep ': OK!' -v || printf '\nHepsi doğru!\n\n'

.PHONY:		all clean fclean re norm