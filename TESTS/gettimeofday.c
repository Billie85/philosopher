//gettimeofdayは時刻とタイムゾーンを取得または設定する。
//gettimeofday() と settimeofday()
//は成功すると 0 を返し、失敗した場合は -1 を返す
//c言語でコードブロック内の経過時間を計算するために、gettimeofdayを使う。


#include <sys/time.h>
#include <stdio.h>

//int gettimeofday(struct timeval *tv, struct timezone *tz);
int main (void)
{
	struct timeval time;
	struct timeval end;
	int	i;

	gettimeofday(&time, NULL);
	printf("tv_sec is [%ld]\n", time.tv_sec);
	printf("tv_usec is [%ld]\n", time.tv_usec);
	return 0;
}