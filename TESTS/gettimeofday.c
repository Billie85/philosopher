//gettimeofdayは時刻とタイムゾーンを取得または設定する。
//gettimeofday() と settimeofday()
//は成功すると 0 を返し、失敗した場合は -1 を返す
//c言語でコードブロック内の経過時間を計算するために、gettimeofdayを使う。


#include <sys/time.h>
#include <stdio.h>

//int gettimeofday(struct timeval *tv, struct timezone *tz);
int main (void)
{
	struct timeval start;
	struct timeval end;
	int	i;

	gettimeofday(&start, NULL);
	i = 0;
	while(i < NULL)
	{
		i++;
	}
	printf("%d\n", gettimeofday(&end, NULL));