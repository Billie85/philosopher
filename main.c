#include "philo.h"

void *philosopher(void *data)
{
	t_info *args;
	t_philo *philo_data;
	philo_data = (t_philo *)data;
	args = philo_data->two_way;

	while(1)
	{
		if (args->flag == 1)
		{
			//args->next->philo_dataにはidは入ってない
			printf("id is %d\n", philo_data->philo_id);
			think(philo_data);
			pick_up_fork(philo_data);
			eat(philo_data);
			put_down(philo_data);

			break;
		}
	}
}

int main(int argc ,char *argv[])
{
	struct timeval	philo_time;
	pthread_mutex_t	mutex;
	t_info		args;
	int			i;

	init(&args);
	args.number_of_philosophers = ft_atoi(argv[1]);

	i = 0;
	while(i < args.number_of_philosophers)
	{
		pthread_mutex_init(&mutex, NULL);
		args.next[i].philo_id = i + 1;
		args.next[i].two_way = &args;
		printf("Thread[%d]has started\n", i);
		if (pthread_create(&args.next[i].thread, NULL, &philosopher, &args.next[i]) != 0)
		{
			perror("Faild to create thread");
			return 1;
		}
		i++;
	}
	args.flag = 1;
	printf("----------finish make pthread----------\n");

	i = 0;
	while(i < args.number_of_philosophers)
	{
		//printf("Thread[%d]has finished\n", i);
		if (pthread_join(args.next[i].thread, NULL) != 0)
		{
			return 2;
		}
		i++;
	}
		pthread_mutex_destroy(&mutex);
		return (0);
}
//10ms変ってくる
//msについて調べる