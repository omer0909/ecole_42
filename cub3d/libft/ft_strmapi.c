/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:54:53 by ysay              #+#    #+#             */
/*   Updated: 2022/01/03 18:05:59 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{	
	size_t	len;
	size_t	i;
	char	*ch;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	ch = (char *)malloc(len + 1);
	if (ch == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ch[i] = f(i, s[i]);
		i++;
	}
	ch[i] = '\0';
	return (ch);
}
