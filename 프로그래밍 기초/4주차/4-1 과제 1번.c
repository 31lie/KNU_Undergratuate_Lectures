/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
4주차 1차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//1번

int main()
{
	double x, y;
	printf("두 실수 입력: ");
	scanf_s("%lf %lf", &x,&y);

	int select;
	printf("연산종류 번호선택 1<+>, 2<->, 3<*>, 4</>: ");
	scanf_s("%d", &select);

	switch (select) {

	case 1:
		printf("%.2lf + %.2lf = %.2lf", x, y, x+y);
		break;

	case 2:
		printf("%.2lf - %.2lf = %.2lf", x, y, x - y);
		break;

	case 3:
		printf("%.2lf * %.2lf = %.2lf", x, y, x * y);
		break;

	case 4:
		printf("%.2lf / %.2lf = %lf", x, y, x / y);
		break;

	default:
		printf("잘못된 입력입니다.");
	}

	return 0;
}
