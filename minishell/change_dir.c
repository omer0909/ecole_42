/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ooz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 00:25:04 by ooz               #+#    #+#             */
/*   Updated: 2022/04/20 21:24:13 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	chdir_helper(t_chdir *cd, char *input, int fd_out)
{
	g_data.last_return = 0;
	getcwd(cd->old_path, MAX_FILE_DIR);
	cd->path = ft_split_arg(input, ' ');
	if (cd->path[1] == NULL)
	{
		chdir(get_env_var("HOME"));
	}
	else if (!ft_strncmp(cd->path[1], "-", 2))
	{
		chdir(g_data.old_path);
		ft_print_working_dir(fd_out);
	}
	else
	{
		return (1);
	}
	return (0);
}

void	ft_change_dir(char *input, int fd_out)
{
	t_chdir	cd;

	if (chdir_helper(&cd, input, fd_out) && *cd.path[1] != '/')
	{
		getcwd(cd.my_path, MAX_FILE_DIR);
		ft_strlcat(cd.my_path, "/", MAX_FILE_DIR);
		ft_strlcat(cd.my_path, cd.path[1], MAX_FILE_DIR);
		if (chdir(cd.my_path))
		{
			ft_putstr_fd(cd.path[1], fd_out);
			ft_putstr_fd(" :konum bulunamadı!\n", fd_out);
			g_data.last_return = 1;
			ft_free_split(cd.path);
			if (fd_out != 1)
				close (fd_out);
			return ;
		}
	}
	else
		chdir(cd.path[1]);
	ft_memcpy(g_data.old_path, cd.old_path, MAX_FILE_DIR);
	ft_free_split(cd.path);
	if (fd_out != 1)
		close (fd_out);
}
