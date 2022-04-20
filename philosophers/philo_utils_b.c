/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ooz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:21:27 by ooz               #+#    #+#             */
/*   Updated: 2022/04/19 15:08:25 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo)
{
	int	i;

	if (!is_life(philo))
		return (0);
	i = (philo->index + 1) * !(philo->index + 1 == philo->table->philo_number);
	pthread_mutex_lock(&philo->table->mutex[i]);
	if (philo->table->forks[i])
	{
		philo->table->forks[i] = 0;
		philo->right_fork = 1;
		printf("%li %i has taken a fork\n", time_now(), philo->index + 1);
	}
	pthread_mutex_unlock(&philo->table->mutex[i]);
	pthread_mutex_lock(&philo->table->mutex[philo->index]);
	if (philo->table->forks[philo->index])
	{
		philo->table->forks[philo->index] = 0;
		philo->left_fork = 1;
		printf("%li %i has taken a fork\n", time_now(), philo->index + 1);
	}
	pthread_mutex_unlock(&philo->table->mutex[philo->index]);
	return (philo->left_fork && philo->right_fork);
}

void	stop_all(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_number)
	{
		pthread_mutex_lock(&table->philo[i].p_mutex);
		table->philo[i].p_life = 0;
		pthread_mutex_unlock(&table->philo[i].p_mutex);
		i++;
	}
}

int	is_life(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->p_mutex);
	result = philo->p_life;
	pthread_mutex_unlock(&philo->p_mutex);
	if (result && time_now() - philo->last_eat > philo->table->time_die)
	{
		pthread_mutex_lock(&philo->table->control);
		if (philo->table->is_life == 0)
		{
			pthread_mutex_unlock(&philo->table->control);
			return (0);
		}
		philo->table->is_life = 0;
		printf("%li %i died\n", time_now(), philo->index + 1);
		stop_all(philo->table);
		pthread_mutex_unlock(&philo->table->control);
		return (0);
	}
	return (result);
}

void	leave_fork(t_philo *philo)
{
	int	i;

	i = (philo->index + 1) * (philo->index + 1 != philo->table->philo_number);
	pthread_mutex_lock(&philo->table->mutex[i]);
	philo->table->forks[i] = 1;
	philo->right_fork = 0;
	pthread_mutex_unlock(&philo->table->mutex[i]);
	pthread_mutex_lock(&philo->table->mutex[philo->index]);
	philo->table->forks[philo->index] = 1;
	philo->left_fork = 0;
	pthread_mutex_unlock(&philo->table->mutex[philo->index]);
}

int	is_compleated(t_table	*table)
{
	int	i;

	i = 0;
	while (i < table->philo_number)
	{
		if (table->philo[i].ate)
			return (0);
		i++;
	}
	return (1);
}
