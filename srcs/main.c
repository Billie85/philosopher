#include "../philo.h"

void	allocate_memory(t_info *args)
{
	args->fork = malloc(sizeof(pthread_mutex_t) * (args->number_of_philosophers));
	if (args->fork == NULL)
		printf("Faild malloc\n");
	args->philo = malloc(sizeof(t_philo) * (args->number_of_philosophers));
	if (args->philo == NULL)
	{
		free(args->fork);
		printf("Faild malloc\n");
	}
}

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
	size_t i;
	pthread_t dead_thread;

	i = 0;

	while(i < args->number_of_philosophers)//5
	{
		pthread_mutex_init(&args->mutex, NULL);
		args->philo[i].philo_id = i + 1;
		args->philo[i].two_way = args;
		args->philo[i].start_time = get_time();
		args->philo[i].finish_eat_time = get_time();//最初に今の時刻にしてその後に最後に食事をした時間に更新していく。

		if (pthread_create(&args->philo[i].thread, NULL, &philosopher, &args->philo[i]) != 0)
			error_message("Faild to create thread");
		i++;
	}
	//pthread_createの第4引数がアドレス(&args)が渡されている状況だったから上手く構造体が渡されてなかった。
	if (pthread_create(&dead_thread, NULL, &doctor, args) != 0)
		error_message("Faild to create thread");
	i = 0;
	if (pthread_join(dead_thread, NULL) != 0)
		error_message("Faild pthread_join");

	i = 0;
	while(i < args->number_of_philosophers)
	{
		if (pthread_join(args->philo[i].thread, NULL) != 0)
			error_message("Faild pthread_join");
		i++;
	}
		if (pthread_mutex_destroy(&args->mutex) != 0)
			error_message("Faild pthread_mutex_destroy");
}

int main(int argc ,char *argv[])
{
	t_info		args;

	init(&args);
	check_args(argc, argv, &args);
	allocate_memory(&args);
	create_pthread(argv, &args);
}