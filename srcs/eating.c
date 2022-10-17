#include "../philo.h"

/* void	finish_eating(t_philo *philo_data)
{
	philo_data->finish_eat_time = get_time() - philo_data->start_time;
	pthread_mutex_unlock(&philo_data->two_way->fork[philo_data->left_fork]);
	pthread_mutex_unlock(&philo_data->two_way->fork[philo_data->right_fork]);
	pthread_mutex_unlock(&philo_data->two_way->fork[(philo_data->philo_id + 1) % philo_data->two_way->number_of_philosophers]);
	pthread_mutex_unlock(&philo_data->two_way->fork[(philo_data->two_way->number_of_philosophers + philo_data->philo_id) % philo_data->two_way->number_of_philosophers]);
} */


void	sleep_to_time(size_t time)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(10);
}

bool	eating(t_philo *philo_data)
{
	long print_eat_time;
	long time_eating_now;

	if (philo_data->two_way->is_dead)
		return (false);
	time_eating_now = get_time();
	print_eat_time = get_time() - philo_data->start_time;
	if (philo_data->two_way->is_dead)
		return (false);
	pthread_mutex_lock(&philo_data->two_way->mutex);
	printf("%ld %ld is eating\n",print_eat_time ,philo_data->philo_id);
	pthread_mutex_unlock(&philo_data->two_way->mutex);

	philo_data->finish_eat_time = get_time() - philo_data->start_time;
		while(1)
	{
		if (get_time() - time_eating_now >= philo_data->two_way->time2eat)
			break;
		precise_sleep(philo_data->two_way->time2sleep);
	}
	pthread_mutex_unlock(&philo_data->two_way->fork[philo_data->left_fork]);
	pthread_mutex_unlock(&philo_data->two_way->fork[philo_data->right_fork]);
}

bool	taking_fork(t_philo *philo_data)
{
	long print_taking_time;
	long time_taking_now;

	philo_data->right_fork = RIGHT_FORK;
	philo_data->left_fork = LEFT_FORK;

	time_taking_now = get_time();
	print_taking_time = get_time() - philo_data->start_time;
	if (philo_data->two_way->is_dead)
		return (false);
	pthread_mutex_lock(&philo_data->two_way->fork[philo_data->left_fork]);
	printf("%ld %ld take a fork [left %ld] \n",print_taking_time ,philo_data->philo_id, philo_data->left_fork);
	pthread_mutex_lock(&philo_data->two_way->fork[philo_data->right_fork]);
	printf("%ld %ld take a fork [right %ld] \n",print_taking_time ,philo_data->philo_id, philo_data->right_fork);
}
