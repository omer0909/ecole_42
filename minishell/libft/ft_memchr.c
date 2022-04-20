/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:16:03 by ooz               #+#    #+#             */
/*   Updated: 2022/01/03 12:16:03 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*tmp_s;
	unsigned char		tmp_c;

	tmp_s = (unsigned const char *)s;
	tmp_c = (unsigned char)c;
	while (n--)
		if (*tmp_s++ == tmp_c)
			return ((void *)(tmp_s - 1));
	return (NULL);
}
