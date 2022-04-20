/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ooz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:13:35 by ooz               #+#    #+#             */
/*   Updated: 2022/04/19 15:05:17 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	table = philo->table;
	philo->last_eat = time_now();
	philo->ate = table->eat_number;
	while (is_life(philo) && philo->ate)
	{
		while (!take_fork(philo))
			if (!is_life(philo))
				return (0);
		printf("%li %i is eating\n", time_now(), philo->index + 1);
		philo->last_eat = time_now();
		if (ft_usleep(table->time_eat, philo))
			return (0);
		leave_fork(philo);
		printf("%li %i is sleeping\n", time_now(), philo->index + 1);
		if (ft_usleep(table->time_sleep, philo))
			return (0);
		printf("%li %i is thinking\n", time_now(), philo->index + 1);
		philo->ate -= philo->ate != -1;
	}
	philo->last_eat = time_now();
	return (0);
}

void	ft_setup(t_table *table)
{
	int	i;

	i = 0;
	table->is_life = 1;
	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->philo_number);
	table->forks = (int *)malloc(sizeof(int) * table->philo_number);
	table->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* table->philo_number);
	pthread_mutex_init(&table->control, NULL);
	while (i < table->philo_number)
	{
		table->philo[i].table = table;
		table->philo[i].index = i;
		table->philo[i].left_fork = 0;
		table->philo[i].right_fork = 0;
		table->forks[i] = 1;
		table->philo[i].p_life = 1;
		pthread_mutex_init(&table->philo[i].p_mutex, NULL);
		pthread_mutex_init(table->mutex + i, NULL);
		i++;
	}
}

void	create_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_number)
	{
		pthread_create(&table->philo[i].thread, NULL, \
		philo_thread, &table->philo[i]);
		i += 2;
	}
	ft_usleep(table->time_eat / 2, table->philo);
	i = 1;
	while (i < table->philo_number)
	{
		pthread_create(&table->philo[i].thread, NULL, \
		philo_thread, &table->philo[i]);
		i += 2;
	}
}

int	main(int argc, char **argv)
{
	t_table	table;

	time_now();
	if (get_args(argc, argv, &table))
	{
		printf("Wrong argument!\n");
		return (-1);
	}
	ft_setup(&table);
	create_philo(&table);
	ft_clean(&table);
	return (0);
}
