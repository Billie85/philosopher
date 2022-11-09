/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doctor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 03:10:44 by root              #+#    #+#             */
/*   Updated: 2022/11/09 23:07:24 by kayumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*doctor(void *data)
{
	t_philo	*philo;
	size_t	now;

	philo = data;
	while (1)
	{
		pthread_mutex_lock(&philo->two_way->mutex);
		if (philo->two_way->is_dead == DIE)
			break ;
		now = get_time();
		if (philo->finish_eat_time + philo->two_way->time2eat < now && \
				now - philo->finish_eat_time >= philo->two_way->time2die)
		{
			print_func(philo, "DEAD");
			break ;
		}
		pthread_mutex_unlock(&philo->two_way->mutex);
	}
	pthread_mutex_unlock(&philo->two_way->mutex);
	return (NULL);
}
