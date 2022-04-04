NAME= fdf
CFLAGS= -Wall -Wextra -Werror -I $(MLX) -I libft
CC= gcc

SRC= main.c read_file.c world_to_screen.c world_to_screen_b.c get_map.c ft_utils.c
OBJ= $(SRC:.c=.o)

ifeq ($(shell uname -s), Linux)
	MLX = minilibx_linux
	MLX_FLAGS = $(MLX)/libmlx_Linux.a -lXext -lX11 -lm -lz
else
	MLX = minilibx_macos
	MLX_FLAGS = -framework OpenGL -framework AppKit $(MLX)/libmlx.a
endif

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C $(MLX)
	gcc -o $(NAME) $(OBJ) libft/libft.a -I $(MLX) -I libft $(CFLAGS) $(MLX_FLAGS)

%.o : %.c FdF.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	make clean -C libft
	make clean -C $(MLX)
	rm -rf $(OBJ)

fclean:
	make fclean -C libft
	make clean -C $(MLX)
	rm -rf $(OBJ) $(NAME) texture

re: clean $(NAME)

texture: texture.c
	make -C libft
	make -C $(MLX)
	$(CC) texture.c -o texture libft/libft.a -I $(MLX) -I libft $(CFLAGS) $(MLX_FLAGS)

norm:
	@norminette *.[ch] libft/*.[ch] | grep ': OK!' -v || printf '\nAll True!\n\n'

.PHONY: all clean fclean re norm
