/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
4주차 2차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//4번


int main()
{
	int num;
	int digit;

	printf("정수를 입력하시오: ");
	scanf_s("%d", &num);

	while (num!=0)
	{
		digit = num % 10;
		printf("%d", digit);
		num = num / 10;

	}
	return 0;
	}