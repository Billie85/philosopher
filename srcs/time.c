#include "../philo.h"

//ミリ秒にする必要がある。
long	get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}