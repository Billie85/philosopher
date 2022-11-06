/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 03:11:24 by root              #+#    #+#             */
/*   Updated: 2022/11/06 09:39:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	precise_sleep(size_t sleep_time)
{
	size_t	end_time;

	end_time = get_time() + sleep_time;
	while (get_time() < end_time)
	{
		usleep(100);
	}
}
