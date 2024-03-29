/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:58:56 by ooz               #+#    #+#             */
/*   Updated: 2022/04/24 18:31:46 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_collision_detect(t_data *data, t_vector2f pos)
{
	float	size;

	size = 0.2f;
	return (data->map[(int)(pos.y + size)][(int)(pos.x + size)] != '1'
		&& data->map[(int)(pos.y - size)][(int)(pos.x + size)] != '1'
		&& data->map[(int)(pos.y - size)][(int)(pos.x - size)] != '1'
		&& data->map[(int)(pos.y + size)][(int)(pos.x - size)] != '1');
}

void	ft_move(t_data *data, t_vector2f move)
{
	if (ft_collision_detect(data,
			(t_vector2f){data->pos.x + move.x, data->pos.y}))
		data->pos.x += move.x;
	if (ft_collision_detect(data,
			(t_vector2f){data->pos.x, data->pos.y + move.y}))
		data->pos.y += move.y;
}

int	ft_event_up(int key, t_data *data)
{
	if (key == KEY_W)
		data->keys.w = 1;
	else if (key == KEY_S)
		data->keys.s = 1;
	else if (key == KEY_A)
		data->keys.a = 1;
	else if (key == KEY_D)
		data->keys.d = 1;
	else if (key == KEY_LEFT)
		data->keys.left = 1;
	else if (key == KEY_RIGHT)
		data->keys.right = 1;
	else if (key == KEY_ESC)
		exit(0);
	return (0);
}

int	ft_event_down(int key, t_data *data)
{
	if (key == KEY_W)
		data->keys.w = 0;
	else if (key == KEY_S)
		data->keys.s = 0;
	else if (key == KEY_A)
		data->keys.a = 0;
	else if (key == KEY_D)
		data->keys.d = 0;
	else if (key == KEY_LEFT)
		data->keys.left = 0;
	else if (key == KEY_RIGHT)
		data->keys.right = 0;
	return (0);
}
