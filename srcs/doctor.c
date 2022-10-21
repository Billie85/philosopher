#include "../philo.h"

void *doctor(void *data)
{
	t_philo *philo;
	long	print_dead_time;

	philo = data;
	print_dead_time = get_time() - philo->start_time;
	while(1)
	{
		pthread_mutex_lock(&philo->two_way->mutex);
		if (philo->two_way->is_dead == false)
			break;
		if (get_time() - philo->finish_eat_time >= philo->two_way->time2die)
		{
			print_func(philo, "DEAD", print_dead_time);
			break;
		}
		pthread_mutex_unlock(&philo->two_way->mutex);
		usleep(1000);
	}
	pthread_mutex_unlock(&philo->two_way->mutex);
}
//pthread_detachを使てるから、whileを２重で回す必要がない。
//whileを無限ルール一つだけで出来る。
