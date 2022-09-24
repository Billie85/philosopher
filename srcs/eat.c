#include "../philo.h"

void	eat(t_philo *philo_data)
{
	int	eat_time;
	eat_time = rand() % 3 + 1;
	printf("Philosopher %d will eat for %d seconds\n", philo_data->two_way->number_of_philosophers, eat_time);
	sleep(eat_time);
}