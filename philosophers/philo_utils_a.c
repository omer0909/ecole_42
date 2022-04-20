/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ooz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:21:19 by ooz               #+#    #+#             */
/*   Updated: 2022/04/19 13:04:59 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_now(void)
{
	static long		first_time = 0;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (first_time == 0)
		first_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - first_time);
}

int	ft_usleep(long int time_in_ms, t_philo *philo)
{
	long int	start_time;

	start_time = time_now();
	while (time_now() - start_time < time_in_ms)
	{
		if (!is_life(philo))
			return (1);
		usleep(100);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long	result;
	int		a;

	while (*nptr == '\n' || *nptr == '\t' || *nptr == '\r' \
	|| *nptr == '\v' || *nptr == '\f' || *nptr == ' ')
		nptr++;
	a = *nptr == '-';
	nptr += (a || *nptr == '+');
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + *nptr++ - '0';
		if (result > 0x7FFFFFFF + a)
			return (-1);
	}
	return (result * ((a * -2) + 1));
}

int	get_args(int argc, char **argv, t_table *table)
{
	if (argc != 5 && argc != 6)
		return (1);
	table->philo_number = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	table->eat_number = -1;
	if (argc == 6)
	{
		table->eat_number = ft_atoi(argv[5]);
		if (table->eat_number < 0)
			return (1);
	}
	if (table->philo_number < 0 || table->time_die < 0 || table->time_eat < 0
		|| table->time_sleep < 0)
		return (1);
	return (0);
}

void	ft_clean(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_number)
	{
		pthread_join(table->philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < table->philo_number)
	{
		pthread_mutex_unlock(table->mutex + i);
		pthread_mutex_destroy(table->mutex + i);
		pthread_mutex_unlock(&table->philo[i].p_mutex);
		pthread_mutex_destroy(&table->philo[i].p_mutex);
		i++;
	}
	pthread_mutex_unlock(&table->control);
	pthread_mutex_destroy(&table->control);
	free(table->forks);
	free(table->philo);
}
