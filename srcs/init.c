#include "../philo.h"

void	init(t_info *args)
{
	int	i;

	args->number_of_philosophers = 0;
	args->time2die = 0;
	args->time2eat = 0;
	args->time2sleep = 0;
	args->everyone_ate = 0;
	args->flag = 0;

	i = 0;
	while(i < args->number_of_philosophers)
	{
		if (pthread_mutex_init(&args->fork[i], NULL) != 0)
		{
			perror("mutex init failed");
			exit(1);
		}
		i++;
	}
}