/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:08:07 by ooz               #+#    #+#             */
/*   Updated: 2022/02/15 21:49:17 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_final_control(int *lst, int l)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (i < l - 1)
	{
		if (lst[i] > lst[i + 1])
			c = 1;
		i++;
	}
	return (c == 0);
}

void	ft_print_commands(int commands[12], int cSize)
{
	int	i;

	i = 0;
	while (i < cSize)
	{
		if (commands[i] == 0)
			ft_putstr_fd("sa\n", 1);
		else if (commands[i] == 1)
			ft_putstr_fd("ra\n", 1);
		else if (commands[i] == 2)
			ft_putstr_fd("rra\n", 1);
		i++;
	}
}

int	ft_control(int *lst, int l, int commands[12], int cSize)
{
	int	test[5];
	int	i;

	ft_memcpy(test, lst, l * sizeof (int));
	i = 0;
	while (i < cSize)
	{
		if (commands[i] == 0)
			ft_sl(test, l);
		else if (commands[i] == 1)
			ft_rl(test, l);
		else if (commands[i] == 2)
			ft_rrl(test, l);
		i++;
	}
	return (ft_final_control(test, l));
}

int	ft_random_s(t_array lst, t_array cmds, int *lst_s, t_array *final)
{
	int	my_cmds[3][12];
	int	i;

	if (ft_control(lst.arr, lst.l, cmds.arr, cmds.l) && cmds.l < final->l)
	{
		final->l = cmds.l;
		ft_memcpy(final->arr, cmds.arr, cmds.l * sizeof(int));
	}
	i = 0;
	if (cmds.l < 12)
	{
		while (i < 3)
		{
			ft_memcpy(my_cmds[i], cmds.arr, cmds.l * sizeof(int));
			my_cmds[i][cmds.l] = i;
			ft_random_s(lst, (t_array){my_cmds[i], cmds.l + 1}, lst_s, final);
			i++;
		}
	}
	return (0);
}

void	sort_m(int *lst, int lst_size)
{
	int	*left;
	int	*right;
	int	l_size;
	int	r_size;

	r_size = lst_size / 2;
	l_size = lst_size - r_size;
	left = (int *)malloc(sizeof(int) * l_size);
	right = (int *)malloc(sizeof(int) * r_size);
	ft_memcpy(left, lst, sizeof(int) * l_size);
	ft_memcpy(right, &lst[l_size], sizeof(int) * r_size);
	if (l_size > 1)
		sort_m(left, l_size);
	if (r_size > 1)
		sort_m(right, r_size);
	while (lst_size--)
	{
		if ((left[l_size - 1] >= right[r_size - 1] || !r_size) && l_size)
			lst[lst_size] = left[l_size-- - 1];
		else
			lst[lst_size] = right[r_size-- - 1];
	}
	free(left);
	free(right);
}
