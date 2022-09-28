#include "../philo.h"

void *philosopher(void *data)
{
	t_info *args;
	t_philo *philo_data;
	philo_data = (t_philo *)data;
	args = philo_data->two_way;

	// == 0
	while(!(args->is_dead))
	{
			//args->next->philo_dataにはidは入ってない
			printf("id is %d\n", philo_data->philo_id);
			think(philo_data);
			pick_up_fork(philo_data);
			eat(philo_data);
			put_down(philo_data);
	}
}