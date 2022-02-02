/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
6주차 2차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//3번

#include <stdlib.h>
#include <time.h>

#define MAX 100
#define LAST 7

//3번

int chanceCount(count,last);
int result;

int main()
{
	printf("2020114658 이윤서\n");

	int guess, input,cnt;

	srand((long)time(NULL));
	guess = rand() % MAX + 1;

	printf("1에서 %d 사이에서 한 정수가 결정되었습니다.\n", MAX);
	printf("이 정수는 무엇일까요? 입력해 보세요: ");
	cnt = 0;

	while (scanf_s("%d", &input))
	{
		if (input > guess)
		{
			cnt++;
			chanceCount(cnt, LAST);
			if (result == 1)
				break;
			printf("입력한 수보다 작습니다. 다시 입력하세요: ");
		
		}
			
		else if (input < guess)
		{
			cnt++;
			chanceCount(cnt, LAST);
			if (result == 1)
				break;
			printf("입력한 수보다 큽니다. 다시 입력하세요: ");
			
		}
			
		else
		{
			puts("정답입니다.");
			break;
		}
	}
	return 0;
}

int chanceCount(count,last)
{
	result=0;
	if (count == last)
	{
		printf("모든 기회를 쓰셨습니다.");
		result = 1;
	}
}