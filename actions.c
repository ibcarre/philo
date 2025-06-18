/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:44:01 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/06/18 12:30:01 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_fork(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->param->global);
	if (philo->param->die != 0)
	{
		pthread_mutex_unlock(&philo->param->global);
		return ;
	}
	printf("%li %i has taken a fork\n", gettime(philo), philo->id);
	pthread_mutex_unlock(&philo->param->global);
}

void	is_eating(t_philosopher *philo)
{
	long	time;

	time = gettime(philo);
	printf("%li %i is eating\n", time, philo->id);
	philo->lasteaten = time;
	pthread_mutex_unlock(&philo->param->global);
	pthread_mutex_lock(&philo->m_eaten);
	philo->nb_eaten++;
	pthread_mutex_unlock(&philo->m_eaten);
	ft_usleep(philo->param->tto_eat);
}

void	unlock_forks(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
	}
	else
	{
		pthread_mutex_unlock(&philo->next->fork);
		pthread_mutex_unlock(&philo->fork);
	}
}

void	eating(t_philosopher *philo, int *d)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->fork);
		print_fork(philo);
		pthread_mutex_lock(&philo->next->fork);
		print_fork(philo);
	}
	else
	{
		pthread_mutex_lock(&philo->next->fork);
		print_fork(philo);
		pthread_mutex_lock(&philo->fork);
		print_fork(philo);
	}
	pthread_mutex_lock(&philo->param->global);
	if (philo->param->die)
	{
		pthread_mutex_unlock(&philo->param->global);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		*d = *d + 1;
		return ;
	}
	is_eating(philo);
	unlock_forks(philo);
}
