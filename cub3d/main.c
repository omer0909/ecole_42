/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:58:48 by ooz               #+#    #+#             */
/*   Updated: 2022/04/24 22:00:55 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_start_game(t_data *data, t_map *map)
{
	data->pos.x = map->x + 0.5f;
	data->pos.y = map->y + 0.5f;
	data->look = (map->ang + 180) * ANLE_TO_RADIAN;
	ft_render(data);
}

void ft_calculate_delta_time(t_data *data)
{
	static clock_t	last = 0;
	static int		first = 0;
	clock_t			now;

	now = clock();
	if (!first)
	{
		first = 1;
		last = clock();
	}
	data->delta_time = ((double) (now - last)) / CLOCKS_PER_SEC;
	last = clock();
}

int	ft_update(t_data *data)
{
	float		speed;
	float		look_speed;
	t_vector2f	move;

	speed = 5.0f;
	look_speed = 1.5f;
	ft_calculate_delta_time(data);
	move = (t_vector2f){0, 0};
	move.x += cosf(data->look) * speed
		* (data->keys.w - data->keys.s) * data->delta_time;
	move.y += sinf(data->look) * speed
		* (data->keys.w - data->keys.s) * data->delta_time;
	move.x += cosf(data->look + 1.570796f) * speed
		* (data->keys.a - data->keys.d) * data->delta_time;
	move.y += sinf(data->look + 1.570796f) * speed
		* (data->keys.a - data->keys.d) * data->delta_time;
	if (data->keys.left)
		data->look += look_speed * data->delta_time;
	if (data->keys.right)
		data->look -= look_speed * data->delta_time;
	ft_move(data, move);
	ft_render(data);
	return (0);
}

int	func_exit(void *tmp)
{
	(void)tmp;
	exit (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	*map;

	if (argc != 2)
		return (-1);
	map = create_map(argv[1]);
	if (map == NULL)
		return (-1);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx,
			WIN_WIDTH, WIN_HEIGHT, "wolfestain 3d");
	data.screen.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.screen.width = WIN_WIDTH;
	data.screen.height = WIN_HEIGHT;
	data.screen.addr = mlx_get_data_addr(data.screen.img,
			&data.screen.bbp, &data.screen.line_len, &data.screen.endian);
	get_data(&data, map);
	ft_start_game(&data, map);
	kill_map(map);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &ft_event_up, &data);
	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, &ft_event_down, &data);
	mlx_loop_hook(data.mlx, ft_update, &data);
	mlx_hook(data.mlx_win, 17, 0, func_exit, 0);
	mlx_loop(data.mlx);
}
