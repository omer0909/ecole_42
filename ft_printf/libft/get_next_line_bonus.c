/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:53:46 by ooz               #+#    #+#             */
/*   Updated: 2022/01/13 01:53:46 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	s_c(char **a, char *b)
{
	char	*tmp;

	tmp = *a;
	*a = b;
	free(tmp);
}

static int	load(const int fd, char **str)
{
	char	buff[BUFFER_SIZE + 1];
	size_t	i;

	while (1)
	{
		if (*str != NULL && ft_strchr(*str, '\n'))
			break ;
		i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0 && *str == NULL)
			return (-1);
		if (i <= 0)
			break ;
		if (*str == NULL)
		{
			*str = (char *)ft_calloc(1, 1);
			if (*str == NULL)
				return (-1);
		}
		buff[i] = '\0';
		s_c(str, ft_strjoin(*str, buff));
		if (*str == NULL)
			return (-1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str[FD_SIZE];
	size_t		i;
	char		*r;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (fd > FD_SIZE || load(fd, &str[fd]) == -1)
		return (NULL);
	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	r = ft_substr(str[fd], 0, i + (str[fd][i] == '\n'));
	if (str[fd][i + (str[fd][i] == '\n')] == '\0')
	{
		free(str[fd]);
		str[fd] = NULL;
		return (r);
	}
	s_c(&str[fd], ft_substr(str[fd], i + 1, ft_strlen(str[fd] + i)));
	return (r);
}
