/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:56:15 by ysay              #+#    #+#             */
/*   Updated: 2022/01/04 10:00:53 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	char	*ch;
	size_t	sr;

	if (s == NULL || set == NULL)
		return (NULL);
	while (*s && ft_strchr(set, *s))
		s++;
	if (!*s)
		return (ft_strdup(""));
	sr = ft_strlen((char *)s);
	while (sr && ft_strchr(set, s[sr - 1]))
		sr--;
	ch = (char *)malloc(sr + 1);
	if (!ch)
		return (NULL);
	ft_strlcpy(ch, s, sr + 1);
	return (ch);
}
