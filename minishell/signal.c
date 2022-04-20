/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ooz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 00:24:21 by ooz               #+#    #+#             */
/*   Updated: 2022/04/17 00:33:27 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_quit_handler(int signum, siginfo_t *info, void *context)
{
	t_list	*tmp;

	(void)context;
	(void)info;
	tmp = g_data.pid_list;
	ft_printf("\rÇıkış!\n");
	while (tmp)
	{
		g_data.sig_quit_sent = 1;
		kill(signum, *(int *)tmp->content);
		wait((int *)tmp->content);
		tmp = tmp->next;
	}
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	t_list	*tmp;

	(void)context;
	(void)info;
	if (g_data.pid_list == NULL)
	{		
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		return ;
	}
	tmp = g_data.pid_list;
	ft_printf("\n");
	while (tmp)
	{
		g_data.sig_int_sent = 1;
		kill(signum, *(int *)tmp->content);
		wait((int *)tmp->content);
		tmp = tmp->next;
	}
}

void	ft_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
}

void	active_signal(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_quit_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGQUIT, &sa, NULL);
}
