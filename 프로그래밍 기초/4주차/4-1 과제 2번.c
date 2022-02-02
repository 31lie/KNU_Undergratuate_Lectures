/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
4주차 1차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//2번


int main()
{
	int month;

	printf("월(month)를 입력하세요: ");
	scanf_s("%d", &month);

	if (month == 1 | month == 2 | month == 3)
		printf("1사분기입니다.");
	else if (month == 4 | month == 5 | month == 6)
		printf("2사분기입니다.");
	else if (month == 7 | month == 8 | month == 9)
		printf("3사분기입니다.");
	else 
		printf("4사분기입니다.");

	return 0;
}
