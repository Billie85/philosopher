#include "../philo.h"

void *doctor(void *data)
{
	t_philo *philo;

	philo = data;

	while(1)
	{
		if (philo->two_way->is_dead == false)
			break ;
		if (get_time() - philo->finish_eat_time >= philo->two_way->time2die)
		{
			print_func(philo, "DEAD");
			break ;
		}
	}
}
