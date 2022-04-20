/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ooz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 00:24:38 by ooz               #+#    #+#             */
/*   Updated: 2022/04/20 21:23:08 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_env(int fd_out)
{
	int	i;

	i = 0;
	while (g_data.env[i] != NULL)
	{
		if (ft_strchr(g_data.env[i], '='))
		{
			ft_putstr_fd(g_data.env[i], fd_out);
			ft_putchar_fd('\n', fd_out);
		}
		i++;
	}
	if (fd_out != 1)
		close (fd_out);
}

char	*ft_swap(char **a, char *b)
{
	char	*tmp;

	if (b == NULL)
		error("malloc error\n");
	tmp = *a;
	*a = b;
	if (tmp != NULL)
		free(tmp);
	return (*a);
}

void	ft_shell(void)
{
	char	*input;

	while (1)
	{
		input = readline("\033[0;32mMinishell$\033[0;37m ");
		if (input == NULL)
		{
			ft_putstr_fd("\r\033[0;32mMinishell$\033[0;37m exit\n", 2);
			exit (0);
		}
		add_history(input);
		ft_setup_process(ft_split_quote(input, '|'));
		free(input);
	}
}

char	**env_dup(char **env)
{
	char	**result;
	int		i;

	result = (char **)malloc(sizeof(char *) * 400);
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strnstr(env[i], "PWD=", ft_strlen("PWD=")))
		{
			result[i] = (char *)malloc(400 + 5);
			ft_strlcpy(result[i], env[i], 400 + 5);
		}
		else
			result[i] = ft_strdup(env[i]);
		i++;
	}
	result[i] = NULL;
	return (result);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	g_data.env = env_dup(env);
	g_data.is_child = 0;
	g_data.sig_int_sent = 0;
	g_data.sig_quit_sent = 0;
	getcwd(g_data.old_path, MAX_FILE_DIR);
	ft_signals();
	ft_shell();
	ft_free_split(g_data.env);
	return (0);
}
