/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ooz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:16:29 by ooz               #+#    #+#             */
/*   Updated: 2022/04/17 01:25:53 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	w_l(char const *s, char c)
{
	size_t	r;

	r = 0;
	while (s[r] != '\0' && (s[r] != c || in_quotes(s, r)))
		r++;
	return (r);
}

static size_t	w_c(char const *s, char c)
{
	size_t	r;
	size_t	i;

	r = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == '\0' \
		|| (s[i + 1] == c && !in_quotes(s, i + 1))))
			r++;
		i++;
	}
	return (r);
}

char	**ft_split_quote(char const *s, char c)
{
	char		**r;
	size_t		i;
	size_t		l;
	size_t		w_i;
	char const	*sf;

	sf = s;
	if (!s)
		return (NULL);
	l = w_c(s, c);
	r = (char **)malloc(sizeof(char *) * l + 1);
	i = 0;
	while (i < l)
	{
		while ((*s == c && !in_quotes(sf, s - sf)) && *s != '\0')
			s++;
		r[i] = (char *)malloc(sizeof(char) * w_l(s, c) + 1);
		w_i = 0;
		while ((*s != c || in_quotes(sf, s - sf)) && *s != '\0')
			r[i][w_i++] = *s++;
		r[i][w_i] = '\0';
		i++;
	}
	r[i] = NULL;
	return (r);
}
