#include "../philo.h"

void *philosopher(void *data)
{
	t_info *args;
	t_philo *philo_data;
	philo_data = (t_philo *)data;
	args = philo_data->two_way;

	while(1)
	{
		eating(philo_data);
		finish_eating(philo_data);
		ft_sleep(philo_data);
		think(philo_data);
		//check_dead(args, philo_data);
	}
}