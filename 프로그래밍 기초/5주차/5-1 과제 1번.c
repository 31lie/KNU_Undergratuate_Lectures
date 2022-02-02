/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
5주차 1차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//1번


int main()
{
	char star = '*';
	char* ptrchar = &star;

	printf("변수의 주소: %d, 코드 값: %d, 문자: %c", ptrchar, *ptrchar, *ptrchar);

	return 0;

}