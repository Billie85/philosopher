#include "../philo.h"

void *philosopher(void *data)
{
	t_info *args;
	t_philo *philo_data;
	philo_data = (t_philo *)data;
	args = philo_data->two_way;

	while(1)
	{
		think(philo_data);
		eating(philo_data);
		finish_eating(philo_data);
		ft_sleep(philo_data);
		usleep(500);
		philo_data->time_last_meal = get_time();//ここで最後の食事を記録してあげる。
		check_dead(args, philo_data);
		if(args->is_dead == 1)
		{
			printf("Philo %ld is DEAD %ld\n",philo_data->philo_id , args->is_dead);
			break;
		}
	}
}