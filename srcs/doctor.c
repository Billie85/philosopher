#include "../philo.h"

void *doctor(void *data)
 {
	size_t	dead_time_now;
	size_t	print_time_dead;
	int		i;
	t_info *args;
	t_philo *philo_data;

	args = (t_info*)data;

	while(1)
	{
		i = 0;
		 while(i < args->number_of_philosophers)
		 {
			dead_time_now = get_time();
			print_time_dead = get_time() - args->philo[i].start_time;
		 	if (dead_time_now - args->philo[i].finish_eat_time > args->time2die)
		 	{
				if (args->is_dead)
					return(NULL);
				pthread_mutex_lock(&args->mutex);
				printf("%ld %ld is dead\n", print_time_dead , args->philo[i].philo_id);
				pthread_mutex_unlock(&args->mutex);
				args->is_dead = 1;
					return(NULL);
			}
			i++;
		}
	}
 }