#include "../philo.h"

void	think(t_philo *philo_data)
{
	printf("Philosopher %ld is thinking\n", philo_data->philo_id);
}

void ft_sleep(t_philo *philo_data)
{
	printf("Philosopher %ld is sleeping\n", philo_data->philo_id);
	usleep(philo_data->two_way->time2sleep * 1000);
}

void	check_dead(t_info *args, t_philo *philo_data)
{
	int i;

	i = 0;
	pthread_mutex_lock(&args->mutex);
	printf("\n");
	printf("in the fucking function dead!!!!!!!!!!!\n");
	printf("get time ->[%ld]\n", get_time() - philo_data->time_last_meal);
	printf("args->time2die ->[%ld]\n", args->time2die);
	printf("\n");
	if (get_time() - philo_data->time_last_meal > args->time2die)
		args->is_dead = 1;
		if(args->is_dead == 1)
		{
			printf("Philo %ld is DEAD\n",philo_data->philo_id);
		}
		else
		pthread_mutex_unlock(&args->mutex);
}

long	get_time(void)
{
	struct timeval m_time;

	gettimeofday(&m_time, NULL);
	return((m_time.tv_sec * 1000) + (m_time.tv_usec / 1000));
}