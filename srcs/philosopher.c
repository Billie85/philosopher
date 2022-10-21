#include "../philo.h"

void *philosopher(void *data)
{
	t_info *args;
	t_philo *philo_data;
	pthread_t	doctor_thread;
	philo_data = data;
	args = philo_data->two_way;

	if (pthread_create(&doctor_thread, NULL, doctor, philo_data) != 0)
	   error_message("Faild to create thread");
	   pthread_detach(doctor_thread);
	if (philo_data->philo_id % 2 == 0)
		usleep(philo_data->two_way->time2eat * 1000);
	while(1)
	{
		taking_fork(philo_data);
		eating(philo_data);
		ft_sleep(philo_data);
		think(philo_data);
	}
}
