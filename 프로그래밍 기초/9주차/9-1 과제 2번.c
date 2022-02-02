/*********************
컴퓨터학부 심화컴퓨터전공
2020114658 이윤서
9주차 1차시 과제
**********************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//2번

struct person {
	char name[20];
	char number[20];
	char address[50];
};

int main()
{
	printf("컴퓨터학부 심화컴퓨터전공 2020114658 이윤서\n\n");
	struct person p1 = { "홍길동","011-1111-1111","서울시 구로구 고척동" };
	struct person p2 = { "조명호","017-3245-3278","서울시 강남구 도곡동" };
	struct person p3 = { "최윤호","011-2222-2456","경기도 안양시 비산동" };


	printf("이름	전화번호		주소\n\n");
	printf("%s	%s		%s\n", p1.name, p1.number, p1.address);
	printf("%s	%s		%s\n", p2.name, p2.number, p2.address);
	printf("%s	%s		%s", p3.name, p3.number, p3.address);

	return 0;
}
