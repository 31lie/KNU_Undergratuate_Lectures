/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
6주차 1차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//1번

int main()
{
	int arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	int(*ptr)[4] = arr;

	int size1 = sizeof(arr) / sizeof(arr[0]);    //3
	int size2 = sizeof(arr[0]) / sizeof(arr[0][0]);		//4
	int i, j;

	/* 이중포인터 이용 */
	


	printf("첫번째 방법: 이중포인터 이용\n\n");
	for (i = 0; i < size1; i++)
	{
		for (j = 0; j < size2; j++)
		{
			printf("%5d",*(*(ptr+i)+j));
		}
		printf("\n");

	}
	printf("\n");


	/* ptr[i] 이용 */

	printf("두번째 방법: *ptr[i] 이용\n\n");
	for (i = 0 ; i < size1 ; i++)
	{
		for (j = 0; j < size2; j++)
		{
			printf("%5d",*(ptr[i]+j));
		}
		printf("\n");

	}


	
	return 0;
}


