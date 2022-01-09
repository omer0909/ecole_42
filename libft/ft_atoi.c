/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:14:17 by ooz               #+#    #+#             */
/*   Updated: 2022/01/03 12:14:17 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cntrl(int nptr)
{
	int	a;
	int	b;

	a = (nptr == '\n' || nptr == '\t' || nptr == '\r');
	b = (nptr == '\v' || nptr == '\f' || nptr == ' ');
	return (a || b);
}

int	ft_atoi(const char *nptr)
{
	long	result;
	int		a;

	while (ft_cntrl(*nptr))
		nptr++;
	a = *nptr == '-';
	nptr += (a || *nptr == '+');
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + *nptr++ - '0';
		if (result > 0x7FFFFFFF && a == 0)
			return (-1);
		if (result > 0x80000000 && a == 1)
			return (0);
	}
	return (result * ((a * -2) + 1));
}
