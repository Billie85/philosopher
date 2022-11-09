/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 03:10:39 by root              #+#    #+#             */
/*   Updated: 2022/11/09 13:06:57 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	check_time_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->two_way->mutex);
	philo->finish_eat_time = get_time();
	pthread_mutex_unlock(&philo->two_way->mutex);
	philo->count_eat++;
	if (philo->count_eat == philo->two_way->number_of_time_2_eat)
	{
		if (philo->philo_id == philo->two_way->number_of_philosophers -1)
			philo->two_way->is_dead = DIE;
	}
}

int	think(t_philo *philo_data)
{
	print_func(philo_data, "THINK");
	return (0);
}

int	ft_sleep(t_philo *philo_data)
{
	print_func(philo_data, "SLEEP");
	precise_sleep(philo_data->two_way->time2sleep);
	return (0);
}

size_t	get_time(void)
{
	struct timeval	m_time;

	gettimeofday (&m_time, NULL);
	return ((m_time.tv_sec * 1000) + (m_time.tv_usec / 1000));
}
