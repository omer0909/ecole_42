/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 02:24:56 by ooz               #+#    #+#             */
/*   Updated: 2022/03/01 22:11:48 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_create_line_in(t_line *r, int *k, int xyij[4])
{
	if (xyij[2] + 1 != xyij[1] && xyij[3] + 1 != xyij[0])
	{
		r[*k].a = xyij[2] * xyij[0] + xyij[3];
		r[*k].b = xyij[2] * xyij[0] + xyij[3] + 1;
		r[*k + 1].a = xyij[2] * xyij[0] + xyij[3];
		r[*k + 1].b = (xyij[2] + 1) * xyij[0] + xyij[3];
		r[*k + 2].a = xyij[2] * xyij[0] + xyij[3];
		r[*k + 2].b = (xyij[2] + 1) * xyij[0] + xyij[3] + 1;
		(*k) += 3;
	}
	else if (xyij[2] + 1 != xyij[1])
	{
		r[*k].a = xyij[2] * xyij[0] + xyij[3];
		r[*k].b = (xyij[2] + 1) * xyij[0] + xyij[3];
		(*k)++;
	}
	else if (xyij[3] + 1 != xyij[0])
	{
		r[*k].a = xyij[2] * xyij[0] + xyij[3];
		r[*k].b = xyij[2] * xyij[0] + xyij[3] + 1;
		(*k)++;
	}
}

void	create_line(int x, int y, t_data *data)
{
	t_line	*r;
	int		i;
	int		j;
	int		k;

	data->line_size = (x * y * 3) - (x * 2 + y * 2) + 1;
	r = (t_line *)malloc(sizeof(t_line) * data->line_size);
	if (r == NULL)
		close_app(data);
	i = 0;
	k = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_create_line_in(r, &k, (int []){x, y, i, j});
			j++;
		}
		i++;
	}
	data->lines = r;
}

void	read_file_in(char *line, int **map, char **content, int size_fd[3])
{
	int	i;
	int	j;

	i = 0;
	while (1)
	{
		line = get_next_line(size_fd[2]);
		if (line == NULL)
			break ;
		content = ft_split(line, ' ');
		free(line);
		map[i] = (int *)malloc(sizeof(int) * size_fd[0]);
		if (!map[i])
			return ;
		j = 0;
		while (j < size_fd[0])
		{
			map[i][j] = ft_atoi(content[j]);
			free(content[j]);
			j++;
		}
		free(content);
		i++;
	}
}

int	read_file(char *name, t_data *data)
{
	int		size[2];
	int		fd;
	char	*line;
	char	**content;
	int		**map;

	line = NULL;
	content = NULL;
	get_size(name, &size[0], &size[1]);
	map = (int **)malloc(size[1] * sizeof(int *));
	if (!map)
		return (0);
	fd = open(name, 0);
	read_file_in(line, map, content, (int []){size[0], size[1], fd});
	close(fd);
	read_map(map, size[0], size[1], data);
	return (0);
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(-1);
}
