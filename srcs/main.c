/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 03:11:07 by root              #+#    #+#             */
/*   Updated: 2022/11/09 10:58:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	allocate_memory(t_info *args)
{
	args->fork = malloc(sizeof(pthread_mutex_t) * \
			(args->number_of_philosophers));
	if (args->fork == NULL)
		printf("Faild malloc\n");
	args->philo = malloc(sizeof(t_philo) * (args->number_of_philosophers));
	if (args->philo == NULL)
	{
		free(args->fork);
		printf("Faild malloc\n");
	}
}

void	check_args(char *argv[], t_info *args)
{
	if (argv[5])
		args->number_of_time_2_eat = ft_atoi(argv[5]);
	else
		args->number_of_time_2_eat = 0;
	args->number_of_philosophers = ft_atoi(argv[1]);
	args->time2die = ft_atoi(argv[2]);
	args->time2eat = ft_atoi(argv[3]);
	args->time2sleep = ft_atoi(argv[4]);
}

void	init(t_info *args)
{
	args->number_of_philosophers = 0;
	args->time2die = 0;
	args->time2eat = 0;
	args->time2sleep = 0;
	args->is_dead = NOT_DIE;
}

int	create_pthread(t_info *args)
{
	long		time;
	size_t		i;

	i = 0;
	time = get_time();
	pthread_mutex_init(&args->mutex, NULL);
	pthread_mutex_init(&args->print_mutex, NULL);
	while (i < args->number_of_philosophers)
	{
		pthread_mutex_init(&args->fork[i], NULL);
		args->philo[i].philo_id = i + 1;
		args->philo[i].two_way = args;
		args->philo[i].start_time = time;
		args->philo[i].finish_eat_time = get_time();
		
		args->philo[i].count_eat = 0;
		if (pthread_create(&args->philo[i].thread, NULL, \
					philosopher, &args->philo[i]) != 0)
			printf("Faildd to create thread\n");
		i++;
	}
	join(args);
	destroy_pthread(args);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	args;

	if (argc != 5 && argc != 6)
	{
		printf(PURPLE"--------------try again------------\n"
			"[1]:number_of_philosophers\n" \
				"[2]:time_to_die\n" \
				"[3]:time_to_eat_time\n" \
				"[4]:time_to_sleep\n" \
				"[5]:number_of_each_philosophers_must_eat\n"BACK);
		return (0);
	}
	init(&args);
	check_args(argv, &args);
	allocate_memory(&args);
	create_pthread(&args);
	free(args.philo);
	free(args.fork);
}
