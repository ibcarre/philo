/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:44:01 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/06/17 15:24:26 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleeping(t_philosopher *philo, int *d)
{
	pthread_mutex_lock(&philo->param->global);
	if (philo->param->die != 0)
	{
		pthread_mutex_unlock(&philo->param->global);
		*d = *d + 1;
		return ;
	}
	printf("%li %i is sleeping\n", gettime(philo), philo->id);
	pthread_mutex_unlock(&philo->param->global);
	ft_usleep(philo->param->tto_sleep);
}

void	thinking(t_philosopher *philo, int *d)
{
	pthread_mutex_lock(&philo->param->global);
	if (philo->param->die != 0)
	{
		pthread_mutex_unlock(&philo->param->global);
		*d = *d + 1;
		return ;
	}
	printf("%li %i is thinking\n", gettime(philo), philo->id);
	pthread_mutex_unlock(&philo->param->global);
	usleep(200);
}
