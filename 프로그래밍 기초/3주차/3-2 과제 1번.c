/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
3주차 2차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//1번

int main()
{
	double cm;

	printf("센티미터(cm)를 소수로 입력하시오: ");
	scanf_s("%lf", &cm);

	double feet = cm * 30.48;

	printf("%.3lf feet 입니다.",feet);

	return 0;
}