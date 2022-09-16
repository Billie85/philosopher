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
	//int	i;
	
	i++;
/* 	while(i < 100000)
	{
		i++;
	} */
}

int main(int argc ,char *argv[])
{
	pthread_t	philo, philo2;

	//printf("argc is %d\n", argc);
	//printf("argv is %s\n", argv[1]);
	//while(i < 4)
	//{
		if (pthread_create(&philo, NULL, &hoge, NULL) != 0)
			return 1;
		if (pthread_create(&philo2, NULL, &hoge, NULL) != 0)
			return 2;
		if (pthread_join(philo, NULL) != 0)
			return 3;
		if (pthread_join(philo2, NULL) != 0)
			return 4;
		printf("Number %d\n", i);
		//i++;
	//}
	return (0);
}