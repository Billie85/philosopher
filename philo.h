#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <sys/time.h>
#include <stdint.h>
#include "./libft/libft.h"

typedef struct s_info t_info;

typedef struct s_philo
{
	int				right_fork;
	int				left_fork;
	int				philo_id;
	pthread_t		philo_thread;
	t_info			*two_way;//双方向
} t_philo;

typedef struct s_info
{
	int		number_of_philosophers;
	int		time2die;
	int		time2eat;
	int		time2sleep;
	int 	flag;
	t_philo	next[200];

} t_info;

void	init(t_info *args);