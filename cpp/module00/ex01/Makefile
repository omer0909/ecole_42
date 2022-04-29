NAME= phonebook
CC= g++
CPPFLAGS= -Wall -Wextra -Werror -std=c++98
SRC= main.cpp Contact.cpp PhoneBook.cpp
OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(CPPFLAGS) $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
