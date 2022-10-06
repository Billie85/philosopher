#include "../philo.h"

void	think(t_philo *philo_data)
{
	printf("Philosopher %ld is thinking\n", philo_data->philo_id);
}

void ft_sleep(t_philo *philo_data)
{
	long start_sleep_time;

	start_sleep_time = get_time();
	//printf("start_sleep_time is ---[%ld]---\n", start_sleep_time);
	printf("Philosopher %ld is sleeping\n", philo_data->philo_id);
  while (1)
  {
    if (get_time() - start_sleep_time >= philo_data->two_way->time2sleep)
      break ;
    //usleep(100);
  }
}

void	check_dead(t_info *args, t_philo *philo_data)
{
	int i;
	long time_last_meal;

	 time_last_meal = philo_data->start_time;

	i = 0;
	pthread_mutex_lock(&args->mutex);
	//printf("get start time ---[%ld]---\n", philo_data->get_time_start);
	//printf("the time now is [%ld]\n", get_time ());
	//printf("last time meal-----[%ld]-----\n", philo_data->start_time);
	//printf("calculation the time and last time meal -----[%ld]------\n", get_time() - philo_data->start_time);
	if (get_time() - philo_data->get_time_start > args->time2die)
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