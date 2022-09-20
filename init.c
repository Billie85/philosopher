#include "philo.h"

void	init(t_info *args)
{
	args->number_of_philosophers = 0;
	args->time2die = 0;
	args->time2eat = 0;
	args->time2sleep = 0;
	args->flag = 0;
}