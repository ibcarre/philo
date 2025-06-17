/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:36:57 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/06/17 15:22:47 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_array(int *eaten, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (!eaten[i])
			return (0);
		i++;
	}
	return (1);
}

void	fill_array(int *arr, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		arr[i] = 0;
		i++;
	}
}

void	check_death(int a, t_philosopher *philo)
{
	if (a)
	{
		printf("%li %i died\n", gettime(philo), philo->id);
		pthread_mutex_unlock(&philo->param->global);
	}
	else
	{
		philo->param->die = 1;
		pthread_mutex_unlock(&philo->param->global);
	}
}

void	check_nb_eat(t_philosopher *philo, int *eaten)
{
	if (philo->param->eat_con && eaten[philo->id - 1] == 0)
	{
		pthread_mutex_lock(&philo->m_eaten);
		if (philo->nb_eaten >= philo->param->nb_eat)
			eaten[philo->id - 1] = 1;
		pthread_mutex_unlock(&philo->m_eaten);
	}
}

void	monitoring(t_philosopher *philo)
{
	int	*eaten;
	int	a;

	a = 0;
	eaten = malloc(philo->param->philo_num * sizeof(int));
	fill_array(eaten, philo->param->philo_num);
	usleep(100);
	while (!check_array(eaten, philo->param->philo_num))
	{
		pthread_mutex_lock(&philo->param->global);
		if (philo->param->tto_die < gettime(philo) - philo->lasteaten)
		{
			philo->param->die = 1;
			a = 1;
			break ;
		}
		pthread_mutex_unlock(&philo->param->global);
		check_nb_eat(philo, eaten);
		philo = philo->next;
		usleep(1000);
	}
	check_death(a, philo);
	free(eaten);
	return ;
}
