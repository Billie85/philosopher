#include "../philo.h"

void	eat(t_philo *philo_data)
{
	philo_data->time_last_meal = get_time();
	printf("Philosopher %ld will eat for %ld seconds\n", philo_data->two_way->number_of_philosophers, philo_data->time_last_meal);
	sleep(philo_data->time_last_meal);
}