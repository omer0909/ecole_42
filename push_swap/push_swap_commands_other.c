/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands_other.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:06:51 by ooz               #+#    #+#             */
/*   Updated: 2022/02/15 21:28:10 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrl(int *l, int s)
{
	int	tmp;

	tmp = l[s - 1];
	if (s < 2)
		return ;
	ft_memmove(&l[1], l, sizeof(int) * (s - 1));
	l[0] = tmp;
}

void	ft_rrr(int *a, int sA, int *b, int sB)
{
	ft_rrl(a, sA);
	ft_rrl(b, sB);
}

void	ft_ra_p(t_array a, t_array b, int r)
{
	if (b.l > 1 && (b.arr[0] / (r * 2)) % 2 == 0)
	{
		ft_rl(a.arr, a.l);
		ft_putstr_fd("ra\n", 1);
	}
	else
	{
		ft_rr(a.arr, a.l, b.arr, b.l);
		ft_putstr_fd("rr\n", 1);
	}
}

void	ft_pa_p(int *dst, int *dstS, int *src, int *srcS)
{
	ft_pl(dst, dstS, src, srcS);
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb_p(int *dst, int *dstS, int *src, int *srcS)
{
	ft_pl(dst, dstS, src, srcS);
	ft_putstr_fd("pb\n", 1);
}
