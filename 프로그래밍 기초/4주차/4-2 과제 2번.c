/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
4주차 2차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//2번


int main()
{
	int floor;

	printf("피라미드 층 입력: ");
	scanf_s("%d", &floor);

	int star = 2 * floor - 1;

	for (int i = 1; i <= floor; i++)
	{
		for (int m = 1; m <= (floor - i); m++)
		{
			printf(" ");
		}
		
		for (int s = 1; s <= ((2 * i) - 1); s++)
		{
			printf("*");
		}

		for (int t = 1; t <= (floor - i); t++)
		{
			printf(" ");
		}

		printf("\n");
	}

	return 0;
}