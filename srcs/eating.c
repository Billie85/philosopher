#include "../philo.h"

void	eating(t_philo *philo_data)
{
	//入ってきたphiloのidが基数か偶数かによってforkの順番や配置すべてが変わってくる。
	philo_data->right_fork = RIGHT_FORK;
	philo_data->left_fork = LEFT_FORK;

	if (philo_data->philo_id & 1)//奇数だったら。1,3,5,
	{
		//printf("Philosopher %ld is waiting to pick up right fork %ld\n", philo_data->philo_id, philo_data->right_fork);
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->right_fork]);
		printf("Philosopher %ld has taken a right fork %ld\n", philo_data->philo_id, philo_data->right_fork);
		//printf("Philosopher %ld is waiting to pick up left fork %ld\n", philo_data->philo_id, philo_data->left_fork);
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->left_fork]);
		printf("Philosopher %ld has taken a left fork %ld\n", philo_data->philo_id, philo_data->left_fork);
		printf("Philosopher %ld is eating", philo_data->philo_id);
		

	}
	else//偶数だったら
	{
		//printf("Philosopher %ld is waiting to pick up left fork %ld\n", philo_data->philo_id, philo_data->left_fork);
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->left_fork]);
		printf("Philosopher %ld has taken a left fork %ld\n", philo_data->philo_id, philo_data->left_fork);
		//printf("Philosopher %ld is waiting to pick up right fork %ld\n", philo_data->philo_id, philo_data->right_fork);
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->right_fork]);
		printf("Philosopher %ld has taken a right fork %ld\n", philo_data->philo_id, philo_data->right_fork);
		printf("Philosopher %ld is eating", philo_data->philo_id);
	}
}