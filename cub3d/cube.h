/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:59:05 by ooz               #+#    #+#             */
/*   Updated: 2022/04/24 17:59:06 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <mlx.h>
# include <libft.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "map.h"

# define WIN_WIDTH 1200
# define WIN_HEIGHT 960

# define PI 3.14159f
# define ANLE_TO_RADIAN 0.0174532f

# ifdef LINUX
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# else
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# endif
typedef struct s_image
{
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bbp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_found
{
	float	distance;
	float	rate;
}	t_found;

typedef struct s_player
{
	int		x;
	int		y;
	float	angle;
}	t_player;

typedef struct s_vector2f
{
	float	x;
	float	y;
}	t_vector2f;

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	right;
	int	left;
}	t_keys;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_image		screen;
	int			**map;
	int			y_size;
	int			x_size;
	int			floor_color;
	int			ceil_color;
	t_image		imgs[4];
	t_vector2f	pos;
	float		look;
	int			active_img;
	t_keys		keys;
}	t_data;

//det_file.c
void	ft_swap(char **a, char *b);
char	*get_file(char *name);
void	free_split(char **str);
int		get_file_color(char *color_str);
void	get_file_args(t_map *map, t_data *data);

//your_map.c
void	alloc_map(t_data *data, char **lines);
void	get_map(t_data *data, char **lines);
int		get_data(t_data *data, t_map *map);

//draw.c
void	image_put_pixel(t_image *img, int x, int y, int color);
int		image_get_pixel(t_image *img, int x, int y);
int		float_approximately(float a, float b);
int		color_dark(int color, float dark);
void	draw_wall(t_data *data, float distance, float rate, int index);

//look.c
int		int_abs(int i);
float	float_abs(float i);
float	get_distance(t_vector2f a, t_vector2f b);
t_found	look_horizontal(t_data *data, float f_slope, int add);
t_found	look_vertical(t_data *data, float f_slope, int add);

//render.c
void	look_slope(t_data *data, float slope, t_player *dir, int index);
void	raycast(t_data *data, float angle, int index);
void	fill_screen(t_data *data);
void	ft_render(t_data *data);

//mov.c
int		ft_collision_detect(t_data *data, t_vector2f pos);
void	ft_move(t_data *data, t_vector2f move);
int		ft_event_up(int key, t_data *data);
int		ft_event_down(int key, t_data *data);

#endif
