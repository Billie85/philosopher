#include "../philo.h"

void	finish_eating(t_philo *philo_data)
{
	/* if (philo_data->two_way->is_dead)
	{
		printf("finish eat function \n");
		return ;
	} */
	philo_data->finish_eat_time = get_time() - philo_data->start_time;
	pthread_mutex_unlock(&philo_data->two_way->fork[(philo_data->philo_id + 1) % philo_data->two_way->number_of_philosophers]);
	pthread_mutex_unlock(&philo_data->two_way->fork[(philo_data->two_way->number_of_philosophers + philo_data->philo_id) % philo_data->two_way->number_of_philosophers]);
}

void	eating(t_philo *philo_data)
{
	long print_eat_time;
	long time_eating_now;

	/* if (philo_data->two_way->is_dead)
	{
		printf("eating function \n");
		return ;
	} */
	philo_data->right_fork = RIGHT_FORK;
	philo_data->left_fork = LEFT_FORK;

	if (philo_data->philo_id & 1)//奇数だったら。1,3,5,
	{
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->right_fork]);
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->left_fork]);
		time_eating_now = get_time();
		print_eat_time = get_time() - philo_data->start_time;
		printf("%ld %ld take a fork\n",print_eat_time ,philo_data->philo_id);
		printf("%ld %ld is eating\n",print_eat_time ,philo_data->philo_id);
		while(1)
		{
			if (get_time() - time_eating_now >= philo_data->two_way->time2eat)
				break;
			precise_sleep(philo_data->two_way->time2sleep);
		}
	}
	else//偶数だったら
	{
		/* if (philo_data->two_way->is_dead)
		{
			printf("else eating funtion \n");
			return ;
		} */
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->left_fork]);
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->right_fork]);
		time_eating_now = get_time();
		print_eat_time = get_time() - philo_data->start_time;
		printf("%ld %ld take a fork\n",print_eat_time ,philo_data->philo_id);
		printf("%ld %ld is eating\n",print_eat_time ,philo_data->philo_id);
		while(1)
		{
			if (get_time() - time_eating_now >= philo_data->two_way->time2eat)
			break;
			precise_sleep(philo_data->two_way->time2sleep);
		}
	}
}