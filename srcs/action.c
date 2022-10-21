#include "../philo.h"

void	check_time_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->two_way->mutex);
	philo->count_eat++;
	if (philo->count_eat == philo->two_way->number_of_time_2_eat)
	{
		philo->two_way->is_dead = false;
	}
	pthread_mutex_unlock(&philo->two_way->mutex);
}

bool	think(t_philo *philo_data)
{
	long start_time_thinking;
	long time_sleep_now;

	start_time_thinking = get_time() - philo_data->start_time;
	print_func(philo_data, "THINK", start_time_thinking);
}

bool ft_sleep(t_philo *philo_data)
{
	long print_time_sleep;
	long time_sleep_now;

	print_time_sleep = get_time() - philo_data->start_time;
	print_func(philo_data, "SLEEP", print_time_sleep);
	precise_sleep(philo_data->two_way->time2sleep);
}

long	get_time(void)
{
	struct timeval m_time;

	gettimeofday(&m_time, NULL);
	return((m_time.tv_sec * 1000) + (m_time.tv_usec / 1000));
}
