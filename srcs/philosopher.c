/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 03:11:20 by root              #+#    #+#             */
/*   Updated: 2022/11/06 09:46:06 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*monitor_detach(t_philo *philo)
{
	pthread_t	doctor_thread;

	if (pthread_create(&doctor_thread, NULL, doctor, philo) != 0)
		printf("Faild to create thread\n");
	pthread_detach(doctor_thread);
	return (NULL);
}

void	*philosopher(void *data)
{
	t_philo	*philo;

	philo = data;
	monitor_detach(philo);
	if (philo->philo_id % 2 == 0)
		precise_sleep(philo->two_way->time2sleep);
	while (1)
	{
		if (philo->two_way->is_dead == DIE)
			break ;
		taking_fork(philo);
		if (philo->two_way->number_of_philosophers == ONE_PHILO)
		{
			print_func(philo, "DEAD");
			break ;
		}
		eating(philo);
		ft_sleep(philo);
		think(philo);
	}
	return (NULL);
}
