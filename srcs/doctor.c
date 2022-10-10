#include "../philo.h"

void *doctor(void *data)
 {
	int		i;
	t_info *args;
	t_philo *philo_data;
	long	time_now;
	philo_data = (t_philo *)data;
	args = philo_data->two_way;

	printf("%ld %ld\n", args->time2die, time_now - args->philo[i].time_finish_eat);
	while(1)
	{
		i = 0;
		time_now = get_time();
		pthread_mutex_lock(&args->mutex);
		 while(i < philo_data->two_way->number_of_philosophers)//5
		 {
			printf("[%ld\n]",args->philo[i].time_finish_eat);
		 	printf("%d\n", i);
		 	fflush(stdout);
		 	if (time_now - args->philo[i].time_finish_eat > args->time2die)
		 	{
		 		printf("aaaaaaaa\n");
				//printf("//// [%ld\n]",args->philo[i].time_finish_eat);
				//rgs->is_dead = 1;//ここで死んだことを教える。
				//printf("%ld %ld is DEAD\n", philo_data->two_way->time_dead ,philo_data->philo_id);
				//return(NULL);
			}
			i++;
		}
	}
	//pthread_mutex_unlock(&args->mutex);
}