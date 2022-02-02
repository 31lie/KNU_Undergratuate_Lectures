/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
6주차 2차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//2번

int add(int a, int b);
int multi(int a, int b);

int main()
{
	printf("2020114658 이윤서\n");

	int i, num1, num2;

	for (i = 0;;)
	{
		printf("두 정수를 입력하세요: ");
		scanf_s("%d %d", &num1, &num2);
		printf("합: %d, 곱: %d\n\n", add(num1, num2), multi(num1, num2));
	}
	

	return 0;
}

int add(int a, int b)
{
	return a + b;
}

int multi(int a, int b)
{
	return a * b;
}