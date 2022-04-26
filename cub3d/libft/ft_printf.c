/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:48:00 by ysay              #+#    #+#             */
/*   Updated: 2022/01/11 11:00:04 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	put_n(unsigned long int i, char *str, int base, int flag)
{
	int	c;

	if (i == 0)
		return (write(1, "0", 1));
	c = 0;
	if (flag == 0)
	{	
		if (i / base > 0)
			c = put_n(i / base, str, base, flag);
		return (c + write(1, &str[i % base], 1));
	}
	flag = 1;
	if ((int)i < 0)
	{
		flag = -1;
		c = write(1, "-", 1);
	}
	if ((int)i / base * flag > 0)
		c += put_n((int)i / base * flag, str, base, 1);
	return (c + write(1, &str[(int)i % base * flag], 1));
}

static int	put_s(char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
		i++;
	return (write(1, s, i));
}

static int	put_arg(va_list *ls, const char *s)
{
	long int		p;
	unsigned int	i;

	if (*s == '%')
		return (put_s("%"));
	else if (*s == 's' || *s == 'p')
	{
		p = va_arg(*ls, long int);
		if (*s == 's')
			return (put_s((char *)p));
		i = write(1, "0x", 2);
		return (i + put_n((long int)p, "0123456789abcdef", 16, 0));
	}
	i = va_arg(*ls, unsigned int);
	if (*s == 'c')
		return (write(1, &i, 1));
	if (*s == 'i' || *s == 'd')
		return (put_n(i, "0123456789", 10, 1));
	if (*s == 'u')
		return (put_n(i, "0123456789", 10, 0));
	if (*s == 'x')
		return (put_n(i, "0123456789abcdef", 16, 0));
	return (put_n(i, "0123456789ABCDEF", 16, 0));
}

static int	is_arg(const char *s)
{
	char	*str;

	str = "csiudpxX%";
	while (*s == '%' && *str && *str != *(s + 1))
		str++;
	return (*s == '%' && *str && *str == *(s + 1));
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	ls;

	i = 0;
	va_start(ls, s);
	while (*s)
	{
		if (is_arg((const char *)s))
		{
			i += put_arg(&ls, (s + 1));
			s += 2;
		}
		else if (*s == '%')
			s++;
		else
			i += write(1, s++, 1);
	}
	va_end(ls);
	return (i);
}
