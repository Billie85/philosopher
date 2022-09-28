//gettimeofdayは時刻とタイムゾーンを取得または設定する。
//gettimeofday() と settimeofday()
//は成功すると 0 を返し、失敗した場合は -1 を返す
//c言語でコードブロック内の経過時間を計算するために、gettimeofdayを使う。

#include <sys/time.h>
#include <stdio.h>

int main(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	printf("Second 		    秒 [%ld]\n", time.tv_sec);
	printf("Microsecondsマイクロ秒 [%ld]\n", time.tv_usec);
	printf("マイクロ秒からミリ変換 [%ld]\n", (time.tv_sec * 1000) + (time.tv_usec / 1000));
	return 0;
}
/* tv_sec：秒単位の値→1秒は1000ミリ秒なので、ミリ秒に変換するには1000倍する必要あり
tv_usec：マイクロ秒単位の値→1マイクロ秒は1/1000ミリ秒なので、ミリ秒に変換するには1000で割る必要あり
両者を合算すれば、ミリ秒の値がわかる */

//出力結果
//1664112473257
//1664112839937