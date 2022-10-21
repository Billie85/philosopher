#include "../philo.h"

int	print_func(t_philo *philo, char *s, long start_time)
{
	long	now;
	char	*sleep = "SLEEP";
	char	*eat = "EATING";
	char	*take_l_fork = "TAKE_LEFT_FORK";
	char	*take_r_fork = "TAKE_RIGHT_FORK";
	char	*think = "THINK";
	char	*dead = "DEAD";

	pthread_mutex_lock(&philo->two_way->print_mutex);

	if(philo->two_way->is_dead == true)
	{
		if (my_strcmp(s, sleep) == 0)
		{
			printf("%ld %ld is sleeping\n", start_time, philo->philo_id);
		}
		else if (my_strcmp(s, take_l_fork) == 0)
		{
			//pthread_mutex_lock(&philo->two_way->fork[philo->left_fork]);
			printf("%ld %ld take a fork [left %ld] \n",start_time ,philo->philo_id, philo->left_fork);
		}
		else if (my_strcmp(s, take_r_fork) == 0)
		{
			//pthread_mutex_lock(&philo->two_way->fork[philo->right_fork]);
			printf("%ld %ld take a fork [right %ld] \n",start_time ,philo->philo_id, philo->right_fork);
		}
		else if (my_strcmp(s, think) == 0)
		{
			printf("%ld %ld is thinking\n", start_time ,philo->philo_id);
		}
		else if(my_strcmp(s, eat) == 0)
		{
			printf("%ld %ld is eating\n",start_time ,philo->philo_id);
			//check_time_eat(philo);
		}
		else if (my_strcmp(s, dead) == 0)
		{
			printf("%ld %ld is dead\n",start_time ,philo->philo_id);
			philo->two_way->is_dead = false;
		}
	}
	pthread_mutex_unlock(&philo->two_way->print_mutex);
	//pthread_mutex_unlock(&philo->two_way->fork[philo->left_fork]);
	//pthread_mutex_unlock(&philo->two_way->fork[philo->right_fork]);

}
