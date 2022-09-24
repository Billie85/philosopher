#include "philo.h"

void	put_down(t_philo *philo_data)
{
	printf("Philosopher %d will put down her chopsticks\n", philo_data->philo_id);
	pthread_mutex_unlock(&philo_data->two_way->fork[(philo_data->philo_id + 1) % philo_data->two_way->number_of_philosophers]);
	pthread_mutex_unlock(&philo_data->two_way->fork[(philo_data->two_way->number_of_philosophers + philo_data->philo_id) % philo_data->two_way->number_of_philosophers]);
}