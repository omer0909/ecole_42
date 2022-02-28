/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 02:06:32 by ooz               #+#    #+#             */
/*   Updated: 2022/02/28 23:29:01 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <libft.h>

void	ft_error(char *s)
{
	ft_printf("%s\n", s);
	exit(0);
}

void	ft_sent(int pid, char c)
{
	unsigned char	a;

	if (c == '\0')
		c = '\n';
	a = 0b10000000;
	while (a)
	{
		if (a & c)
		{
			if (kill(pid, SIGUSR1))
				ft_error("SIGUSR1 gonderilemedi!");
		}
		else
		{
			if (kill(pid, SIGUSR2))
				ft_error("SIGUSR2 gonderilemedi!");
		}
		usleep (100);
		a >>= 1;
	}
}

void	sig_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	(void)signum;
	(void)siginfo;
	(void)ucontext;
	ft_printf("işlem basarili");
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	int					one;
	struct sigaction	sa;

	if (argc != 3)
		ft_error("arguman hatali!");
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(argv[1]);
	i = 0;
	one = 1;
	while (argv[2][i] || one--)
	{
		ft_sent(pid, argv[2][i]);
		i += one;
	}
}
