#include "../philo.h"

bool	eating(t_philo *philo)
{
	print_func(philo, "EATING");
	precise_sleep(philo->two_way->time2sleep);
	pthread_mutex_unlock(&philo->two_way->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->two_way->fork[philo->right_fork]);
}

bool	taking_fork(t_philo *philo)
{
	
	philo->right_fork = RIGHT_FORK;
	philo->left_fork = LEFT_FORK;
	if (philo->right_fork == philo->two_way->number_of_philosophers)
		philo->right_fork = 0;
	
		pthread_mutex_lock(&philo->two_way->fork[philo->left_fork]);
		print_func(philo, "TAKE_LEFT_FORK");
		pthread_mutex_lock(&philo->two_way->fork[philo->right_fork]);
		print_func(philo, "TAKE_RIGHT_FORK");
		
}
