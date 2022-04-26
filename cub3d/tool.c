/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:46:05 by ysay              #+#    #+#             */
/*   Updated: 2022/04/24 18:15:48 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tool.h>

int	kill_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg && arg[i])
		free(arg[i++]);
	if (arg)
		free(arg);
	return (0);
}

char	*join_and_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (tmp);
}

int	my_get_line(int fd, char **str, int f)
{
	int		i;
	char	*s;

	i = 0;
	*str = get_next_line(fd);
	if (!*str)
		return (-1);
	if (f)
		s = ft_strtrim(*str, " \n\t\v\f\r");
	else
		s = ft_strdup(*str);
	free(*str);
	while (s && s[i])
	{	
		if (!ft_isspace(s[i]))
		{
			*str = s;
			return (0);
		}
		i++;
	}
	free(s);
	*str = NULL;
	return (0);
}

void	get_pos(t_map *map)
{
	int		i;
	int		k;
	int		t;

	t = 0;
	i = 0;
	while (map->data[i])
	{
		k = 0;
		while (map->data[i][k])
		{
			if (ft_strchr("WESN", map->data[i][k]))
			{
				while (map->data[i][k] != "ENWS"[t])
					t++;
				map->ang = t * 90;
				map->data[i][k] = '0';
				map->y = i;
				map->x = k;
				return ;
			}
			k++;
		}
		i++;
	}
}
