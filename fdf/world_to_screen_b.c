/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_to_screen_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:09:54 by ooz               #+#    #+#             */
/*   Updated: 2022/03/01 22:11:37 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line(t_data *data, int i, t_vector2 a_pos, t_vector2 b_pos)
{
	float		add_col;
	float		col_i;
	int			limit;
	float		count;
	t_vector2	add;

	add = (t_vector2){a_pos.x - b_pos.x, a_pos.y - b_pos.y};
	count = ft_max(ft_abs(add.x), ft_abs(add.y));
	add_col = 1.0f / count;
	add.x *= add_col;
	add.y *= add_col;
	col_i = 0;
	limit = 1000;
	while (((int)(a_pos.x - b_pos.x) || (int)(a_pos.y - b_pos.y)) && limit--)
	{
		if (a_pos.x >= 0 && a_pos.x < RES_X && a_pos.y >= 0 && a_pos.y < RES_Y)
			image_pixel_put(data, a_pos.x, a_pos.y \
			, col_lerp(data->colors[data->lines[i].a] \
			, data->colors[data->lines[i].b], col_i));
		a_pos.x -= add.x;
		a_pos.y -= add.y;
		col_i += add_col;
	}
}

void	draw_lines(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->line_size)
	{
		ft_line(data, i, data->vertex2d[data->lines[i].a] \
		, data->vertex2d[data->lines[i].b]);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}

void	world_to_screen_in(t_data *data, int i, t_vector3 pos3)
{
	if (data->persp)
	{
		data->vertex2d[i].x = (pos3.x - RES_X / 2) / ((pos3.z - 500) / 500) \
		+ RES_X / 2;
		data->vertex2d[i].y = (pos3.y - RES_Y / 2) / ((pos3.z - 500) / 500) \
		+ RES_Y / 2;
	}
	else
	{
		data->vertex2d[i].x = ((pos3.x - RES_X / 2) \
		* (1 + data->cam_pos.z * 0.01f) + RES_X / 2);
		data->vertex2d[i].y = ((pos3.y - RES_Y / 2) \
		* (1 + data->cam_pos.z * 0.01f) + RES_Y / 2);
	}
}

void	world_to_screen(t_data *data)
{
	int			i;
	t_vector3	pos3;

	i = 0;
	while (i < data->vertex_size)
	{
		pos3 = (t_vector3){data->vertex[i].x, data->vertex[i].y - 5 \
		, data->vertex[i].z - 5};
		pos3 = rotate(pos3, data->cam_angle);
		pos3 = (t_vector3){pos3.x + data->cam_pos.x, pos3.y + data->cam_pos.y \
		, pos3.z + data->cam_pos.z};
		world_to_screen_in(data, i, pos3);
		i++;
	}
}

void	ft_draw(t_data *data)
{
	world_to_screen(data);
	draw_lines(data);
}
