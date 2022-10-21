#include "../philo.h"

bool	eating(t_philo *philo)
{
	long print_eat_time;

	print_eat_time = get_time() - philo->start_time;
	print_func(philo, "EATING", print_eat_time);

	philo->finish_eat_time = get_time();
	precise_sleep(philo->two_way->time2sleep);
	pthread_mutex_unlock(&philo->two_way->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->two_way->fork[philo->right_fork]);
}

bool	taking_fork(t_philo *philo)
{
	long print_taking_time;
	
	philo->right_fork = RIGHT_FORK;
	philo->left_fork = LEFT_FORK;
	if (philo->right_fork == philo->two_way->number_of_philosophers)
		philo->right_fork = 0;
		
		print_taking_time = get_time() - philo->start_time;
		pthread_mutex_lock(&philo->two_way->fork[philo->left_fork]);
		print_func(philo, "TAKE_LEFT_FORK", print_taking_time);
		pthread_mutex_lock(&philo->two_way->fork[philo->right_fork]);
		print_func(philo, "TAKE_RIGHT_FORK", print_taking_time);
}
