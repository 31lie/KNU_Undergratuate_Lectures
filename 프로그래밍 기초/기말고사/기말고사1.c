/*******************************************
컴퓨터학부 심화컴퓨터전공 2020114658 이윤서
프로그래밍기초_기말고사
********************************************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	printf("2020114658 이윤서\n");
	int m, n, x, y; // 범위 존재
	int arr[100][100];
	int ka;

	scanf("%d%d%d%d", &m, &n, &x, &y);

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			scanf("%d", &ka);
			arr[i][j] = ka;

		}
		
		
	}

}

int row