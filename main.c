#include "philo.h"

int max = 0;
pthread_mutex_t mutex;

void	pick_up_fork(t_philo *philo_data)
{
	t_info	*fork_info;
	philo_data->right_fork = (philo_data->philo_id + 1) % philo_data->two_way->number_of_philosophers;
	philo_data->left_fork = (philo_data->philo_id + philo_data->two_way->number_of_philosophers) % philo_data->two_way->number_of_philosophers;

	printf("----------fork pair---------\n");
	printf("left fork is  [%d]\n",  philo_data->left_fork);
	printf("right fork is [%d]\n", philo_data->right_fork);

	//入ってきたphiloのidが基数か偶数かによって処理が変わってくる。
	if (philo_data->philo_id & 1)//基数だったら。
	{
		printf("Philosopher %d is waiting to pick up right fork %d\n", philo_data->philo_id, philo_data->right_fork);
		//pthread_mutex_lock(&fork_info->fork[philo_data->left_fork]);
		printf("Philosopher %d picked up right fork %d\n", philo_data->philo_id, philo_data->right_fork);

		printf("Philosopher %d is waiting to pick up left fork %d\n", philo_data->philo_id, philo_data->left_fork);
		//pthread_mutex_lock(&fork_info->fork[philo_data->right_fork]);
		printf("Philosopher %d picked up left fork %d\n", philo_data->philo_id, philo_data->left_fork);
	}
	else//偶数だったら
	{
		printf("Philosopher %d is waiting to pick up left fork %d\n", philo_data->philo_id, philo_data->left_fork);
		//pthread_mutex_lock(&fork_info->fork[philo_data->right_fork]);
		printf("Philosopher %d picked up left fork %d\n", philo_data->philo_id, philo_data->left_fork);

		printf("Philosopher %d is waiting to pick up right fork %d\n", philo_data->philo_id, philo_data->right_fork);
		//pthread_mutex_lock(&fork_info->fork[philo_data->right_fork]);
		printf("Philosopher %d picked up right fork %d\n", philo_data->philo_id, philo_data->right_fork);
	}
}

void	thinking(t_philo *philo_data)
{
	int sleeptime;

	sleeptime = rand() % 3 + 1;//gettime();
	pthread_mutex_lock(&mutex);
	printf("Philosopher %d will think for %d seconds\n", philo_data->philo_id, sleeptime);
	sleep(sleeptime);
	pthread_mutex_unlock(&mutex);
}

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
			thinking(philo_data);
			pick_up_fork(philo_data);
			//lock(mutex)
			//take_fork(L)
			//take_fork(R)
			//eat
			//put_fork(R)
			//put_fork(L)
			//unloc(mutex)
			break;
		}
	}
	
}

int main(int argc ,char *argv[])
{
	struct timeval	philo_time;
	pthread_mutex_t	mutex;
	t_info		t_args;
	int			i;

	init(&t_args);
	t_args.number_of_philosophers = ft_atoi(argv[1]);
	/* printf("argv 2 [%d]\n",t_args.time2die = ft_atoi(argv[2]));
	printf("argv 3 [%d]\n",t_args.time2eat = ft_atoi(argv[3]));
	printf("argv 4 [%d]\n",t_args.time2sleep = ft_atoi(argv[4])); */

	pthread_mutex_init(&mutex, NULL);
	i = 0;
	while(i < t_args.number_of_philosophers)
	{
		t_args.next[i].philo_id = i;
		t_args.next[i].two_way = &t_args;
		printf("Thread[%d]has started\n", i);
		if (pthread_create(&t_args.next[i].thread, NULL, &philosopher, &t_args.next[i]) != 0)
		{
			perror("Faild to create thread");
			return 1;
		}
		i++;
	}
	t_args.flag = 1;
	printf("----------finish make pthread----------\n");

	i = 0;
	while(i < t_args.number_of_philosophers)
	{
		//printf("Thread[%d]has finished\n", i);
		if (pthread_join(t_args.next[i].thread, NULL) != 0)
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