/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:59:16 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/06/17 14:32:20 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str, int *n)
{
	long	nb;
	int		i;

	i = 0;
	nb = 0;
	if (str[i] == '-')
		return (0);
	while (is_num(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
		if (nb < 0)
			return (0);
	}
	if (str[i])
		return (0);
	*n = nb;
	if (*n <= 0)
		return (0);
	return (1);
}
