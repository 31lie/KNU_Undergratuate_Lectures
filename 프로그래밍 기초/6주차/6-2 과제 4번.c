/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
6주차 2차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//4번

int result(int n);


int main()
{
	printf("2020114658 이윤서 \n");

	int number;

	printf("양의 정수를 입력하세요: ");
	scanf_s("%d", &number);

	if (number < 10)
		printf("%d\n", number);
	else
		result(number);
	return 0;

}

int result(int n)
{
	if (n<10)
		printf("%d\n", n);
	else
	{
		result(n/10);
		printf("%d\n", n%10);
	}

}