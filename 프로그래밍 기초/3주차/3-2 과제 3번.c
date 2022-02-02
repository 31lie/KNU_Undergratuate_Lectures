/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
3주차 2차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//3번


int main()
{
	int x, y;
	printf("두 수를 입력하시오: ");
	scanf_s("%d%d", &x, &y);
	int max = x > y ? x : y;
	int min = x > y ? y : x;

	printf("몫: %d\n", max/min);
	printf("나머지: %d", max % min);

	return 0;
}