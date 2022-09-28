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
	time_t			start_time;
	time_t			time_last_meal;
	int				right_fork;
	int				left_fork;
	int				philo_id;
	pthread_t		thread;
	pthread_t		t_monitor;
	t_info			*two_way;//双方向
} t_philo;

typedef struct s_info
{
	int		is_dead;
	pthread_mutex_t	mutex;
	int		number_of_philosophers;
	int		time2die;
	int		time2eat;
	int		time2sleep;
	int 	everyone_ate;
	pthread_mutex_t fork[200];
	t_philo	philo_next[200];
} t_info;

void	init(t_info *args);
void *philosopher(void *data);
void	think(t_philo *philo_data);
void	pick_up_fork(t_philo *philo_data);
void	eat(t_philo *philo_data);
void	put_down(t_philo *philo_data);
long	get_time(void);