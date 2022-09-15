#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void *hoge()
{
	write(0, "Hi\n", 3);
}

int main(int argc ,char *argv[])
{
	pthread_t	th1;
	int			data = 100;

	pthread_create(&th1, NULL, &hoge, NULL);
	//sleep(3);
	pthread_join(th1, NULL);
	return (0);
}