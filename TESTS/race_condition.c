#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

int i = 0;

void *hoge()
{
	i++;
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
		printf("Number %d\n", i); //合計２になる。
	return (0);
}