/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:04:17 by sayysf            #+#    #+#             */
/*   Updated: 2022/01/06 17:46:03 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_buffer(char *str)
{
	char	*buff;

	buff = ft_strchr((const char *)str, '\n');
	if (!buff)
	{
		free(str);
		return (NULL);
	}
	buff++;
	if (!*buff)
	{
		free(str);
		return (NULL);
	}
	buff = ft_strdup(buff);
	free(str);
	return (buff);
}

char	*get_line(char *str)
{
	char	*stop;
	char	*line;
	size_t	len;

	stop = ft_strchr((const char *)str, '\n');
	if (!stop)
		return (ft_strdup((const char *)str));
	stop++;
	len = ft_strlen((const char *)str) - ft_strlen((const char *)stop);
	line = ft_substr((const char *)str, 0, len);
	return (line);
}

char	*read_buffer(char *str, int fd, char *buff)
{
	int		cd;
	char	*s;

	cd = 1;
	while (cd != 0 && !ft_strchr((const char *)str, '\n'))
	{
		cd = read(fd, buff, BUFFER_SIZE);
		if (cd < 0)
		{
			free(str);
			return (NULL);
		}
		buff[cd] = '\0';
		s = ft_strjoin((const char *)str, buff);
		free(str);
		str = s;
	}
	if (!*str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*read_data(char *str, int fd)
{
	char	*buff;

	if (!str)
		str = ft_strdup("");
	if (!str)
		return (NULL);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	str = read_buffer(str, fd, buff);
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_data((char *)str, fd);
	if (!str)
		return (NULL);
	line = get_line((char *)str);
	if (!line)
		return (NULL);
	str = get_buffer((char *)str);
	return (line);
}
