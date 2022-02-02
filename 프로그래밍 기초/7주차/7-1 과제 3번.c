/*********************
컴퓨터학부 심화컴퓨터전공
2020114658 이윤서
7주차 1차시 과제
**********************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//3번

int main()
{
	printf("컴퓨터학부 심화컴퓨터전공 2020114658 이윤서\n\n");
	char str1[50], str2[50];
	int leng;

	printf("첫 번째 문장을 입력하세요: ");
	gets_s(str1, sizeof(str1));
	printf("두 번째 문장을 입력하세요: ");
	gets_s(str2, sizeof(str2));

	strcat(str1, str2);
	printf("%s", str1);

	return 0;

}