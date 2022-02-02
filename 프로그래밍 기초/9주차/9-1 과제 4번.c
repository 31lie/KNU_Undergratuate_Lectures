/*********************
컴퓨터학부 심화컴퓨터전공
2020114658 이윤서
9주차 1차시 과제
**********************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//4번

struct fraction {
	int numerator;
	int denominator;
};

struct fraction multFr(struct fraction fr1, struct fraction fr2)
{
	struct fraction res = { fr1.numerator * fr2.numerator,fr1.denominator * fr2.denominator };

	return res;
}

void prtFr(struct fraction fr1, struct fraction fr2,struct fraction result)
{
	struct fraction res = multFr(fr1, fr2);
	printf("[output]\n");
	printf("%d/%d * %d/%d = ",fr1.numerator,fr1.denominator,fr2.numerator,fr2.denominator);
	printf("%d/%d", result.numerator, result.denominator);
}

int main()
{
	printf("컴퓨터학부 심화컴퓨터전공 2020114658 이윤서 \n\n");
	struct fraction f1 = { 3,4 };
	struct fraction f2 = { 2,7 };
	
	prtFr(f1, f2,multFr(f1,f2));


	return 0;

}