/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:43:56 by aasselma          #+#    #+#             */
/*   Updated: 2023/06/02 17:08:36 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct data
{
	int				dead;
	int				done;
	int				ph_num;
	int				argc;
	long			die_time;
	long			eat_time;
	long			sleep_time;
	long			tm;
	pthread_mutex_t	*lock_death;
	pthread_mutex_t	*counter;
	pthread_mutex_t	*lock_done;
}					t_data;

typedef struct philo
{
	int				id;
	int				num_ot_eat;
	long			last_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*lock_last;
	t_data			*data;
	pthread_t		philo;
}					t_philo;

void				fill_data(t_data *data, int ph_num, long die_t, long eat_t);
void				fill_data_of_threads(t_philo *th, t_data *dt, int n_o_e);
int					ft_printf(char *str, t_philo *philo);
int					ft_routin(t_philo *philo);
int					ft_sleep(t_philo *philo);
int					check_death(t_philo *thread);
long				ft_atoi(char *s);
long				t_now(void);
void				my_usleep(long sleep_time);

#endif