CC= clang++
CPPFLAGS= -Wall -Wextra -Werror -std=c++98
SRCS= megaphone.cpp
NAME= megaphone
OBJS= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ $(CPPFLAGS) -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
