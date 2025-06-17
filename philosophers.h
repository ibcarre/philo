/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibtihal <ibtihal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:34:00 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/06/13 11:34:21 by ibtihal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

typedef struct timeval	t_timeval;

typedef struct parameters
{
	int				philo_num;
	int				tto_die;
	int				tto_eat;
	int				tto_sleep;
	long			start;
	pthread_mutex_t	m_start;
	int				eat_con;
	int				nb_eat;
	int				die;
	pthread_mutex_t	global;
}	t_parameters;

//EATING SLEEPING THINKING

typedef struct philosopher
{
	pthread_t			philo_t;
	pthread_mutex_t		fork;
	struct philosopher	*next;
	t_parameters		*param;
	int					id;
	int					nb_eaten;
	pthread_mutex_t		m_eaten;
	long				lasteaten;
}	t_philosopher;

int				ft_atoi(char *str, int *n);
void			free_all(t_philosopher *philo);
t_philosopher	*ft_lst_add_philo(t_philosopher *philo, t_parameters *param);
t_philosopher	*init_philo(t_parameters *para);
int				init_param(t_parameters *param, char **ac);
void			init_thread(t_philosopher *philo);
void			*even(void *p);
void			*odd(void *p);
long			getms(void);
long			gettime(t_philosopher *philo);
void			monitoring(t_philosopher *philo);
void			sleeping(t_philosopher *philo, int *d);
void			eating(t_philosopher *philo, int *d);
void			thinking(t_philosopher *philo, int *d);
int				ft_usleep(long microseconds);

#endif