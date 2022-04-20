/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ooz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 00:24:48 by ooz               #+#    #+#             */
/*   Updated: 2022/04/17 02:44:54 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*select_path(char *v)
{
	char	**paths;
	char	*result;
	int		i;

	if ((*v == '/' || (v[0] == '.' && v[1] == '/')
			|| (v[0] == '.' && v[1] == '.' && v[2] == '/')))
		return ((char *)((size_t)v * !access(v, X_OK)));
	if (!get_env_var("PATH"))
		return (NULL);
	paths = ft_split(get_env_var("PATH"), ':');
	i = 0;
	result = NULL;
	while (paths[i] != NULL)
	{
		ft_swap(&result, ft_strjoin(paths[i++], "/"));
		ft_swap(&result, ft_strjoin(result, v));
		if (!access(result, X_OK))
		{
			ft_free_split(paths);
			return (result);
		}
	}
	free(result);
	ft_free_split(paths);
	return (NULL);
}

void	ft_run(char **env, char **args)
{
	char	*path;

	path = select_path(args[0]);
	if (path == NULL)
	{
		printf("%s :komut bulunamadı!\n", args[0]);
		exit(127);
	}
	exit(execve(path, args, env));
	ft_free_split(args);
	ft_free_split(env);
	free(path);
}

int	ft_command_compare(char *input, char *cmd)
{
	int		i;
	char	*cmd_space;
	int		result;

	i = ft_strlen(cmd) + 1;
	cmd_space = ft_strjoin(cmd, " ");
	result = (!ft_strncmp(input, cmd_space, i) || !ft_strncmp(input, cmd, i));
	free(cmd_space);
	return (result);
}
