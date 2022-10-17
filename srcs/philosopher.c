#include "../philo.h"

void *philosopher(void *data)
{
	t_info *args;
	t_philo *philo_data;
	philo_data = (t_philo *)data;
	args = philo_data->two_way;

	if (philo_data->philo_id % 2 == 0)
		usleep(philo_data->two_way->time2eat * 1000);
	while(!args->is_dead)
	{
		printf("philo_data->philo_id is [%ld]\n", philo_data->philo_id);
		(!taking_fork(philo_data));
			break;
		(!eating(philo_data));
			break;
		ft_sleep(philo_data);
		think(philo_data);
	}
}
