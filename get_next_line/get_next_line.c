/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:49:30 by ooz               #+#    #+#             */
/*   Updated: 2022/01/05 22:49:30 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strnew(size_t size)
{
	char	*ptr;

	size++;
	ptr = (char *)malloc(size);
	if (ptr == NULL)
		return (NULL);
	while (size--)
		ptr[size] = '\0';
	return (ptr);
}

void	s_c(char **a, char *b)
{
	char	*tmp;

	tmp = *a;
	*a = b;
	free(tmp);
}

int	load(const int fd, char **str)
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
			*str = ft_strnew(0);
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
	static char	*str;
	size_t		i;
	char		*r;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (load(fd, &str) == -1)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	r = ft_substr(str, 0, i + (str[i] == '\n'));
	if (str[i + (str[i] == '\n')] == '\0')
	{
		free(str);
		str = NULL;
		return (r);
	}
	s_c(&str, ft_substr(str, i + 1, ft_strlen(str + i)));
	return (r);
}
