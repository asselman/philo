/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:19:15 by aasselma          #+#    #+#             */
/*   Updated: 2023/06/22 15:16:02 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_routin(t_philo *philo)
{
	if (ft_routin(philo) == 1)
		return (1);
	if (ft_sleep(philo) == 1)
		return (1);
	return (0);
}

void	my_usleep(long sleep_time)
{
	long	now;

	now = t_now();
	while (1)
	{
		if ((t_now() - now) >= sleep_time)
			break ;
		usleep(50);
	}
}

void	*ph_managment(void *th)
{
	t_philo			*philo;

	philo = (t_philo *)th;
	if ((philo->id + 1) % 2 == 0)
		usleep(1500);
	while (1)
	{
		pthread_mutex_lock(philo->data->counter);
		if (philo->num_ot_eat != 0 || philo->data->argc == 5)
		{
			ft_printf("is thinking\n", philo);
			pthread_mutex_unlock(philo->data->counter);
			if (start_routin(philo) == 1)
				return (NULL);
		}
		else
		{
			pthread_mutex_unlock(philo->data->counter);
			pthread_mutex_lock(philo->data->lock_done);
			philo->data->done++;
			pthread_mutex_unlock(philo->data->lock_done);
			return (NULL);
		}
	}
	return (NULL);
}

void	ft_contune(t_philo *thread, t_data *data, int num_oft_eat)
{
	int	i;

	i = 0;
	fill_data_of_threads(thread, data, num_oft_eat);
	while (i < data->ph_num)
	{
		thread[i].data = data;
		pthread_create(&thread[i].philo, NULL, ph_managment, &thread[i]);
		usleep(10);
		i = i + 2;
	}
	i = 1;
	if (data->ph_num != 1)
	{
		while (i < data->ph_num)
		{
			thread[i].data = data;
			pthread_create(&thread[i].philo, NULL, ph_managment, &thread[i]);
			usleep(10);
			i = i + 2;
		}
	}
}

int	main(int argc, char **argv)
{
	t_philo			*thread;
	t_data			*data;
	int				i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		data = malloc(sizeof(t_data));
		fill_data(data, ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));
		data->sleep_time = ft_atoi(argv[4]);
		data->argc = argc;
		thread = malloc(data->ph_num * sizeof(t_philo));
		if (argc == 6)
			i = ft_atoi(argv[5]);
		ft_contune(thread, data, i);
		i = check_death(thread);
		pthread_mutex_lock(thread[i].data->counter);
		if (thread[i].data->argc == 5)
			thread[i].num_ot_eat = 1;
		if (thread[i].num_ot_eat != 0)
			printf("%ld %d died\n", t_now() - thread->data->tm, thread[i].id + 1);
		pthread_mutex_unlock(thread[i].data->counter);
		i = 0;
		while (i != thread->data->ph_num)
			pthread_join(thread[i++].philo, NULL);
	}
	return (0);
}
