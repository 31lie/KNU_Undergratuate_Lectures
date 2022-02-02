/*********************
컴퓨터학부 심화컴퓨터전공
2020114658 이윤서
9주차 2차시 과제
**********************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//1번


typedef struct person {
	char name[20];
	char number[20];
	char address[50];
}person;

int main()
{
	person p[10] = { NULL, };
	char res;
	int i = 0, j = 0;

	printf("\n컴퓨터학부 심화컴퓨터전공 2020114658 이윤서\n\n");
	printf("[input]\n");
	do
	{
		printf("이름:");
		scanf_s("\n%s", p[j].name,20);
		printf("전화번호:");
		scanf_s("\n%s", p[j].number,20);
		printf("주소:");
		scanf_s("\n%[^\n]s",p[j].address,50);

		printf("계속 입력하시겠습니까?");
		scanf_s("\n%c",&res,2);
		j++;
	} while (res == 'y');

	printf("[output]\n");
	printf("이름	전화번호		주소\n\n");
	for (i = 0; (i < sizeof(p) / sizeof(p[0])); i++)
	{
		printf("%s	%s		%s\n", p[i].name, p[i].number, p[i].address);
	}

	return 0;

}