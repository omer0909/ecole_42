/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 23:23:23 by ooz               #+#    #+#             */
/*   Updated: 2022/03/01 23:49:28 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_pixel(t_img_read *d, int x, int y)
{
	int		result;

	result = (unsigned char)d->addr[(x * d->width + y) * 4] \
	+ (unsigned char)d->addr[(x * d->width + y) * 4 + 1] \
	+ (unsigned char)d->addr[(x * d->width + y) * 4 + 2];
	result /= (3 * 25 * d->value);
	return (result);
}

int	main(int argc, char **argv)
{
	t_img_read	d;
	int			x;
	int			y;

	if (argc != 3)
		return (0);
	d.value = 100.0f / ft_atoi(argv[2]);
	d.mlx = mlx_init();
	d.img = mlx_xpm_file_to_image(d.mlx, argv[1], &d.width, &d.height);
	d.addr = mlx_get_data_addr(d.img, &d.bbp, &d.line_len, &d.endian);
	y = 0;
	while (y < d.height)
	{
		x = 0;
		while (x < d.width)
		{
			ft_printf(" %i", get_pixel(&d, y, x));
			++x;
		}
		ft_printf("\n");
		++y;
	}
	mlx_destroy_image(d.mlx, d.img);
	return (0);
}
