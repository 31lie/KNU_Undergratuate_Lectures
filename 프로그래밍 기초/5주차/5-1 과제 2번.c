/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
5주차 1차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//2번


int main()
{
	int data1 = 10, data2 = 20;
	int sum;
	int* pd1 = &data1, * pd2 = &data2;

	*pd1 = 100;
	*pd2 = 200;
	sum = *pd1 + *pd2;

	printf("%d", sum);

	return 0;
}