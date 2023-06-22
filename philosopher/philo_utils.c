/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 06:45:39 by aasselma          #+#    #+#             */
/*   Updated: 2023/06/02 17:32:53 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philo.h"

long	ft_atoi(char *s)
{
	long	r;
	long	sign;
	long	i;

	r = 0;
	sign = 1;
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		r = r * 10 + s[i++] - '0';
	if ((r * sign) <= 0)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	return (r * sign);
}

long	t_now(void)
{
	struct timeval	tv;
	long			befor;

	gettimeofday(&tv, NULL);
	befor = ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
	return (befor);
}

int	ft_printf(char *str, t_philo *philo)
{
	long	tm;

	tm = philo->data->tm;
	pthread_mutex_lock(philo->data->lock_death);
	if (philo->data->dead == 0)
	{
		printf("%ld %d %s", t_now() - tm, philo->id + 1, str);
		pthread_mutex_unlock(philo->data->lock_death);
	}
	else
	{
		pthread_mutex_unlock(philo->data->lock_death);
		return (1);
	}
	return (0);
}

void	fill_data(t_data *data, int ph_num, long die_t, long eat_t)
{
	pthread_mutex_t	*done_lock;
	pthread_mutex_t	*death_lock;
	pthread_mutex_t	times_of_eat;

	death_lock = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(death_lock, NULL);
	data->counter = malloc(sizeof(pthread_mutex_t));
	data->counter = &times_of_eat;
	pthread_mutex_init(data->counter, NULL);
	done_lock = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(done_lock, NULL);
	data->ph_num = ph_num;
	data->die_time = die_t;
	data->eat_time = eat_t;
	data->dead = 0;
	data->done = 0;
	data->lock_death = death_lock;
	data->lock_done = done_lock;
	data->tm = t_now();
}

void	fill_data_of_threads(t_philo *th, t_data *dt, int n_o_e)
{
	int				i;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*last_eat_lock;

	i = 0;
	mutex = malloc(dt->ph_num * sizeof(pthread_mutex_t));
	last_eat_lock = malloc(sizeof(pthread_mutex_t));
	while (i != dt->ph_num)
		pthread_mutex_init(&(mutex[i++]), NULL);
	pthread_mutex_init(last_eat_lock, NULL);
	i = 0;
	while (i != dt->ph_num)
	{
		th[i].num_ot_eat = n_o_e;
		th[i].id = i;
		th[i].forks = mutex;
		th[i].lock_last = last_eat_lock;
		i++;
	}
}
