/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:20:06 by ooz               #+#    #+#             */
/*   Updated: 2022/03/02 06:10:31 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_abs(float a)
{
	return (a * ((a >= 0) * 2 - 1));
}

float	ft_max(float a, float b)
{
	return (a * (a >= b) + b * (b > a));
}

void	image_pixel_put(t_data *data, int x, int y, int color)
{
	if (x < 0 && x > RES_X && y < 0 && y > RES_Y)
		return ;
	*((int *)(data->img.addr + (y * data->img.line_len) \
	+ (x * (data->img.bbp / 8)))) = color;
}

static size_t	w_c(char const *s, char c)
{
	size_t	r;

	r = 0;
	while (*s != '\0')
	{
		if ((*s != c && *s != '\n') \
		&& (s[1] == '\0' || s[1] == c || s[1] == '\n'))
			r++;
		s++;
	}
	return (r);
}

int	ft_verify(char *file)
{
	int		fd;
	int		x;
	int		i;
	char	*line;

	fd = open(file, 0);
	line = get_next_line(fd);
	if (line == NULL || *line == '\0' || ft_strchr(line, '\n') == NULL)
		return (-1);
	x = w_c(line, ' ');
	while (line != NULL)
	{
		i = w_c(line, ' ');
		if (i != x && i != x - 1)
			return (-1);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
