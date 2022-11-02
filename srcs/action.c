#include "../philo.h"

void	check_time_eat(t_philo *philo)
{
	

	philo->finish_eat_time = get_time();
	philo->count_eat++;

	if (philo->count_eat == philo->two_way->number_of_time_2_eat)
	{
		if (philo->philo_id == philo->two_way->number_of_philosophers -1)
			philo->two_way->is_dead = false;
	}
}

bool	think(t_philo *philo_data)
{
	print_func(philo_data, "THINK");
}

bool ft_sleep(t_philo *philo_data)
{
	//print_time_sleep = get_time() - philo_data->start_time;
	print_func(philo_data, "SLEEP");
	precise_sleep(philo_data->two_way->time2sleep);
}

long	get_time(void)
{
	struct timeval m_time;

	gettimeofday(&m_time, NULL);
	return((m_time.tv_sec * 1000) + (m_time.tv_usec / 1000));
}
