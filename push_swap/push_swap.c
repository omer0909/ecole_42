/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:07:20 by ooz               #+#    #+#             */
/*   Updated: 2022/03/01 18:06:17 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_bw_search(int c, int *lst_s, int l)
{
	int	i;

	i = l / 2;
	if (c == lst_s[i])
		return (i);
	if (c < lst_s[i])
		return (ft_bw_search(c, lst_s, i));
	return (i + 1 + ft_bw_search(c, lst_s + i + 1, l - (i + 1)));
}

void	ft_aling_r(int *a, int *b, int l_r[2], int *lst_s)
{
	int	i;
	int	b_s;
	int	a_s;

	a_s = l_r[0];
	b_s = 0;
	if (ft_final_control(a, l_r[0]))
		return ;
	i = -1;
	while (++i < l_r[0])
	{
		if ((ft_bw_search(a[0], lst_s, l_r[0]) / l_r[1]) % 2)
			ft_ra_p((t_array){a, a_s}, (t_array){b, a_s}, l_r[2]);
		else
			ft_pb_p(b, &b_s, a, &a_s);
	}
	while (b_s)
		ft_pa_p(a, &a_s, b, &b_s);
	ft_aling_r(a, b, (int [2]){l_r[0], l_r[1] * 2}, lst_s);
}

void	process(int *lst_sorted, int *a, int s_a)
{
	int	*b;

	b = (int *)malloc(sizeof(int) * s_a);
	ft_aling_r(a, b, (int [2]){s_a, 1}, lst_sorted);
	free(b);
}

void	ft_rand(int l, int *a, int *a_s)
{
	int		cmds[12];
	t_array	final;

	final.l = 12;
	final.arr = cmds;
	ft_random_s((t_array){a, l}, (t_array){(int [12]){0}, 0}, a_s, &final);
	ft_print_commands(final.arr, final.l);
}

int	main(int argc, char **argv)
{
	int	*lst;
	int	*lst_sorted;

	ft_arg(&argc, &argv);
	if (ft_verify(argc, argv) || ft_create(argc, argv, &lst, &lst_sorted))
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	sort_m(lst_sorted, argc - 1);
	if (argc - 1 <= 5)
		ft_rand(argc - 1, lst, lst_sorted);
	else
		process(lst_sorted, lst, argc - 1);
}
