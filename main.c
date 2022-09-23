#include "philo.h"

int max = 0;
pthread_mutex_t mutex;

void	put_down(t_philo *philo_data)
{
	printf("Philosopher %d will put down her chopsticks\n", philo_data->two_way->number_of_philosophers);
	pthread_mutex_unlock(&philo_data->two_way->fork[(philo_data->two_way->number_of_philosophers + 1) % philo_data->philo_id]);
	pthread_mutex_unlock(&philo_data->two_way->fork[(philo_data->two_way->number_of_philosophers + philo_data->philo_id) % philo_data->philo_id]);
}

void	eat(t_philo *philo_data)
{
	int	eat_time;
	eat_time = rand() % 3 + 1;
	printf("Philosopher %d will eat for %d seconds\n", philo_data->two_way->number_of_philosophers, eat_time);
	sleep(eat_time);
}

void	pick_up_fork(t_philo *philo_data)
{
	philo_data->right_fork = (philo_data->two_way->number_of_philosophers + 1) % philo_data->philo_id;
	philo_data->left_fork = (philo_data->philo_id + philo_data->two_way->number_of_philosophers) % philo_data->philo_id;

	//入ってきたphiloのidが基数か偶数かによって処理が変わってくる。
	if (philo_data->philo_id & 1)//奇数だったら。1,3,5,
	{
		printf("Philosopher %d is waiting to pick up right fork %d\n", philo_data->philo_id, philo_data->right_fork);
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->right_fork]);
		printf("Philosopher %d picked up right fork %d\n", philo_data->philo_id, philo_data->right_fork);
		printf("Philosopher %d is waiting to pick up left fork %d\n", philo_data->philo_id, philo_data->left_fork);
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->left_fork]);
		printf("Philosopher %d picked up left fork %d\n", philo_data->philo_id, philo_data->left_fork);
	}
	else//偶数だったら
	{
		printf("Philosopher %d is waiting to pick up left fork %d\n", philo_data->philo_id, philo_data->left_fork);
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->left_fork]);
		printf("Philosopher %d picked up left fork %d\n", philo_data->philo_id, philo_data->left_fork);
		printf("Philosopher %d is waiting to pick up right fork %d\n", philo_data->philo_id, philo_data->right_fork);
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->right_fork]);
		printf("Philosopher %d picked up right fork %d\n", philo_data->philo_id, philo_data->right_fork);
	}
}

void	thinking(t_philo *philo_data)
{
	int sleeptime;

	sleeptime = rand() % 3 + 1;//gettime();
	sleep(sleeptime);
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