#include "../philo.h"

void	*detach(t_philo *philo)
{
	pthread_t	doctor_thread;
	if (pthread_create(&doctor_thread, NULL, doctor, philo) != 0)
	   error_message("Faild to create thread");
	   pthread_detach(doctor_thread);
}

void *philosopher(void *data)
{
	t_philo *philo;
	philo = data;

	detach(philo);
	if (philo->philo_id % 2 == 0)
		usleep(philo->two_way->time2eat * 1000);
	while(1)
	{
		taking_fork(philo);
		eating(philo);
		ft_sleep(philo);
		think(philo);
	}
}
