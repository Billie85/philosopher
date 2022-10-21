#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <stdint.h>
#include <stdbool.h>

#define LEFT_FORK (philo->philo_id -1);
#define RIGHT_FORK (philo->philo_id);
#define BACK        "\033[0m"
#define RED			"\033[0;31m"
#define YELLOW		"\033[1;33m]" 
#define ORANGE		"\033[0;33m"
#define GREEN		"\033[0;32m"
#define CLAN		"\033[0;36m"
#define PURPLE		"\033[1;35m"


typedef struct s_info t_info;

typedef struct s_philo
{
	size_t			count_eat;
	time_t			finish_eat_time;
	time_t			start_time;
	size_t			right_fork;
	size_t			left_fork;
	size_t			philo_id;
	t_info			*two_way;
	pthread_t		thread;
} t_philo;

typedef struct s_info
{
	bool		is_dead;
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


bool	taking_fork(t_philo *philo_data);
void 	check_args(int argc, char *argv[], t_info *args);
int create_pthread(char *argv[], t_info *args);
void	init(t_info *args);
bool	eating(t_philo *philo_data);
void	check_dead(t_info *args, t_philo *philo_data);
void *philosopher(void *data);
bool	think(t_philo *philo_data);
void	pick_up_fork(t_philo *philo_data);
bool	eat(t_philo *philo_data);
bool	finish_eating(t_philo *philo_data);
long	get_time(void);
bool ft_sleep(t_philo *philo_data);
void    precise_sleep(size_t sleep_time);
void *doctor(void *data);
int	ft_atoi(const char *str);
void error_message(const char *s);
int	print_func(t_philo *philo, char *s, long start_time);
int	my_strcmp(char *s, char *s1);
void	check_time_eat(t_philo *philo_data);