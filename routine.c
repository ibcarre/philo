/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:41:51 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/06/18 11:53:31 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*odd(void *ph)
{
	t_philosopher	*philo;
	int				d;

	philo = (t_philosopher *) ph;
	d = 0;
	pthread_mutex_lock(&philo->param->m_start);
	pthread_mutex_unlock(&philo->param->m_start);
	if (!philo->param->tto_eat)
		return (NULL);
	while (!d)
	{
		eating(philo, &d);
		sleeping(philo, &d);
		thinking(philo, &d);
	}
	return (NULL);
}

void	*even(void *ph)
{
	t_philosopher	*philo;
	int				d;

	philo = (t_philosopher *) ph;
	d = 0;
	pthread_mutex_lock(&philo->param->m_start);
	pthread_mutex_unlock(&philo->param->m_start);
	if (!philo->param->tto_eat)
		return (NULL);
	while (!d)
	{
		sleeping(philo, &d);
		thinking(philo, &d);
		eating(philo, &d);
	}
	return (NULL);
}
