#include "../philo.h"

void	pick_up_fork(t_philo *philo_data)
{
	//入ってきたphiloのidが基数か偶数かによってforkの順番や配置すべてが変わってくる。
	philo_data->right_fork = RIGHT_FORK;
	philo_data->left_fork = LEFT_FORK;

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