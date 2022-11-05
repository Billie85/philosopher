/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doctor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 03:10:44 by root              #+#    #+#             */
/*   Updated: 2022/11/06 03:10:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*doctor(void *data)
{
	t_philo	*philo;

	philo = data;
	while (1)
	{
		if (philo->two_way->is_dead == DIE)
			break ;
		if (get_time() - philo->finish_eat_time >= philo->two_way->time2die)
		{
			print_func(philo, "DEAD");
			break ;
		}
	}
	return (NULL);
}
