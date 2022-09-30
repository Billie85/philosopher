#include "../philo.h"
//ウェイターを使わない分皆が食べたかどうかと死んでいないかどうかの確認が必要になる。

int main(int argc ,char *argv[])
{
	struct timeval	philo_time;
	t_info		args;
	int			i;
	int			j;

	init(&args);
	args.number_of_philosophers = ft_atoi(argv[1]);
	args.time2die = ft_atoi(argv[2]);
	args.time2eat = ft_atoi(argv[3]);
	args.time2sleep = ft_atoi(argv[4]);

	i = 0;
	while(i < args.number_of_philosophers)
	{
		pthread_mutex_init(&args.mutex, NULL);
		args.philo_next[i].philo_id = i + 1;
		args.philo_next[i].two_way = &args;
		args.philo_next[i].time_last_meal = get_time();
		if (pthread_create(&args.philo_next[i].thread, NULL, &philosopher, &args.philo_next[i]) != 0)
		{
			perror("Faild to create thread");
			return 1;
		}
		i++;
	}

	i = 0;
	while(i < args.number_of_philosophers)
	{
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