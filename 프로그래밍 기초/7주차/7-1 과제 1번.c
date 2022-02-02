/*********************
컴퓨터학부 심화컴퓨터전공
2020114658 이윤서
7주차 1차시 과제
**********************/

#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

//1번

int main()
{
	char str[100];
	int length, i;
	int count[26] = { 0 };

	printf("컴퓨터학부 심화컴퓨터전공 2020114658 이윤서\n\n");

	printf("문자열을 입력하세요: ");
	gets_s(str, sizeof(str));
	length = strlen(str);

	for (i = 0; i < length; i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z' || 'a' && str[i] <= 'z'))
		{
			if (str[i] <= 'Z')
				count[str[i] - 'A']++;
			else
				count[str[i] - 'a']++;
		}
	}

	for (i = 0; i < 26; i++)
	{
		if (count[i])
			printf("%c : %d\n", 'a' + i, count[i]);
	}

	return 0;
}

