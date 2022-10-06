#include "../philo.h"

void *philosopher(void *data)
{
	int i;
	int j;
	t_info *args;
	t_philo *philo_data;
	philo_data = (t_philo *)data;
	args = philo_data->two_way;

//	i = 0;
	j = 0;
	while(1)
	{
			eating(philo_data);
			finish_eating(philo_data);
			ft_sleep(philo_data);
			think(philo_data);
			//philo_data->start_time = get_time();
			check_dead(args, philo_data);
			//usleep(100);
	}
}