#include "../philo.h"

void *philosopher(void *data)
{
	t_info *args;
	t_philo *philo_data;
	philo_data = (t_philo *)data;
	args = philo_data->two_way;

//1
	while(1)
	{
		//think(philo_data);
		eating(philo_data);
		//eat(philo_data);
		put_down(philo_data);
		philo_data->time_last_meal = get_time();//ここで最後の食事を記録してあげる。
		check_dead(args, philo_data);
		if(args->is_dead == 1)
		{
			printf("Philo %ld is dead %ld\n",philo_data->philo_id , args->is_dead);
			break;
		}
	}
}