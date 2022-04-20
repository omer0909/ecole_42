/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ooz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 00:24:59 by ooz               #+#    #+#             */
/*   Updated: 2022/04/20 21:28:26 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_var(char *var)
{
	size_t	var_size;
	char	**env;

	env = g_data.env;
	while (1)
	{
		if (*env == NULL)
			return (NULL);
		var_size = ft_strlen(var);
		if (ft_strnstr(*env, var, var_size) && (*env)[var_size] == '=')
			return (*env + var_size + 1);
		env++;
	}
}

void	ft_print_env_export(int fd_out)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	while (g_data.env[i] != NULL)
	{
		ft_putstr_fd("declare -x ", fd_out);
		j = 0;
		a = 1;
		while (g_data.env[i][j])
		{
			ft_putchar_fd(g_data.env[i][j], fd_out);
			if (g_data.env[i][j] == '=')
			{
				ft_putchar_fd('"', fd_out);
				a = 0;
			}
			j++;
		}
		ft_putstr_fd((char *)((size_t)"\"\n" + a), fd_out);
		i++;
	}
}

void	ft_env_del(char *var)
{
	int	var_size;
	int	i;

	i = 0;
	while (g_data.env[i] != NULL)
	{
		var_size = ft_strlen(var);
		if (ft_strnstr(g_data.env[i], var, var_size)
			&& (g_data.env[i][var_size] == '='
			|| g_data.env[i][var_size] == '\0'))
		{
			free(g_data.env[i]);
			ft_memmove(g_data.env + i,
				g_data.env + (i + 1), (400 - i - 1) * sizeof(int));
			return ;
		}
		i++;
	}
}

void	unset_env(char *command)
{
	char	**args;

	args = ft_split_arg(command, ' ');
	if (args[1] == NULL)
		return ;
	ft_env_del(args[1]);
	ft_free_split(args);
}

void	export_env(char *command, int fd_out)
{
	int		i;
	char	**args;
	char	**var;

	args = ft_split_arg(command, ' ');
	if (args[1] == NULL)
	{
		ft_print_env_export(fd_out);
		if (fd_out != 1)
			close (fd_out);
		return ;
	}
	var = ft_split(args[1], '=');
	if (get_env_var(var[0]))
		ft_env_del(var[0]);
	i = 0;
	while (g_data.env[i] != NULL)
		i++;
	g_data.env[i] = ft_strdup(args[1]);
	g_data.env[i + 1] = NULL;
	ft_free_split(args);
	ft_free_split(var);
	if (fd_out != 1)
		close (fd_out);
}
