/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 02:35:23 by ooz               #+#    #+#             */
/*   Updated: 2022/03/01 23:23:53 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <libft.h>

# define RES_X 2400
# define RES_Y 1300
# define ANGLE_TO_RADIAN 0.017453292519943295

typedef struct s_vector2
{
	float	x;
	float	y;
}	t_vector2;

typedef struct s_line
{
	int	a;
	int	b;
}	t_line;

typedef struct s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

typedef struct s_Quaternion
{
	float	w;
	float	x;
	float	y;
	float	z;
}	t_Quaternion;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bbp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	t_img			img;
	t_vector3		cam_angle;
	t_vector3		cam_pos;
	t_vector3		*vertex;
	t_vector2		*vertex2d;
	int				vertex_size;
	unsigned int	*colors;
	t_line			*lines;
	int				line_size;
	int				persp;
}	t_data;

typedef struct s_img_read
{
	void	*mlx;
	void	*img;
	int		height;
	int		width;
	char	*addr;
	int		bbp;
	int		line_len;
	int		endian;
	float	value;
}	t_img_read;

int				read_file(char *name, t_data *data);
void			ft_draw(t_data *data);
int				get_size(char *name, int *x, int *y);
void			read_map(int **map, int x, int y, t_data *data);
void			create_line(int x, int y, t_data *data);
t_vector3		rotate(t_vector3 pos, t_vector3 angle);
unsigned int	col_lerp(unsigned int a, unsigned int b, float i);
float			ft_abs(float a);
float			ft_max(float a, float b);
void			image_pixel_put(t_data *data, int x, int y, int color);
int				close_app(t_data *data);
void			ft_error(char *str);
int				ft_verify(char *file);

#endif
