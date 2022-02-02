/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
3주차 2차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//2번


int main()
{
	int month;
	printf("달을 입력하시오: ");
	scanf_s("%d", &month);
	
	month >= 6 ? printf("하반기입니다.") : printf("상반기입니다.");

	return 0;
}
