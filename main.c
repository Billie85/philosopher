#include "philo.h"

int max = 0;
pthread_mutex_t mutex;

int	check_malloc(t_arguments *args)
{
	if (args == NULL)
	perror("malloc failed");
	return (0);
}

//ここでphilo達が食事を始めるプログラムを書く。
void *start_philo(void *data)
{
	int	i;
	t_arguments *args;
	args = (t_arguments *)data;

	i = 0;
	while(i < args->number_of_philosophers)
	{
		pthread_mutex_lock(&mutex);
		i++;
		pthread_mutex_unlock(&mutex);
	}
}

int main(int argc ,char *argv[])
{
	t_arguments	*args;
	pthread_t	*philo;
	int			i;

	printf("argc is %d\n", argc -1);
	printf("argv is %s\n", argv [1]);

	args = (t_arguments *)malloc(sizeof(t_arguments));
	check_malloc(args);
	init(args);
	args->number_of_philosophers = ft_atoi(argv[1]);
	philo = (pthread_t *)malloc(sizeof(pthread_t) * args->number_of_philosophers);
	if (philo == NULL)
		return (0);
	printf("number_of_philosophers is [%d]\n", args->number_of_philosophers);

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while(i < args->number_of_philosophers)
	{
		printf("Thread[%d]has started\n", i);
		if (pthread_create(&philo[i], NULL, &start_philo, NULL) != 0)
		{
			perror("Faild to create thread");
			return 1;
		}
		i++;
	}

	i = 0;
	while(i < args->number_of_philosophers)
	{
		printf("Thread[%d]has finished\n", i);
		if (pthread_join(philo[i], NULL) != 0)
		{
			return 2;
		}
		i++;
	}
		pthread_mutex_destroy(&mutex);
		printf("Total Number %d\n", max);
		return (0);
}