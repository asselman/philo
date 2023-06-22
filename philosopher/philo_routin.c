/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:15:00 by aasselma          #+#    #+#             */
/*   Updated: 2023/06/03 05:23:38 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_sleep(t_philo *philo)
{
	int	checker;

	checker = ft_printf("is sleeping\n", philo);
	my_usleep(philo->data->sleep_time);
	return (checker);
}

int	modify_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->data->lock_death);
	philo->data->dead = 1;
	pthread_mutex_unlock(philo->data->lock_death);
	pthread_mutex_lock(philo->lock_last);
	philo->last_eat = t_now();
	pthread_mutex_unlock(philo->lock_last);
	return (1);
}

int	ft_routin(t_philo *philo)
{
	int	right_id;
	int	checker;

	right_id = philo->id + 1;
	if (philo->id + 1 == philo->data->ph_num)
		right_id = 0;
	pthread_mutex_lock(&philo->forks[philo->id]);
	checker = ft_printf("has taken a fork\n", philo);
	if (philo->data->ph_num == 1)
		if (modify_dead(philo) == 1)
			return (1);
	pthread_mutex_lock(&philo->forks[right_id]);
	checker = ft_printf("has taken a fork\n", philo);
	checker = ft_printf("is eating\n", philo);
	pthread_mutex_lock(philo->lock_last);
	philo->last_eat = t_now();
	pthread_mutex_unlock(philo->lock_last);
	my_usleep(philo->data->eat_time);
	pthread_mutex_lock(philo->data->counter);
	if (philo->data->argc == 6)
		philo->num_ot_eat--;
	pthread_mutex_unlock(philo->data->counter);
	pthread_mutex_unlock(&philo->forks[philo->id]);
	pthread_mutex_unlock(&philo->forks[right_id]);
	return (checker);
}

int	check_num_of_eat(t_philo *thread, int i)
{
	pthread_mutex_lock(thread[i].data->lock_done);
	if (thread[i].data->done == thread[i].data->ph_num)
	{
		pthread_mutex_unlock(thread[i].data->lock_done);
		return (1);
	}
	pthread_mutex_unlock(thread[i].data->lock_done);
	return (0);
}

int	check_death(t_philo *thread)
{
	int	i;

	i = 0;
	while (1)
	{
		if (check_num_of_eat(thread, i) == 1)
			return (i);
		pthread_mutex_lock(thread[i].lock_last);
		
		if ((t_now() - thread[i].last_eat) >= thread[i].data->die_time
			&& thread[i].last_eat != 0)
		{
			pthread_mutex_unlock(thread[i].lock_last);
			pthread_mutex_lock(thread[i].data->lock_death);
			thread[i].data->dead = 1;
			pthread_mutex_unlock(thread[i].data->lock_death);
			return (i);
		}
		pthread_mutex_unlock(thread[i].lock_last);
		i++;
		if (i >= thread[0].data->ph_num - 1)
			i = 0;
	}
}
