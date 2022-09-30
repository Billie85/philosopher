#include "../philo.h"

void	check_dead(t_info *args, t_philo *philo_data)
{
	int i;

	i = 0;
	pthread_mutex_lock(&args->mutex);
	printf("get time ->[%ld]\n", get_time() - args->philo_next->time_last_meal);
	printf("time last meal ->[%ld]\n", philo_data->time_last_meal);
	if (get_time() - philo_data->time_last_meal > args->time2die)
	{
		//printf("Philosopher %ld is DEAD\n", args->philo_id);
		args->is_dead = 1;
	}
	pthread_mutex_unlock(&args->mutex);
}