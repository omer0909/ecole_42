NAME= sedIsForLosers
CC= clang++
CPPFLAGS= -Wall -Wextra -Werror -std=c++98
SRC= main.cpp
OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $^ $(CPPFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
