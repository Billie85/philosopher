/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 03:11:02 by root              #+#    #+#             */
/*   Updated: 2022/11/06 03:11:03 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	join(t_info *args)
{
	size_t	i;

	i = 0;
	while (i < args->number_of_philosophers)
	{
		if (pthread_join(args->philo[i++].thread, NULL) != 0)
			printf("Faild pthread_join\n");
	}
}

void	destroy_pthread(t_info *args)
{
	size_t	i;

	i = 0;
	while (i < args->number_of_philosophers)
	{
		if (pthread_mutex_destroy(&args->fork[i++]) != 0)
			printf("Faild pthread_mutex_destroy\n");
	}
	if (pthread_mutex_destroy(&args->mutex) != 0)
		printf("Faild pthread_mutex_destroy\n");
	if (pthread_mutex_destroy(&args->print_mutex) != 0)
		printf("Faild pthread_mutex_destroy\n");
}
