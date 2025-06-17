/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibtihal <ibtihal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 08:42:33 by ibtihal           #+#    #+#             */
/*   Updated: 2025/06/13 08:43:15 by ibtihal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_param(t_parameters *param, char **ac)
{
	int	n;

	if (!ft_atoi(ac[0], &n))
		return (0);
	param->philo_num = n;
	if (!ft_atoi(ac[1], &n))
		return (0);
	param->tto_die = n;
	if (!ft_atoi(ac[2], &n))
		return (0);
	param->tto_eat = n;
	if (!ft_atoi(ac[3], &n))
		return (0);
	param->tto_sleep = n;
	if (!ac[4])
	{
		param->eat_con = 0;
		return (1);
	}
	param->eat_con = 1;
	if (!ft_atoi(ac[4], &n))
		return (0);
	param->nb_eat = n;
	return (1);
}

t_philosopher	*init_philo(t_parameters *para)
{
	int				i;
	t_philosopher	*philo;
	t_philosopher	*first;

	i = 2;
	philo = malloc(sizeof(t_philosopher));
	if (!philo)
		return (NULL);
	first = philo;
	first->nb_eaten = 0;
	first->param = para;
	first->next = NULL;
	first->id = 1;
	while (i < para->philo_num + 1)
	{
		philo = ft_lst_add_philo(philo, para);
		if (!philo)
			return (free_all(first), NULL);
		philo->id = i;
		i++;
	}
	philo->next = first;
	return (first);
}

void	init_thread(t_philosopher *philo)
{
	int	i;

	i = 0;
	while (i < philo->param->philo_num)
	{
		pthread_mutex_init(&(philo->fork), NULL);
		pthread_mutex_init(&philo->m_eaten, NULL);
		philo->lasteaten = 0;
		if (i % 2 == 0)
			pthread_create(&(philo->philo_t), NULL, even, (void *)philo);
		else
			pthread_create(&(philo->philo_t), NULL, odd, (void *)philo);
		i++;
		philo = philo->next;
	}
}
