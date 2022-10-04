#include "../philo.h"

void *philosopher(void *data)
{
	int i;
	int j;
	t_info *args;
	t_philo *philo_data;
	philo_data = (t_philo *)data;
	args = philo_data->two_way;

	i = 0;
	j = 0;
	while(1)
	{
		if (i < args->number_of_time_2_eat)
		{
			eating(philo_data);
			finish_eating(philo_data);
			ft_sleep(philo_data);
			think(philo_data);
			philo_data->time_last_meal = get_time();//ここで最後の食事を記録してあげる。
			check_dead(args, philo_data);
		}
		else if (j < args->number_of_philosophers)
		{
			think(philo_data);
			eating(philo_data);
			finish_eating(philo_data);
			ft_sleep(philo_data);
			usleep(500);
			philo_data->time_last_meal = get_time();//ここで最後の食事を記録してあげる。
			check_dead(args, philo_data);
		}
		i++;
		j++;
	}
}