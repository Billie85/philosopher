#include "../philo.h"
//ウェイターを使わない分皆が食べたかどうかと死んでいないかどうかの確認が必要になる。

void check_dead(t_info *args)
{
	int i;

	i = 0;
	while(i < args->number_of_philosophers && args->is_dead == 0)
	{
		pthread_mutex_lock(&args->mutex);
		if ((get_time() - args->philo_next[i].time_last_meal) > args->time2die)
		args->is_dead = 1;
		pthread_mutex_unlock(&args->mutex);
		usleep(100);
	}
}

int main(int argc ,char *argv[])
{
	struct timeval	philo_time;
	//pthread_mutex_t	mutex;
	t_info		args;
	int			i;
	int			j;

	init(&args);
	args.number_of_philosophers = ft_atoi(argv[1]);
	args.time2die = ft_atoi(argv[2]);
	//args.time2eat = ft_atoi(argv[3]);
	//args.time2sleep = ft_atoi(argv[4]);
	
	//もしも哲学者がtime to dieの時間で食べ始めなかったら死ぬ
	args.philo_next->start_time = get_time();
	printf("start time is [%ld]\n", args.philo_next->start_time);
	i = 0;
	while(i < args.number_of_philosophers)
	{
		pthread_mutex_init(&args.mutex, NULL);
		args.philo_next[i].philo_id = i + 1;
		args.philo_next[i].two_way = &args;
		printf("Thread[%d]has started\n", i);
		if (pthread_create(&args.philo_next[i].thread, NULL, &philosopher, &args.philo_next[i]) != 0)
		{
			perror("Faild to create thread");
			return 1;
		}
		pthread_mutex_lock(&args.mutex);
		args.philo_next[i].time_last_meal = get_time();
		printf("Philos [No.%d] ->last meat time is [%ld]\n", args.philo_next[i].philo_id, args.philo_next[i].time_last_meal);
		pthread_mutex_unlock(&args.mutex);
		i++;
	}
	//args.flag = 1;
	check_dead(&args);
	if (args.is_dead)
		exit;
	printf("----------finish make pthread----------\n");

	i = 0;
	while(i < args.number_of_philosophers)
	{
		//printf("Thread[%d]has finished\n", i);
		if (pthread_join(args.philo_next[i].thread, NULL) != 0)
		{
			return 2;
		}
		i++;
	}
		pthread_mutex_destroy(&args.mutex);
		return (0);
}
//10ms変ってくる
//msについて調べる