/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:59:37 by ooz               #+#    #+#             */
/*   Updated: 2022/04/24 22:02:47 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	look_slope(t_data *data, float slope, t_player *dir, int index)
{
	t_found	vertical;
	t_found	horizontal;

	horizontal = look_horizontal(data, slope, dir->x);
	vertical = look_vertical(data, 1 / slope, dir->y);
	if (horizontal.distance > vertical.distance)
	{
		data->active_img = dir->y > 0;
		if (dir->y < 0)
			vertical.rate = 1 - vertical.rate;
		draw_wall(data, vertical.distance * cos(dir->angle),
			vertical.rate, index);
	}
	else
	{
		data->active_img = 2 + (dir->x > 0);
		if (dir->x > 0)
			horizontal.rate = 1 - horizontal.rate;
		draw_wall(data, horizontal.distance * cos(dir->angle),
			horizontal.rate, index);
	}
}

void	raycast(t_data *data, float angle, int index)
{
	float		cos_angle;
	float		sin_angle;
	t_player	dir;

	cos_angle = cosf(angle + data->look);
	sin_angle = sinf(angle + data->look);
	dir.x = (cos_angle > 0) * 2 - 1;
	dir.y = (sin_angle > 0) * 2 - 1;
	dir.angle = angle;
	look_slope(data, sin_angle / cos_angle, &dir, index);
}

void	fill_screen(t_data *data)
{
	int		x;
	int		y;
	int		half;

	half = data->screen.height / 2;
	y = 0;
	while (y < half)
	{
		x = 0;
		while (x < data->screen.width)
			image_put_pixel(&data->screen, x++, y, data->ceil_color);
		y++;
	}
	while (y < data->screen.height)
	{
		x = 0;
		while (x < data->screen.width)
			image_put_pixel(&data->screen, x++, y, data->floor_color);
		y++;
	}
}

void	ft_render(t_data *data)
{
	const float	view_angle = 1.5f / 2;
	const float	add = view_angle / WIN_WIDTH;
	float		angle;
	int			index;

	fill_screen(data);
	index = WIN_WIDTH;
	angle = -(view_angle / 2);
	while (index--)
	{
		raycast(data, angle, index);
		angle += add;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->screen.img, 0, 0);
}
