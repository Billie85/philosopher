#include "../philo.h"

void	finish_eating(t_philo *philo_data)
{
	//printf("Philosopher %ld finish to eat\n", philo_data->philo_id);
	//printf("Philosopher %d will put down her chopsticks\n", philo_data->philo_id);
	//philo_data->last_time_eat = last_time_eat();
	pthread_mutex_unlock(&philo_data->two_way->fork[(philo_data->philo_id + 1) % philo_data->two_way->number_of_philosophers]);
	pthread_mutex_unlock(&philo_data->two_way->fork[(philo_data->two_way->number_of_philosophers + philo_data->philo_id) % philo_data->two_way->number_of_philosophers]);
}

//usleepするタイミングがいまいちわかってない。
//哲学者が食事をするのにかかる時間。はusleepすればOK
void	eating(t_philo *philo_data)
{
	int time;
	//入ってきたphiloのidが基数か偶数かによってforkの順番や配置すべてが変わってくる。
	philo_data->right_fork = RIGHT_FORK;
	philo_data->left_fork = LEFT_FORK;

//これでミリ秒に変換になってるかも。
	time = (philo_data->two_way->time2eat * 1000);
	if (philo_data->philo_id & 1)//奇数だったら。1,3,5,
	{
		//printf("Philosopher %ld is waiting to pick up right fork %ld\n", philo_data->philo_id, philo_data->right_fork);
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->right_fork]);
		//printf("Philosopher %ld has taken a right fork %ld\n", philo_data->philo_id, philo_data->right_fork);
		//printf("Philosopher %ld is waiting to pick up left fork %ld\n", philo_data->philo_id, philo_data->left_fork);
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->left_fork]);
		printf("Philosopher %ld has taken a fork\n", philo_data->philo_id);
		//printf("Philosopher %ld has taken a left fork %ld\n", philo_data->philo_id, philo_data->left_fork);
		printf("Philosopher %ld is eating\n", philo_data->philo_id);
		usleep(time);
	}
	else//偶数だったら
	{
		//printf("Philosopher %ld is waiting to pick up left fork %ld\n", philo_data->philo_id, philo_data->left_fork);
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->left_fork]);
		//printf("Philosopher %ld has taken a left fork %ld\n", philo_data->philo_id, philo_data->left_fork);
		//printf("Philosopher %ld is waiting to pick up right fork %ld\n", philo_data->philo_id, philo_data->right_fork);
		pthread_mutex_lock(&philo_data->two_way->fork[philo_data->right_fork]);
		printf("Philosopher %ld has taken a fork\n", philo_data->philo_id);
		//printf("Philosopher %ld has taken a right fork %ld\n", philo_data->philo_id, philo_data->right_fork);
		printf("Philosopher %ld is eating\n", philo_data->philo_id);
		usleep(time);
	}
}