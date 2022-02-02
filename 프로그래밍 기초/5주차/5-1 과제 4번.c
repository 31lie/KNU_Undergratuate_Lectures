/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
5주차 1차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//4번


int main()
{
	double num1, num2;
	
	printf("두 실수를 입력하시오: ");
	scanf_s("%lf %lf", &num1, &num2);

	double* ptrnum1 = &num1, * ptrnum2 = &num2;

	printf("두 실수의 덧셈: %.2lf+%.2lf=%.2lf\n", *ptrnum1, *ptrnum2, *ptrnum1 + *ptrnum2);
	printf("두 실수의 뺄셈: %.2lf-%.2lf=%.2lf\n", *ptrnum1, *ptrnum2, *ptrnum1 - *ptrnum2);
	printf("두 실수의 곱셈: %.2lf*%.2lf=%.3lf\n", *ptrnum1, *ptrnum2, *ptrnum1**ptrnum2);
	printf("두 실수의 나눗셈: %.2lf/%.2lf=%.3lf", *ptrnum1, *ptrnum2, *ptrnum1 / *ptrnum2);

	return 0;
}