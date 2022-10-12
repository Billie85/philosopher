#include "../philo.h"

void	think(t_philo *philo_data)
{
	long start_time_thinking;
	long time_sleep_now;

	/* if (philo_data->two_way->is_dead)
	{
		printf("think function \n");
		return ;
	} */
	pthread_mutex_lock(&philo_data->two_way->mutex);
	start_time_thinking = get_time() - philo_data->start_time;
	printf("%ld %ld is thinking\n",start_time_thinking ,philo_data->philo_id);
	pthread_mutex_unlock(&philo_data->two_way->mutex);
}

void ft_sleep(t_philo *philo_data)
{
	long print_time_sleep;
	long time_sleep_now;

	/* if (philo_data->two_way->is_dead)
	{
		printf("sleep function \n");
		return ;
	} */
	time_sleep_now = get_time();
	print_time_sleep = get_time() - philo_data->start_time;//出力するための時間
	printf("%ld %ld is sleeping\n", print_time_sleep , philo_data->philo_id);
  while (1)
  {
    if (get_time() - time_sleep_now >= philo_data->two_way->time2sleep)
		break ;
	  precise_sleep(philo_data->two_way->time2sleep);
  }
}

long	get_time(void)
{
	struct timeval m_time;

	gettimeofday(&m_time, NULL);
	return((m_time.tv_sec * 1000) + (m_time.tv_usec / 1000));
}