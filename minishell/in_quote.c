/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ooz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 00:44:56 by ooz               #+#    #+#             */
/*   Updated: 2022/04/17 00:45:45 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	in_char(const char *str, int index, char c)
{
	int	in;
	int	i;

	in = 0;
	i = 0;
	if (str[index] == c)
		return (-1);
	while (str[i])
	{
		if (i == index)
		{
			if (in)
				return (1);
			return (0);
		}
		if (str[i] == c)
		{
			in = !in;
		}
		i++;
	}
	return (0);
}

int	in_quotes(const char *s, int i)
{
	return (in_char(s, i, '\'') || in_char(s, i, '"'));
}

int	in_single_quotes(const char *s, int i)
{
	return (in_char(s, i, '\''));
}
