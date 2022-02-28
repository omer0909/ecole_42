/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 02:06:26 by ooz               #+#    #+#             */
/*   Updated: 2022/02/24 11:13:13 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <libft.h>

void	sig_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	static int				i;
	static unsigned char	c;

	(void)ucontext;
	(void)siginfo;
	if (signum == SIGUSR1)
		c += 0b10000000 >> i;
	i++;
	if (i != 8)
		return ;
	write(1, &c, 1);
	write(1, "\n", 1);
	i = 0;
	c = 0;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	ft_printf("pid = %i\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
