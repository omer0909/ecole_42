/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:22:56 by ysay              #+#    #+#             */
/*   Updated: 2022/04/24 18:18:58 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map.h>

int	kill_map(t_map *map)
{
	if (!map)
		return (0);
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	kill_arg(map->data);
	free(map);
	return (1);
}

int	check_map(t_map *map, char *s, char *s2)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if (!ft_strchr(s, map->data[i][j]))
				return (-1);
			if (ft_strchr(s2, map->data[i][j]))
				k++;
			j++;
		}
		i++;
	}
	if (1 != k)
		return (-1);
	i = 0;
	return (0);
}

int	check_wall(t_map *map, char ch)
{
	int		i;
	int		j;
	char	*s;

	i = 1;
	while (map->data[i] && map->data[i + 1])
	{
		s = map->data[i];
		j = 0;
		while (s[j])
		{
			if (s[j] == ch && ((!j || s[j - 1] == ' '
						|| !s[j + 1] || s[j + 1] == ' ')
					|| ((size_t)j + 1 > ft_strlen(map->data[i - 1])
						|| map->data[i - 1][j] == ' ')
				|| ((size_t)j + 1 > ft_strlen(map->data[i + 1])
					|| map->data[i + 1][j] == ' ')))
				return (-1);
			j++;
		}	
		i++;
	}
	if (ft_strchr(map->data[i], ch) || ft_strchr(map->data[0], ch))
		return (-1);
	return (0);
}

t_map	*init_map(int fd)
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	if (-1 == get_param(map, fd, NULL) || -1 == map->c.f || -1 == map->f.f)
	{
		ft_putstr_fd("Error\nMap Error\n", 2);
		kill_map(map);
		return (NULL);
	}
	if (-1 == my_get_map(map, fd) || -1 == check_map(map, "01NSEW ", "NWES")
		|| check_wall(map, '0') || check_wall(map, 'N')
		|| check_wall(map, 'S') || check_wall(map, 'W') || check_wall(map, 'E'))
	{
		ft_putstr_fd("Error\nMap Error\n", 2);
		kill_map(map);
		return (NULL);
	}
	return (map);
}

t_map	*create_map(char *av)
{
	t_map	*map;
	int		fd;
	int		l;

	l = ft_strlen(av);
	if (l < 4 || av[l - 4] != '.' || av[l - 3] != 'c' || av[l - 2] != 'u'
		|| av[l - 1] != 'b')
	{	
		ft_putstr_fd("Error\nArgument Error\n", 2);
		exit (-1);
	}
	fd = open(av, 0);
	if (0 > fd)
	{
		ft_putstr_fd("Error\nFolder Error\n", 2);
		exit (-1);
	}
	map = init_map(fd);
	if (map)
		get_pos(map);
	return (map);
}
