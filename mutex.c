#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

void *hoge()
{
	printf("eating\n");
	sleep(3);
	printf("sleeping\n");
	sleep(3);
	printf("dead\n");
}

int main(int argc ,char *argv[])
{
	pthread_t	philo1;
	pthread_t	philo2;
	pthread_t	philo3;
	pthread_t	philo4;
	pthread_t	philo5;

	pthread_create(&philo1, NULL, &hoge, NULL);
	pthread_create(&philo2, NULL, &hoge, NULL);
	pthread_create(&philo3, NULL, &hoge, NULL);
	pthread_create(&philo4, NULL, &hoge, NULL);
	pthread_create(&philo5, NULL, &hoge, NULL);
	pthread_join(philo1, NULL);
	pthread_join(philo2, NULL);
	pthread_join(philo3, NULL);
	pthread_join(philo4, NULL);
	pthread_join(philo5, NULL);
	return (0);
}