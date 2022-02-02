/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
4주차 1차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//3번

int main()
{
	double x, y;
	printf("두 실수 입력: ");
	scanf_s("%lf %lf", &x, &y);

	if ((x>0) & (y>0))
		printf("%.3lf + %.3lf = %.3lf", x, y, x + y);
	else if ((x>0) & (y<=0))
		printf("%.3lf - (%.3lf) = %.3lf", x, y, x - y);
	else if ((x<=0) & (y>0))
		printf("-(%.3lf) + %.3lf = %.2lf", x, y, -x + y);
	else
		printf("-(%.3lf) - (%.3lf) = %.2lf", x, y, -x - y);

	return 0;
}