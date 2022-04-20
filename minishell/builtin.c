/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ooz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 00:25:04 by ooz               #+#    #+#             */
/*   Updated: 2022/04/20 21:31:26 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char *program, int fd_out)
{
	int		n;
	int		first;
	int		i;
	char	**argv;

	argv = ft_split_arg(program, ' ');
	n = 1;
	i = 1;
	while (argv[i] != NULL && ft_strncmp(argv[i], "-n", 2) == 0 && i++)
		n = 0;
	first = 0;
	while (argv[i] != NULL && argv[i] != NULL)
	{
		if (first)
			ft_putstr_fd(" ", fd_out);
		ft_putstr_fd(argv[i++], fd_out);
		first = 1;
	}
	if (n)
		ft_putstr_fd("\n", fd_out);
	g_data.last_return = 0;
	ft_free_split(argv);
	if (fd_out != 1)
		close (fd_out);
}

void	ft_exit_end(char **args, int r)
{
	ft_free_split(args);
	exit(r);
}

void	ft_exit(char *program)
{
	char	**args;
	int		a;

	ft_putstr_fd("exit\n", 2);
	args = ft_split_arg(program, ' ');
	if (args[1] == NULL)
		ft_exit_end(args, 0);
	a = 0;
	if (args[1][a] == '+' || args[1][a] == '-')
		a = 1;
	while (args[1][a] >= '0' && args[1][a] <= '9' && args[1][a] != '\0')
		a++;
	if (args[1][a] != '\0')
	{
		ft_putstr_fd("Argüman sayı değil\n", 2);
		ft_exit_end(args, 255);
	}
	else if (args[2] != NULL)
	{
		ft_putstr_fd("Çok fazla argüman var\n", 2);
		ft_free_split(args);
		return ;
	}
	ft_exit_end(args, ft_atoi(args[1]));
}

void	ft_print_working_dir(int fd_out)
{
	char	my_path[MAX_FILE_DIR];

	getcwd(my_path, MAX_FILE_DIR);
	ft_putstr_fd(my_path, fd_out);
	ft_putstr_fd("\n", fd_out);
	if (fd_out != 1)
		close (fd_out);
}

int	ft_builtin_commands(char *program, int fd_out)
{
	if (ft_command_compare(program, "exit"))
		ft_exit(program);
	else if (ft_command_compare(program, "pwd"))
		ft_print_working_dir(get_out_files(fd_out, program));
	else if (ft_command_compare(program, "export"))
		export_env(program, get_out_files(fd_out, program));
	else if (ft_command_compare(program, "unset"))
		unset_env(program);
	else if (ft_command_compare(program, "env"))
		ft_print_env(get_out_files(fd_out, program));
	else if (ft_command_compare(program, "cd"))
	{
		ft_change_dir(program, get_out_files(fd_out, program));
		getcwd(get_env_var("PWD"), MAX_FILE_DIR);
	}
	else if (ft_command_compare(program, "echo"))
		ft_echo(program, get_out_files(fd_out, program));
	else if (*program == '>')
		close(get_file(program + 1, 0, O_CREAT | O_TRUNC));
	else
		return (0);
	return (1);
}
