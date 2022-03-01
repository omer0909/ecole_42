/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:59:08 by ooz               #+#    #+#             */
/*   Updated: 2022/02/15 23:32:23 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"

typedef struct s_array
{
	int	*arr;
	int	l;
}	t_array;

void	process(int *lstSorted, int *a, int s_a);
void	ft_aling_r(int *a, int *b, int l_r[2], int *lst_s);
int		ft_bw_search(int c, int *lst_s, int l);
void	sort_m(int *lst, int lst_size);
int		ft_random_s(t_array lst, t_array cmds, int *lst_s, t_array *final);
int		ft_control(int *lst, int l, int commands[12], int cSize);
void	ft_print_commands(int commands[12], int cSize);
int		ft_final_control(int *lst, int l);
int		ft_r_control(int *lst, int l, int r);
void	ft_rr(int *a, int sA, int *b, int sB);
void	ft_rl(int *l, int s);
void	ft_pl(int *dst, int *dstS, int *src, int *srcS);
void	ft_ss(int *a, int sA, int *b, int sB);
void	ft_sl(int *l, int size);
void	ft_rrl(int *l, int s);
void	ft_rrr(int *a, int sA, int *b, int sB);
void	ft_pa_p(int *dst, int *dstS, int *src, int *srcS);
void	ft_pb_p(int *dst, int *dstS, int *src, int *srcS);
int		get_split_size(char **argv);
int		ft_r_control(int *lst, int l, int r);
void	ft_ra_p(t_array a, t_array b, int r);
int		ft_verify(int argc, char **argv);
void	ft_arg(int *argc, char ***argv);
int		ft_create(int argc, char **argv, int **lst, int **lst_sorted);

#endif
