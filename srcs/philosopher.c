#include "../philo.h"

void	*monitor_detach(t_philo *philo)
{
	pthread_t	doctor_thread;
	if (pthread_create(&doctor_thread, NULL, doctor, philo) != 0)
	   printf("Faild to create thread\n");
	   pthread_detach(doctor_thread);
}

void *philosopher(void *data)
{
	t_philo *philo;

	philo = data;
	monitor_detach(philo);
	if (philo->philo_id % 2 == 0)
		usleep(philo->two_way->time2eat * 1000);
	while(1)
	{
		if (philo->two_way->is_dead == false)
			break;
		taking_fork(philo);
		eating(philo);
		ft_sleep(philo);
		think(philo);
	}
}
