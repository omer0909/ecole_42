NAME= mraiiiiiiinnnzzzZ
CC= clang++
CPPFLAGS= -Wall -Wextra -Werror -std=c++98
SRC= Zombie.cpp main.cpp newZombie.cpp randomChump.cpp
OBJ= $(SRC:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $^ $(CPPFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
