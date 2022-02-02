/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
6주차 2차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//1번


int sum(int *ary, int SIZE);

int main()
{
	printf("2020114658 이윤서\n");
	int array[] = { 1,2,3,4,5 };
	int* array1 = array;
	int aryLength = sizeof(array) / sizeof(int);
	printf("%d", sum(array1,aryLength));

	return 0;
}

int sum(int *ary, int SIZE)
{
	int i,result=0;
	for (i = 0; i < SIZE; i++)
	{
		result = result + *(ary+i);
		
	}

	return result;
}