/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:24:33 by ysay              #+#    #+#             */
/*   Updated: 2022/02/08 15:24:38 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

int	check_wall(t_map *map, int c)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		if (map->data[0][i] != c || map->data[map->row - 1][i] != c)
			return (0);
		i++;
	}
	i = 0;
	while (i < map->row)
	{
		if (map->data[i][0] != c || map->data[i][map->len - 1] != c)
			return (0);
		i++;
	}
	return (1);
}

int	check_other(t_map *map, char *str)
{
	int		i;
	char	*s;

	i = 0;
	while (i < map->row)
	{
		s = map->data[i];
		while (*s)
		{
			if (!ft_strchr(str, *s))
				return (0);
			s++;
		}
		i++;
	}
	return (1);
}

t_map	*check_map(char *s, char *str, char *str2)
{
	t_map	*map;
	char	*st;

	if (!s || !str || !str2)
		return (NULL);
	st = str2;
	while (*st)
	{
		if (!ft_strchr(s, *st))
			return (NULL);
		st++;
	}
	map = creat_map(s);
	if (!map)
		return (NULL);
	if (map->row < 3 || !check_wall(map, str[1]) || !check_other(map, str))
	{
		kill_map(map);
		return (NULL);
	}
	return (map);
}
