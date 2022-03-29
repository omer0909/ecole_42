/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 02:25:13 by ooz               #+#    #+#             */
/*   Updated: 2022/03/16 00:05:00 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clear(t_data *data)
{
	size_t	i;

	i = RES_Y * RES_X * (data->img.bbp / 8);
	while (i--)
	{
		data->img.addr[i] = 0;
	}
}

int	close_app(t_data *data)
{
	free(data->vertex);
	free(data->vertex2d);
	free(data->lines);
	free(data->colors);
	if (data->img.img != NULL)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	exit (0);
}

void	ft_events(int key, t_data *data)
{
	if (key == 53)
		close_app(data);
	if (key == 123)
		data->cam_angle.y += 10;
	if (key == 124)
		data->cam_angle.y -= 10;
	if (key == 125)
		data->cam_angle.z += 10;
	if (key == 126)
		data->cam_angle.z -= 10;
	if (key == 0)
		data->cam_pos.x += 10;
	if (key == 2)
		data->cam_pos.x -= 10;
}

int	key_event(int key, t_data *data)
{
	ft_events(key, data);
	if (key == 1)
		data->cam_pos.y += 10;
	if (key == 13)
		data->cam_pos.y -= 10;
	if (key == 6)
		data->cam_pos.z += 10 * (data->cam_pos.z < 250);
	if (key == 7)
		data->cam_pos.z -= 10 * (data->cam_pos.z > -40);
	if (key == 35)
		data->persp = !data->persp;
	ft_clear(data);
	ft_draw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_error("Arguman hatali!\n");
	if (ft_verify(argv[1]))
		ft_error("Dosya hatali!\n");
	read_file(argv[1], &data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, RES_X, RES_Y, "FdF");
	data.img.img = mlx_new_image(data.mlx, RES_X, RES_Y);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bbp \
	, &data.img.line_len, &data.img.endian);
	mlx_key_hook(data.mlx_win, key_event, &data);
	mlx_hook(data.mlx_win, 17, 1L << 2, close_app, &data);
	ft_draw(&data);
	mlx_loop(data.mlx);
	close_app(&data);
	return (0);
}
