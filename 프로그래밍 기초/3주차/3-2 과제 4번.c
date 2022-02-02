/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
3주차 2차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//4번


int main()
{
	int x, y, z;

	printf("세 수를 입력하시오: ");
	scanf_s("%d%d%d", &x, &y, &z);

	int max = x > y ? (x > z ? x : z) : (y > z ? y : z);

	printf("가장 큰 수는 %d입니다.", max);

	return 0;
}
