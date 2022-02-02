/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
3주차 1차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//3번

int main()
{
	double a, b;
	scanf_s("%lf", &a);
	scanf_s(" %lf", &b);
	printf("합: %lf, 평균: %lf", a + b, (a + b) / 2);

	return 0;

}