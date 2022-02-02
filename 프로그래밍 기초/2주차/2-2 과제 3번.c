/***********************
컴퓨터학부 심화컴퓨터전공
2020114658 이윤서
2주차 2차시 _ 실습문제
************************/

#include <stdio.h>


//3번

#define PI 3.14

int main()
{
	double radius = 7.58;
	double area = radius * radius * PI;
	double cir = 2 * PI * radius;

	printf("원의 반지름: %f\n원의 면적: %f\n원의 둘레: %f", radius, area, cir);

	return 0;
}