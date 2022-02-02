/***********************
컴퓨터학부 심화컴퓨터전공
2020114658 이윤서
2주차 2차시 _ 실습문제
************************/

#include <stdio.h>


//2번

int main()
{
	int second = 1;
	int minute = second * 60;
	int hour = minute * 60;
	int day = hour * 12;

	printf("하루는 %d초 입니다.", day);

	return 0;
}