#include "../philo.h"

/* void	finish_eating(t_philo *philo_data)
{
	philo_data->finish_eat_time = get_time() - philo_data->start_time;
	pthread_mutex_unlock(&philo_data->two_way->fork[philo_data->left_fork]);
	pthread_mutex_unlock(&philo_data->two_way->fork[philo_data->right_fork]);
	pthread_mutex_unlock(&philo_data->two_way->fork[(philo_data->philo_id + 1) % philo_data->two_way->number_of_philosophers]);
	pthread_mutex_unlock(&philo_data->two_way->fork[(philo_data->two_way->number_of_philosophers + philo_data->philo_id) % philo_data->two_way->number_of_philosophers]);
} */

bool	eating(t_philo *philo_data)
{
	long print_eat_time;

	print_eat_time = get_time() - philo_data->start_time;
	print_func(philo_data, "EATING", print_eat_time);

	philo_data->finish_eat_time = get_time();
	precise_sleep(philo_data->two_way->time2sleep);
	pthread_mutex_unlock(&philo_data->two_way->fork[philo_data->left_fork]);
	pthread_mutex_unlock(&philo_data->two_way->fork[philo_data->right_fork]);
}

bool	taking_fork(t_philo *philo_data)
{
	long print_taking_time;
	
	
	philo_data->right_fork = RIGHT_FORK;
	philo_data->left_fork = LEFT_FORK;
	if (philo_data->right_fork == philo_data->two_way->number_of_philosophers)
		philo_data->right_fork = 0;
		
		print_taking_time = get_time() - philo_data->start_time;
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->left_fork]);
		print_func(philo_data, "TAKE_LEFT_FORK", print_taking_time);
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->right_fork]);
		print_func(philo_data, "TAKE_RIGHT_FORK", print_taking_time);

}
