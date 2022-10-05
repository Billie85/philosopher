#include "../philo.h"

void	finish_eating(t_philo *philo_data)
{
	pthread_mutex_unlock(&philo_data->two_way->fork[(philo_data->philo_id + 1) % philo_data->two_way->number_of_philosophers]);
	pthread_mutex_unlock(&philo_data->two_way->fork[(philo_data->two_way->number_of_philosophers + philo_data->philo_id) % philo_data->two_way->number_of_philosophers]);
}

void	eating(t_philo *philo_data)
{
	long start_time_eating;

	start_time_eating = philo_data->start_time;
	philo_data->right_fork = RIGHT_FORK;
	philo_data->left_fork = LEFT_FORK;


	if (philo_data->philo_id & 1)//奇数だったら。1,3,5,
	{
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->right_fork]);
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->left_fork]);
		printf("Philosopher %ld has taken a fork\n", philo_data->philo_id);
		printf("Philosopher %ld is eating\n", philo_data->philo_id);
		while(1)
		{
			if (get_time() - start_time_eating >= philo_data->two_way->time2eat)
			break;
			usleep(300);
		}
	}
	else//偶数だったら
	{
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->left_fork]);
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->right_fork]);
		printf("Philosopher %ld has taken a fork\n", philo_data->philo_id);
		printf("Philosopher %ld is eating\n", philo_data->philo_id);
		while(1)
		{
			if (get_time() - start_time_eating >= philo_data->two_way->time2eat)
			break;
			usleep(300);
		}
	}
}