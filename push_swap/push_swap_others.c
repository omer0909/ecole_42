/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_others.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:08:00 by ooz               #+#    #+#             */
/*   Updated: 2022/02/15 23:50:00 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_split_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	ft_r_control(int *lst, int l, int r)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (i < l - 1)
	{
		if ((lst[i] / r) % 2 < (lst[i + 1] / r) % 2)
			c = 1;
		i++;
	}
	return (c == 0);
}

void	ft_arg(int *argc, char ***argv)
{
	if (*argc == 2)
	{
		*argv = ft_split((*argv)[1], ' ');
		*argc = get_split_size(*argv) + 1;
		ft_memmove(*argv + 1, *argv, (*argc - 1) * sizeof(char *));
	}
}

int	ft_verify(int argc, char **a)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (a[i][j] != '\0')
		{
			if (!ft_isdigit(a[i][j]) && a[i][j] != '-' && a[i][j] != '+')
				return (-1);
			++j;
		}
		if (ft_strlen(a[i]) > 2 && (ft_atoi(a[i]) == -1 || !ft_atoi(a[i])))
			return (-1);
		++i;
	}
	return (0);
}

int	ft_create(int argc, char **argv, int **lst, int **lst_sorted)
{
	int	i;
	int	j;

	i = 0;
	*lst = (int *)malloc(sizeof(int) * (argc - 1));
	*lst_sorted = (int *)malloc(sizeof(int) * (argc - 1));
	while (i < (argc - 1))
	{
		(*lst)[i] = ft_atoi(argv[i + 1]);
		j = 0;
		while (j < i)
		{
			if ((*lst)[j++] == (*lst)[i])
			{
				free(*lst);
				free(*lst_sorted);
				return (-1);
			}
		}
		i++;
	}
	ft_memcpy(*lst_sorted, *lst, (argc - 1) * sizeof(int));
	return (0);
}
