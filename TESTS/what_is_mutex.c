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
//mutexを使うことでスレッドを同時に走らせてもアクセスすることができないから、race_conditionを防ぐことができる
	while(i < 10)//OK
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

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while(i < 4)
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