/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
4주차 2차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//1번

#define MAX 5


int main()
{
	for (int i = 1 ; i <= MAX ; i++)
	{
		for (int m = MAX; m >= i; m--)
		{
			printf("%d", m);
		}
		printf("\n");

	}

	return 0;
}

