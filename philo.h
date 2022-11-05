#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <stdint.h>

#define LEFT_FORK (philo->philo_id -1);
#define RIGHT_FORK (philo->philo_id);
#define BACK       	"\x1b[0m"
#define RED			"\033[0;31m"
#define YELLOW		"\033[1;33m]" 
#define ORANGE		"\033[0;33m"
#define GREEN		"\033[0;32m"
#define CLAN		"\033[0;36m"
#define PURPLE		"\033[1;35m"
#define ONE_PHILO 1
#define DIE 0
#define NOT_DIE 1

typedef struct s_info t_info;

typedef struct s_philo
{
	size_t			count_eat;
	size_t			total_eat;
	time_t			finish_eat_time;
	size_t			start_time;
	size_t			right_fork;
	size_t			left_fork;
	size_t			philo_id;
	t_info			*two_way;
	pthread_t		thread;
} t_philo;

typedef struct s_info
{
	int		is_dead;
	size_t		number_of_philosophers;
	size_t		time2die;
	size_t		time2eat;
	size_t		time2sleep;
	size_t		number_of_time_2_eat;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_mutex;
	t_philo	*philo;
} t_info;

int	taking_fork(t_philo *philo_data);
void 	check_args(char *argv[], t_info *args);
int create_pthread(t_info *args);
void	init(t_info *args);
int	eating(t_philo *philo_data);
void	check_dead(t_info *args, t_philo *philo_data);
void *philosopher(void *data);
int	think(t_philo *philo_data);
void	pick_up_fork(t_philo *philo_data);
int	eat(t_philo *philo_data);
int	finish_eating(t_philo *philo_data);
size_t	get_time(void);
int ft_sleep(t_philo *philo_data);
void    precise_sleep(size_t sleep_time);
void *doctor(void *data);
int	ft_atoi(const char *str);
void	destroy_pthread(t_info *args);
int	print_func(t_philo *philo, char *s);
int	my_strcmp(char *s, char *s1);
void	check_time_eat(t_philo *philo_data);
void	join(t_info *args);