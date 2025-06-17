/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:34:07 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/06/17 15:23:22 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	join_threads(t_philosopher *philo)
{
	int	i;

	i = 0;
	while (i < philo->param->philo_num)
	{
		pthread_join(philo->philo_t, NULL);
		i++;
		philo = philo->next;
	}
}

void	destroy_mutex(t_philosopher *philo)
{
	int	i;

	i = 0;
	while (i < philo->param->philo_num)
	{
		pthread_mutex_destroy(&philo->fork);
		pthread_mutex_destroy(&philo->m_eaten);
		philo = philo->next;
		i++;
	}
	pthread_mutex_destroy(&philo->param->m_start);
	pthread_mutex_destroy(&philo->param->global);
}

int	philo_one(t_parameters param)
{
	if (param.philo_num == 1)
	{
		printf("%i %i has taken a fork\n", 0, 1);
		usleep(param.tto_die * 1000);
		printf("%i %i died\n", param.tto_die, 1);
		return (1);
	}
	return (0);
}

int	main(int av, char **ac)
{
	t_parameters	param;
	t_philosopher	*first;

	if (av > 6 || av < 5)
		return (printf("Wrong nb of t_parameters\n"), 1);
	if (!init_param(&param, &ac[1]))
		return (printf("Wrong parameters\n"), 2);
	if (philo_one(param))
		return (0);
	param.start = getms();
	param.die = 0;
	pthread_mutex_init(&(param.global), NULL);
	first = init_philo(&param);
	if (!first)
		return (printf("failed malloc\n"), 3);
	pthread_mutex_init(&first->param->m_start, NULL);
	pthread_mutex_lock(&first->param->m_start);
	init_thread(first);
	first->param->start = getms();
	pthread_mutex_unlock(&first->param->m_start);
	monitoring(first);
	join_threads(first);
	destroy_mutex(first);
	free_all(first);
	return (0);
}
