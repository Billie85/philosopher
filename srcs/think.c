#include "../philo.h"

void	think(t_philo *philo_data)
{
	int sleeptime;

	sleeptime = philo_data->two_way->time2sleep;
	sleep(sleeptime);
}