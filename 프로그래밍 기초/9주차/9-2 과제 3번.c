/*********************
컴퓨터학부 심화컴퓨터전공
2020114658 이윤서
9주차 2차시 과제
**********************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//3번


struct person {
	char name[20];
	char tel[20];
	char adress[80];
};

typedef struct person person;

union reg {
	person man;
	char company[20];
};

typedef union reg reg;

struct car {
	char year[10];
	char kind[20];
	reg owner;
};

typedef struct car car;

int main()
{
	printf("\n컴퓨터학부 심화컴퓨터전공 2020114658 이윤서 \n\n");
	car c[2] = { {"2012 09","그랜져 GT",{"홍길동","011-1111-1111","서울시 구로구 고척동"}},{"2013 04","인피니티","인피니티북스"} };
	printf("%10s%16s%30s\n\n", "년 식", "종 류", "주 인");
	printf("%10s%16s%10s%14s%24s\n", c[0].year, c[0].kind, c[0].owner.man.name, c[0].owner.man.tel, c[0].owner.man.adress);
	printf("%10s%16s%30s\n", c[1].year, c[1].kind, c[1].owner.company);

	return 0;
}