#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <stdint.h>
#include "./libft/libft.h"

typedef struct s_rguments
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;

} t_arguments;

void	init(t_arguments *args);