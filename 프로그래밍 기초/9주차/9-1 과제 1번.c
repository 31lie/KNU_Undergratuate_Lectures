/*********************
컴퓨터학부 심화컴퓨터전공
2020114658 이윤서
9주차 1차시 과제
**********************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//1번

struct fraction {
	int numerator;
	int denominator;
};

int main()
{
	printf("컴퓨터학부 심화컴퓨터전공 2020114658 이윤서\n\n");
	struct fraction f1 = { 4,5 };
	struct fraction f2 = { 3,7 };
	struct fraction res = { f1.numerator*f2.numerator, f1.denominator*f2.denominator};

	printf("[output]\n");
	printf("%d/%d * %d/%d = %d/%d",f1.numerator,f1.denominator,f2.numerator,f2.denominator,res.numerator,res.denominator);

	return 0;

}