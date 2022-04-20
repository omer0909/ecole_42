/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ooz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:36:41 by ooz               #+#    #+#             */
/*   Updated: 2022/04/14 15:41:02 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <time.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_philo	t_philo;

typedef struct s_table {
	t_philo			*philo;
	int				*forks;
	int				philo_number;
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				eat_number;
	int				is_life;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	control;
}	t_table;

typedef struct s_philo {
	pthread_t		thread;
	pthread_mutex_t	p_mutex;
	int				p_life;
	int				index;
	long			last_eat;
	int				ate;
	t_table			*table;
	int				left_fork;
	int				right_fork;
}	t_philo;

//philo_utils_a.c
long	time_now(void);
int		ft_usleep(long int time_in_ms, t_philo *philo);
int		ft_atoi(const char *nptr);
int		get_args(int argc, char **argv, t_table *table);
void	ft_clean(t_table *table);

//philo_utils_b.c
void	stop_all(t_table *table);
int		is_life(t_philo *philo);
int		take_fork(t_philo *philo);
void	leave_fork(t_philo *philo);
int		is_compleated(t_table	*table);

//philo.c
void	*control_thread(void *arg);
void	*philo_thread(void *arg);
void	ft_setup(t_table *table);
void	create_philo(t_table *table);
int		main(int argc, char **argv);

#endif
