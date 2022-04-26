/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:46:54 by ysay              #+#    #+#             */
/*   Updated: 2022/01/04 10:00:42 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_printx(int pn, int fg, int fd)
{
	int	a;

	if (pn == 0)
		return ;
	ft_printx(pn / 10 * fg, 1, fd);
	a = pn % 10 * fg + '0';
	write(fd, &a, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	fg;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		fg = -1;
		write(fd, "-", 1);
	}
	else
		fg = 1;
	ft_printx(n, fg, fd);
}
