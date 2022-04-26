/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:27:28 by ysay              #+#    #+#             */
/*   Updated: 2022/01/04 15:45:52 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			flag;
	long int	num;

	num = 0;
	flag = 1;
	while ((*nptr >= 0x9 && *nptr <= 0xd) || *nptr == 0x20)
		nptr++;
	if (*nptr == '-')
	{
		nptr++;
		flag = -1;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		num *= 10;
		num += (*nptr - '0') * flag;
		nptr++;
		if (num > 2147483647)
			return (-1);
		if (num < -2147483648)
			return (0);
	}
	return ((int)num);
}
