/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:34:46 by ooz               #+#    #+#             */
/*   Updated: 2022/04/03 20:07:07 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrxxx(char *s, int *x)
{
	if (!s)
	{
		ft_putstrxxx("(null)", x);
		return ;
	}
	while (*s)
		*x += write(1, s++, 1);
}

void	ft_putcharxxx(char c, int *x)
{
	*x += write(1, &c, 1);
}

void	ft_putnbrxxx(int n, int *x)
{
	char	s[10];
	int		i;
	long	nbr;

	nbr = n;
	i = 0;
	if (nbr == 0)
		*x += write(1, "0", 1);
	if (nbr < 0)
	{
		nbr *= -1;
		*x += write(1, "-", 1);
	}
	while (nbr)
	{
		s[i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	while (i--)
		*x += write(1, s + i, 1);
}
