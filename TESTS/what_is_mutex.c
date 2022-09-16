//MUTual EXclusion（mutex）の略であり、日本語だと同期処理の方法である。
//「未使用」と「使用中」で判断し、共有資源を同時にアクセスさせない方式。
//例えば、ミューテックスが「未使用」の共有資源にアクセスすると「使用中」に変わります。
//「使用中」となっている時は、他のプログラム（タスク）がアクセスしようとしても、
//アクセスできません。このように共有資源に対して、同時アクセスを防ぐ排他制御のことを「ミューテックス」といいます。

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
	while(i < 100000000)
	{
		pthread_mutex_lock(&mutex);
		i++;
		max++;
		pthread_mutex_unlock(&mutex);
	}
}

int main(int argc ,char *argv[])
{
	pthread_t	philo, philo2;

	pthread_mutex_init(&mutex, NULL);
		if (pthread_create(&philo, NULL, &hoge, NULL) != 0)
		{
			return 1;
		}
		if (pthread_create(&philo2, NULL, &hoge, NULL) != 0)
		{
			return 2;
		}
		if (pthread_join(philo, NULL) != 0)
		{
			return 3;
		}
		if (pthread_join(philo2, NULL) != 0)
		{
			return 4;
		}
		pthread_mutex_destroy(&mutex);
		printf("Number %d\n", max);
		return (0);
}