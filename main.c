#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

int max = 0;
pthread_mutex_t mutex;

void *hoge()
{
	int	i;

	i = 0;
	while(i < 10)
	{
		pthread_mutex_lock(&mutex);
		i++;
		max++;
		pthread_mutex_unlock(&mutex);
	}
}

int main(int argc ,char *argv[])
{
	pthread_t	philo[4];
	int			i;

	printf("argc is %d\n", argc -1);
	printf("argv is %s\n", argv [1]);

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while(i < argc -1)
	{
		if (pthread_create(&philo[i], NULL, &hoge, NULL) != 0)
		{
			perror("Faild to create thread");
			return 1;
		}
		printf("Thread[%d]has started\n", i);
		if (pthread_join(philo[i], NULL) != 0)
		{
			return 2;
		}
		printf("Thread[%d]has finished\n", i);
		i++;
	}
		pthread_mutex_destroy(&mutex);
		printf("Number %d\n", max);
		return (0);
}