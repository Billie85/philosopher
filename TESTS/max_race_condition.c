#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

int max = 0;

void *hoge()
{
	int	i;

	i = 0;
//19999をを超えてしまうとrace_conditionが起こってしまう。
	while(i < 19999)
	{
		i++;
		max++;
	}
}

int main(int argc ,char *argv[])
{
	pthread_t	philo, philo2;
	
		if (pthread_create(&philo, NULL, &hoge, NULL) != 0)
			return 1;
		if (pthread_create(&philo2, NULL, &hoge, NULL) != 0)
			return 2;
		if (pthread_join(philo, NULL) != 0)
			return 3;
		if (pthread_join(philo2, NULL) != 0)
			return 4;
		printf("Number %d\n", max);
	return (0);
}