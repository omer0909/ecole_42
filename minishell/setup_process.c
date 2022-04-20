/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ooz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 00:24:15 by ooz               #+#    #+#             */
/*   Updated: 2022/04/17 04:19:48 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_create_process(char *command, int fd[2], int del)
{
	int					pid;
	struct sigaction	sa;

	cut_trim(command, " ");
	command = ft_set_var(ft_strdup(command), 1);
	if (ft_builtin_commands(command, fd[1]))
	{
		free(command);
		return (0);
	}
	pid = fork();
	if (pid == 0)
	{
		sa.sa_sigaction = sig_quit_handler;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGQUIT, &sa, NULL);
		g_data.is_child = 1;
		dup2(get_in_files(fd[0], command), 0);
		dup2(get_out_files(fd[1], command), 1);
		close(del);
		ft_run(g_data.env, ft_split_arg(command, ' '));
		exit(0);
	}
	free(command);
	return (pid);
}

void	ft_wait_and_clear_lst(void *content)
{
	if (*(int *)content)
	{
		wait((int *)content);
		if (g_data.sig_int_sent)
			g_data.last_return = 130;
		else if (g_data.sig_quit_sent)
			g_data.last_return = 131;
		else
			g_data.last_return = WEXITSTATUS(*(int *)content);
		g_data.sig_int_sent = 0;
		g_data.sig_quit_sent = 0;
	}
	free(content);
}

void	add_pid_list(t_list **pid_list, int pid)
{
	t_list	*tmp;
	int		*pid_ptr;

	pid_ptr = (int *)malloc(sizeof(int));
	*pid_ptr = pid;
	tmp = ft_lstnew(pid_ptr);
	ft_lstadd_front(pid_list, tmp);
}

void	lock_signal(char **command)
{
	active_signal();
	ft_lstclear(&g_data.pid_list, ft_wait_and_clear_lst);
	signal(SIGQUIT, SIG_IGN);
	ft_free_split(command);
}

void	ft_setup_process(char **command)
{
	t_process	ps;

	ps.tmp_fd = 0;
	ps.i = 0;
	g_data.pid_list = NULL;
	while (command[ps.i] != NULL)
	{
		if (command[ps.i + 1] != NULL)
		{
			pipe(ps.fd);
			add_pid_list(&g_data.pid_list, ft_create_process(command[ps.i++],
					(int []){ps.tmp_fd, ps.fd[1]}, ps.fd[0]));
			close(ps.fd[1]);
			if (ps.tmp_fd != 0)
				close(ps.tmp_fd);
			ps.tmp_fd = ps.fd[0];
			continue ;
		}
		add_pid_list(&g_data.pid_list, ft_create_process(command[ps.i++],
				(int []){ps.tmp_fd, 1}, -1));
		if (ps.tmp_fd != 0)
			close(ps.tmp_fd);
	}
	lock_signal(command);
}
