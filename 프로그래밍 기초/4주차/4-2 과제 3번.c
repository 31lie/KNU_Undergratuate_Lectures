/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
4주차 2차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//3번

#define MAX 10000

int main()
{
	int sum = 0; 
	int n = 1;

	while (sum <= MAX)
	{
		if ((sum + n) > MAX)
		{
			printf("가장 큰 합: %d, 그 때의 n값: %d", sum, n);
		}
		sum = sum + n;
		n++;
		
	}

	return 0;
}