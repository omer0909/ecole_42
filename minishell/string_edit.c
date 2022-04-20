/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_edit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ooz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 00:24:26 by ooz               #+#    #+#             */
/*   Updated: 2022/04/17 03:16:39 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cut_trim(char *str, char *set)
{
	int	l;

	while (ft_strchr(set, *str) && *str != '\0')
		ft_memmove(str, str + 1, ft_strlen(str));
	l = ft_strlen(str);
	while (ft_strchr(set, str[l]) && l > 0)
		str[l--] = '\0';
}

void	cut_all(char *str, char *set)
{
	char	*c;

	while (*set)
	{
		while (ft_strchr(str, *set))
		{
			c = ft_strchr(str, *set);
			ft_memmove(c, c + 1, ft_strlen(c));
		}
		set++;
	}
}

char	**ft_split_arg(char const *s, char c)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_split_quote(s, c);
	while (str[i])
	{
		cut_all(str[i], "\"'");
		i++;
	}
	return (str);
}

char	*ft_middle(char *command, int *i, int *j)
{
	char	*var;
	char	*tmp;

	if (command[*i] == '$')
	{
		(*j)++;
		(*i)++;
		return (ft_itoa(getpid()));
	}
	if (*j - *i == 0)
		return (ft_strdup("$"));
	if (command[*i] == '?')
		return (ft_itoa(g_data.last_return));
	tmp = ft_substr(command, *i, *j - *i);
	var = get_env_var(tmp);
	free(tmp);
	if (var == NULL)
		var = "";
	return (ft_strdup(var));
}

char	*ft_set_var(char *cmd, int i)
{
	int		j;
	char	*front;
	char	*middle;
	char	*back;

	while (cmd[i - 1] != '$' || in_single_quotes(cmd, i - 1))
		if (cmd[i++ - 1] == '\0')
			return (cmd);
	j = i;
	while (cmd[j] != '\0' && cmd[j] != ' '
		&& cmd[j] != '$' && cmd[j] != '"' && cmd[j] != ':')
		j++;
	if (cmd[j] == '"')
		ft_memmove(cmd + j, cmd + j + 1, ft_strlen(cmd + j));
	front = ft_substr(cmd, 0, i - 1);
	middle = ft_middle(cmd, &i, &j);
	back = ft_substr(cmd, j, ft_strlen(cmd + j));
	ft_swap(&cmd, ft_strjoin(front, middle));
	free(front);
	free(middle);
	ft_swap(&cmd, ft_strjoin(cmd, back));
	free(back);
	return (ft_set_var(cmd, i + 1));
}
