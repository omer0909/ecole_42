/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 02:28:32 by ooz               #+#    #+#             */
/*   Updated: 2022/03/01 22:11:57 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	word_counter(char const *s, char c)
{
	int	r;

	r = 0;
	while (*s != '\0')
	{
		if (*s != c && (s[1] == '\0' || s[1] == c))
			r++;
		s++;
	}
	return (r);
}

int	get_size(char *name, int *x, int *y)
{
	int		fd;
	char	*line;

	*y = 1;
	fd = open(name, 0);
	line = get_next_line(fd);
	*x = word_counter(line, ' ');
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		(*y)++;
	}
	close(fd);
	free(line);
	return (0);
}

void	ft_values(int x, int y, t_data *data)
{
	data->cam_angle.x = 0;
	data->cam_angle.y = 0;
	data->cam_angle.z = 0;
	data->cam_pos.x = RES_X / 2;
	data->cam_pos.y = RES_Y / 2;
	data->cam_pos.z = 0;
	data->persp = 0;
	data->vertex_size = x * y;
	data->vertex = (t_vector3 *)malloc(sizeof(t_vector3) * data->vertex_size);
	data->vertex2d = (t_vector2 *)malloc(sizeof(t_vector2) * data->vertex_size);
	data->colors = (unsigned int *)malloc(sizeof(int) * data->vertex_size);
}

void	read_map(int **map, int x, int y, t_data *data)
{
	int		i;
	int		j;
	int		k;
	float	size;

	ft_values(x, y, data);
	size = 1.0 / x * 500;
	i = 0;
	k = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			data->vertex[k].x = (j - x / 2) * size;
			data->vertex[k].y = (i - y / 2) * size;
			data->vertex[k].z = map[i][j] * (size * 0.1);
			data->colors[k] = map[i][j] * 0XFFFFF + 0XFF;
			j++;
			k++;
		}
		free(map[i++]);
	}
	free(map);
	create_line(x, y, data);
}
