/*********************
컴퓨터학부 심화컴퓨터전공
2020114658 이윤서
9주차 2차시 과제
**********************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//2번

struct person {
	char name[10];
	char phone[20];
	char address[50];
}person;

struct employee {
	struct person info;
	char number[20];
	int monthpay;
	double incentive;
	double yearpay;
};

int main()
{
	struct employee p[10] = { NULL, };
	char res;
	int i = 0, j = 0;

	printf("\n컴퓨터학부 심화컴퓨터전공 2020114658 이윤서\n\n");
	printf("[input]\n");

	do
	{
		printf("사번, 이름, 전화번호, 주소 입력: ");
		scanf_s("%s %s %s %[^\n]", p[j].number,10, p[j].info.name,20, p[j].info.phone,20,p[j].info.address,50);
		printf("월급, 인센티브 입력: ");
		scanf_s("%d %lf", &p[j].monthpay, &p[j].incentive);
		p[j].yearpay = p[j].monthpay * (12 + p[j].incentive);

		printf("계속 입력하시겠습니까?");
		scanf_s("\n%c", &res, 2);
		j++;
	} while (res == 'y');

	printf("[output]\n");
	printf("\n  사 번   이 름		전 화 번 호		주 소		 월 급	        인센티브	    연 봉   \n\n");
	for (i = 0; (i < j); i++)
	{
		printf("%s  %s       %s     %s    %d          %d             %.1lf\n", p[i].number, p[i].info.name, p[i].info.phone, p[i].info.address, p[i].monthpay, (int)(p[i].incentive * 100), p[i].yearpay);
	}

	return 0;

}