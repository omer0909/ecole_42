/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:06:58 by ooz               #+#    #+#             */
/*   Updated: 2022/02/15 21:27:53 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sl(int *l, int size)
{
	int	tmp;

	if (size < 2)
		return ;
	tmp = l[0];
	l[0] = l[1];
	l[1] = tmp;
}

void	ft_ss(int *a, int sA, int *b, int sB)
{
	ft_sl(a, sA);
	ft_sl(b, sB);
}

void	ft_pl(int *dst, int *dstS, int *src, int *srcS)
{
	if (*srcS == 0)
		return ;
	ft_memmove(&dst[1], dst, *dstS * sizeof(int));
	dst[0] = src[0];
	(*dstS)++;
	(*srcS)--;
	ft_memmove(src, &src[1], sizeof(int) * *srcS);
}

void	ft_rl(int *l, int s)
{
	int	tmp;

	if (s < 2)
		return ;
	tmp = l[0];
	ft_memmove(l, &l[1], sizeof(int) * (s - 1));
	l[s - 1] = tmp;
}

void	ft_rr(int *a, int sA, int *b, int sB)
{
	ft_rl(a, sA);
	ft_rl(b, sB);
}
