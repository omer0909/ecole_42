/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:26:35 by ooz               #+#    #+#             */
/*   Updated: 2022/01/05 22:28:32 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (n--)
		*tmp++ = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*r;

	i = nmemb * size;
	if (i > 0X7FFFFFFF)
		return (NULL);
	r = malloc(i);
	if (!r)
		return (NULL);
	ft_bzero(r, i);
	return (r);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	r = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (r == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
		r[i++] = *s1++;
	while (*s2 != '\0')
		r[i++] = *s2++;
	r[i] = '\0';
	return (r);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (s == NULL )
		return (NULL);
	if (ft_strlen(s) <= start)
		return ((char *)ft_calloc(1, 1));
	result = (char *)malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[i + start];
		i++;
	}
	result[i] = '\0';
	return (result);
}
