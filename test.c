#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	char str[10] = "THINK";
	char str1[10] = "THINKa";

	if (strcmp(str, str1) == 0)
	//if (str == str1)
		printf("YES\n");
		else
		printf("NO\n");
}