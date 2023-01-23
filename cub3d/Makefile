NAME= cub3D
CC= clang
CFLAGS= -Wall -Wextra -Werror $(addprefix -I , $(IDIR)) -Ofast
SRC= main.c get_file.c your_map.c draw.c look.c mov.c render.c map.c map_u.c tool.c
LIBFT= libft/libft.a
IDIR= libft ./ $(MLX)
OBJ= $(SRC:.c=.o)

ifeq ($(shell uname -s), Linux)
	MLX = minilibx_linux
	MLX_LIB = $(MLX)/libmlx_Linux.a
	MLX_FLAGS = -lXext -lX11 -lm -lz -DLINUX
else
	MLX = minilibx_macos
	MLX_LIB = $(MLX)/libmlx.a
	MLX_FLAGS = -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) 

$(LIBFT):
	make -C libft

$(MLX_LIB):
	make -C $(MLX)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

clean:
	make clean -C libft
	make clean -C $(MLX)
	rm -rf $(OBJ)

re: fclean all

norm:
	@norminette *.[ch] libft/*.[ch] | grep ': OK!' -v || printf '\nAll True!\n\n'

.PHONY: all fclean clean re norm
