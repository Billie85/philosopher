#include "philo.h"

void	think(t_philo *philo_data)
{
	int sleeptime;

	sleeptime = rand() % 3 + 1;//gettime();
	sleep(sleeptime);
}