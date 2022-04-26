/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:50:42 by ysay              #+#    #+#             */
/*   Updated: 2022/01/04 14:49:15 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t d_s)
{
	size_t	dest_len;
	size_t	i;

	i = 0;
	dest_len = 0;
	while (dest[dest_len] && dest_len < d_s)
		dest_len++;
	while (src[i] && (dest_len + i + 1) < d_s)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (dest_len < d_s)
		dest[dest_len + i] = '\0';
	return (dest_len + ft_strlen(src));
}
