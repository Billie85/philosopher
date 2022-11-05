/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 03:11:28 by root              #+#    #+#             */
/*   Updated: 2022/11/06 06:22:25 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	another_action2(char *s, t_philo *philo, size_t time_now)
{
	char	*eat;
	char	*dead;

	dead = "DEAD";
	eat = "EATING";
	if (my_strcmp(s, eat) == 0)
	{
		printf(RED"%ld %ld is eating\n"BACK, time_now, philo->philo_id);
		check_time_eat(philo);
	}
	else if (my_strcmp(s, dead) == 0)
	{
		printf(GREEN"%ld %ld is dead\n"BACK, time_now, philo->philo_id);
		philo->two_way->is_dead = DIE;
	}
	return (0);
}

int	another_action(char *s, t_philo *philo, size_t time_now)
{
	char	*take_l_fork;
	char	*take_r_fork;
	char	*think;

	take_l_fork = "TAKE_LEFT_FORK";
	take_r_fork = "TAKE_RIGHT_FORK";
	think = "THINK";
	if (my_strcmp(s, take_l_fork) == 0)
		printf(ORANGE"%ld %ld take a fork [left %ld] \n"BACK, time_now, \
			philo->philo_id, philo->left_fork);
	else if (my_strcmp(s, take_r_fork) == 0)
		printf(ORANGE"%ld %ld take a fork [right %ld] \n"BACK, time_now, \
			philo->philo_id, philo->right_fork);
	else if (my_strcmp(s, think) == 0)
	{
		printf("%ld %ld is thinking\n"BACK, time_now, philo->philo_id);
	}
		another_action2(s, philo, time_now);
	return (0);
}

int	print_func(t_philo *philo, char *s)
{
	size_t	time_now;
	char	*sleep;

	sleep = "SLEEP";
	pthread_mutex_lock(&philo->two_way->print_mutex);
	time_now = get_time() - philo->start_time;
	if (philo->two_way->is_dead == NOT_DIE)
	{
		if (my_strcmp(s, sleep) == 0)
		{
			printf(CLAN"%ld %ld is sleeping\n"BACK, time_now, philo->philo_id);
		}
			another_action(s, philo, time_now);
	}
	pthread_mutex_unlock(&philo->two_way->print_mutex);
	return (0);
}
