/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 02:06:32 by ooz               #+#    #+#             */
/*   Updated: 2022/02/28 23:29:06 by ooz              ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		ft_error("arguman hatali!");
	pid = ft_atoi(argv[1]);
	ft_sent(pid, argv[2][0]);
}
