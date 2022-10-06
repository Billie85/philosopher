#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <stdint.h>
#include "./libft/libft.h"

#define LEFT_FORK (philo_data->philo_id + philo_data->two_way->number_of_philosophers) % philo_data->two_way->number_of_philosophers;
#define RIGHT_FORK (philo_data->philo_id + 1) % philo_data->two_way->number_of_philosophers;

typedef struct s_info t_info;

typedef struct s_philo
{
	time_t			get_time_start;
	time_t			start_time;
	size_t				right_fork;
	size_t				left_fork;
	size_t				philo_id;
	pthread_t		thread;
	pthread_t		t_monitor;
	t_info			*two_way;//双方向
} t_philo;

typedef struct s_info
{
	size_t		flag;
	size_t		is_dead;
	pthread_mutex_t	mutex;
	size_t		number_of_philosophers;
	size_t		time2die;
	size_t		time2eat;
	size_t		time2sleep;
	size_t		number_of_time_2_eat;
	pthread_mutex_t fork[200];
	t_philo	philo_next[200];
} t_info;


void 	check_args(int argc, char *argv[], t_info *args);
int create_pthread(char *argv[], t_info *args);
void	init(t_info *args);
void	eating(t_philo *philo_data);
void	check_dead(t_info *args, t_philo *philo_data);
void *philosopher(void *data);
void	think(t_philo *philo_data);
void	pick_up_fork(t_philo *philo_data);
void	eat(t_philo *philo_data);
void	finish_eating(t_philo *philo_data);
long	get_time(void);
void ft_sleep(t_philo *philo_data);