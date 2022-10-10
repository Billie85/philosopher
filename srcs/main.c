#include "../philo.h"

void 	check_args(int argc, char *argv[], t_info *args)
{
	if (argv[5])
		args->number_of_time_2_eat = ft_atoi(argv[5]);
	else
		args->number_of_time_2_eat = 0;
	args->number_of_philosophers = ft_atoi(argv[1]);
	args->time2die = ft_atoi(argv[2]);
	args->time2eat = ft_atoi(argv[3]);
	args->time2sleep = ft_atoi(argv[4]);
}

void	init(t_info *args)
{
	int	i;

	args->number_of_philosophers = 0;
	args->time2die = 0;
	args->time2eat = 0;
	args->time2sleep = 0;
}

int create_pthread(char *argv[], t_info *args)
{
	int i;
	int j;
	pthread_t dead_thread;


	i = 0;
	while(i < args->number_of_philosophers)
	{
		pthread_mutex_init(&args->mutex, NULL);
		args->philo[i].philo_id = i + 1;
		args->philo[i].two_way = args;
		args->philo[i].get_time_start = get_time();
		args->philo[i].time_finish_eat = get_time();//最初に今の時刻にしてその後に最後に食事をした時間に更新していく。

		if (pthread_create(&args->philo[i].thread, NULL, &philosopher, &args->philo[i]) != 0)
		{
			perror("Faild to create thread");
			return 1;
		}
		i++;
	}
	//pthread_mutex_init(&args->dead_mutex, NULL); //ここのコメントアウトを外すとdoctor関数でセグフォします。
/* 	if (pthread_create(&dead_thread, NULL, &doctor, &args) != 0)
	{
		perror("Faild to create thread");
		return 1;
	}
	i = 0;
	if (pthread_join(dead_thread, NULL) != 0)
	{
			return 2;
	} */

	i = 0;
	while(i < args->number_of_philosophers)
	{
		if (pthread_join(args->philo[i].thread, NULL) != 0)
		{
			return 2;
		}
		i++;
	}
		pthread_mutex_destroy(&args->mutex);
		return (0);
}

int main(int argc ,char *argv[])
{
	t_info		args;

	init(&args);
	check_args(argc, argv, &args);
	create_pthread(argv, &args);
}
//10ms変ってくる
//msについて調べる