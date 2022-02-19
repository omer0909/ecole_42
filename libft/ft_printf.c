/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:34:54 by ooz               #+#    #+#             */
/*   Updated: 2022/02/17 12:29:27 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_utils.c"

static void	ft_putunbr(unsigned int n, int *x)
{
	char	s[10];
	int		i;

	i = 0;
	if (n == 0)
		*x += write(1, "0", 1);
	while (n)
	{
		s[i++] = n % 10 + '0';
		n /= 10;
	}
	while (i--)
		*x += write(1, s + i, 1);
}

static void	ft_putptr(size_t n, int *x)
{
	char	s[16];
	int		i;

	if (n == 0)
	{
		ft_putstrxxx("0x0", x);
		return ;
	}
	ft_memset(s, '\0', 16);
	i = 0;
	while (n)
	{
		s[i++] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	*x += write(1, "0x", 2);
	while (i--)
		*x += write(1, s + i, 1);
}

static void	ft_putinth(unsigned int n, char *l, int *x)
{
	char	s[16];
	int		i;

	i = 0;
	if (n == 0)
	{
		ft_putstrxxx("0", x);
		return ;
	}
	while (n)
	{
		s[i++] = l[n % 16];
		n /= 16;
	}
	while (i--)
		*x += write(1, s + i, 1);
}

static int	ft_select(char v, va_list list, int *x)
{
	if (v == 'c')
		ft_putcharxxx(va_arg(list, int), x);
	else if (v == 's')
		ft_putstrxxx(va_arg(list, char *), x);
	else if (v == 'p')
		ft_putptr(va_arg(list, size_t), x);
	else if (v == 'd')
		ft_putnbrxxx(va_arg(list, int), x);
	else if (v == 'i')
		ft_putnbrxxx(va_arg(list, int), x);
	else if (v == 'u')
		ft_putunbr(va_arg(list, unsigned int), x);
	else if (v == 'x')
		ft_putinth(va_arg(list, size_t), "0123456789abcdef", x);
	else if (v == 'X')
		ft_putinth(va_arg(list, size_t), "0123456789ABCDEF", x);
	else if (v == '%')
		*x += write(1, "%", 1);
	else
		return (-1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		b;
	int		x;

	x = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
		{
			b = 0;
			while (*(++str) == ' ')
				b = 1;
			if (b)
				x += write(1, " ", 1);
			if (ft_select(*str, list, &x) == -1)
				x += write(1, "%", 1);
		}
		else
			x += write(1, str, 1);
		str++;
	}
	va_end(list);
	return (x);
}
