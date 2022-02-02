/*********************
컴퓨터학부 심화컴퓨터전공
2020114658 이윤서
7주차 1차시 과제
**********************/

#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

//2번

int main()
{
	printf("컴퓨터학부 심화컴퓨터전공 2020114658 이윤서\n\n");

	char c;
	printf("문자열을 입력하세요: ");

	while (scanf_s("%c", &c) != EOF)
	{
		if (c != ' ')
			printf("%c", c);
	}
	return 0;

}