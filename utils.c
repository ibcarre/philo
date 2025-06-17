/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibtihal <ibtihal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:53:41 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/06/13 11:49:44 by ibtihal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all(t_philosopher *philo)
{
	int				i;
	int				phil_num;
	t_philosopher	*next;

	i = 0;
	phil_num = philo->param->philo_num;
	while (i < phil_num && philo)
	{
		next = philo->next;
		free(philo);
		philo = next;
		i++;
	}
}

long	getms(void)
{
	t_timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	return (((cur_time.tv_sec * 1000) + (cur_time.tv_usec / 1000)));
}

int	ft_usleep(long milliseconds)
{
	long	start;

	start = getms();
	while ((getms() - start) < milliseconds)
		usleep(200);
	return (0);
}

long	gettime(t_philosopher *philo)
{
	long	time;

	time = getms() - philo->param->start;
	return (time);
}

t_philosopher	*ft_lst_add_philo(t_philosopher *philo, t_parameters *param)
{
	t_philosopher	*next;

	next = malloc(sizeof(t_philosopher));
	philo->next = next;
	next->nb_eaten = 0;
	next->param = param;
	next->next = NULL;
	return (next);
}
