/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:59:14 by ooz               #+#    #+#             */
/*   Updated: 2022/04/24 21:41:20 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	image_put_pixel(t_image *img, int x, int y, int color)
{
	if (x < 0 || x > img->width || y < 0 || y > img->height)
		return ;
	*((int *)(img->addr + (y * img->line_len) \
	+ (x * 4))) = color;
}

int	image_get_pixel(t_image *img, int x, int y)
{
	if (x < 0 || x > img->width || y < 0 || y > img->height)
		return (0);
	return (*((int *)(img->addr + (y * img->line_len) \
	+ (x * 4))));
}

int	float_approximately(float a, float b)
{
	return (a - b < 0.0001f && a - b > -0.0001f);
}

int	color_dark(int color, float dark)
{
	int	r;
	int	g;
	int	b;

	r = color & 0x000000FF;
	r *= dark;
	g = (color & 0x0000FF00) >> 8;
	g *= dark;
	b = (color & 0x00FF0000) >> 16;
	b *= dark;
	return (r | (g << 8) | (b << 16));
}

void	draw_wall(t_data *data, float distance, float rate, int index)
{
	int		draw;
	float	rate_i;
	int		start;
	int		end;
	float	dark;

	dark = 2.0f / distance;
	if (dark >= 1)
		dark = 1;
	draw = (5 / distance) * (WIN_HEIGHT * 0.3f);
	rate_i = (float)data->imgs[data->active_img].height / draw;
	start = (WIN_HEIGHT - draw) / 2;
	end = 0;
	if (start < 0)
	{
		draw += start;
		end = -start;
	}
	while (draw-- > end)
		image_put_pixel(&data->screen, index, draw + start,
			color_dark(image_get_pixel(&data->imgs[data->active_img],
					data->imgs[data->active_img].width * rate,
					draw * rate_i), dark));
}
