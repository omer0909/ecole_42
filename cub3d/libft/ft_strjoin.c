/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:50:06 by ysay              #+#    #+#             */
/*   Updated: 2022/01/03 18:05:59 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static char	*ft_strnew(size_t size)
{
	char	*ch;
	size_t	i;

	i = 0;
	ch = (char *)malloc(size + 1);
	if (ch == NULL)
		return (NULL);
	while (i <= size)
		ch[i++] = '\0';
	return (ch);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen((const char *)s1) + ft_strlen((const char *)s2);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		str[i++] = *(s1++);
	while (s2 && *s2)
		str[i++] = *(s2++);
	return (str);
}
