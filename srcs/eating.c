/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 03:10:48 by root              #+#    #+#             */
/*   Updated: 2022/11/06 09:46:25 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eating(t_philo *philo)
{
	print_func(philo, "EATING");
	precise_sleep(philo->two_way->time2eat);
	pthread_mutex_unlock(&philo->two_way->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->two_way->fork[philo->right_fork]);
	return (0);
}

int	taking_fork(t_philo *philo)
{
	philo->right_fork = RIGHT_FORK;
	philo->left_fork = LEFT_FORK;
	if (philo->right_fork == philo->two_way->number_of_philosophers)
		philo->right_fork = 0;
	if (philo->two_way->number_of_philosophers == ONE_PHILO)
	{
		pthread_mutex_lock(&philo->two_way->fork[philo->left_fork]);
		print_func(philo, "TAKE_LEFT_FORK");
		pthread_mutex_unlock(&philo->two_way->fork[philo->left_fork]);
		return (0);
	}
	pthread_mutex_lock(&philo->two_way->fork[philo->left_fork]);
	print_func(philo, "TAKE_LEFT_FORK");
	pthread_mutex_lock(&philo->two_way->fork[philo->right_fork]);
	print_func(philo, "TAKE_RIGHT_FORK");
	return (0);
}