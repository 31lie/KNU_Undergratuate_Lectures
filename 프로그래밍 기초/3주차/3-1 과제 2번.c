/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
3주차 1차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//2번

int main()
{
	double f_degree;
	scanf_s("%lf",&f_degree);
	double c_degree = 5.0 / 9.0 * (f_degree - 32.0);
	printf("섭씨 온도: %.4lf", c_degree);

	return 0;
}