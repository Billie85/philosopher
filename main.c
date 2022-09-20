#include "philo.h"

int max = 0;
pthread_mutex_t mutex;

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
			//think
			//take_fork(L)
			//take_fork(R)
			//eat
			//put_fork(R)
			//put_fork(L)
			break;
		}
	}
}

int main(int argc ,char *argv[])
{
	pthread_mutex_t	mutex;
	t_info		t_args;
	int			i;

	init(&t_args);
	t_args.number_of_philosophers = ft_atoi(argv[1]);
	//t_args.time2die = ft_atoi(argv[2]);
	//t_args.time2eat = ft_atoi(argv[3]);
	//t_args.time2sleep = ft_atoi(argv[4]);

	pthread_mutex_init(&mutex, NULL);
	i = 0;
	while(i < t_args.number_of_philosophers)
	{
		t_args.next[i].philo_id = i;
		t_args.next[i].two_way = &t_args;
		printf("Thread[%d]has started\n", i);
		if (pthread_create(&t_args.next[i].philo_thread, NULL, &philosopher, &t_args.next[i]) != 0)
		{
			perror("Faild to create thread");
			return 1;
		}
		i++;
	}
	t_args.flag = 1;
	printf("finish make pthread");

	i = 0;
	while(i < t_args.number_of_philosophers)
	{
		printf("Thread[%d]has finished\n", i);
		if (pthread_join(t_args.next[i].philo_thread, NULL) != 0)
		{
			return 2;
		}
		i++;
	}
		pthread_mutex_destroy(&mutex);
		return (0);
}