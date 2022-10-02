#include "../philo.h"

void	think(t_philo *philo_data)
{
	printf("Philosopher %ld is thinking\n", philo_data->philo_id);
}

void ft_sleep(t_philo *philo_data)
{
	int time;

	printf("Philosopher %ld is sleeping\n", philo_data->philo_id);
	time = get_time();
	usleep(philo_data->two_way->time2sleep * 1000 - 14000);
	//while((get_time() - time) < philo_data->two_way->time2sleep);
}

void	check_dead(t_info *args, t_philo *philo_data)
{
	int i;

	i = 0;
	pthread_mutex_lock(&args->mutex);
	//printf("get time ->[%ld]\n", get_time() - args->philo_next->time_last_meal);
	//printf("time last meal ->[%ld]\n", philo_data->time_last_meal);
	if (get_time() - philo_data->time_last_meal > args->time2die)
		args->is_dead = 1;
	pthread_mutex_unlock(&args->mutex);
}

//ミリ秒にする必要がある。
long	get_time(void)
{
	struct timeval m_time;

	gettimeofday(&m_time, NULL);
	return((m_time.tv_sec * 1000) + (m_time.tv_usec / 1000));
}