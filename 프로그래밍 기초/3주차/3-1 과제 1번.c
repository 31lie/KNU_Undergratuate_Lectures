/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
3주차 1차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//1번

#define PI 3.141592

int main()
{
    double radius;
    scanf_s("%lf", &radius);
    double area = radius * radius * PI;
    double cir = 2 * PI * radius;
    printf("원의 반지름: %lf\n", radius);
    printf("원의 면적: %lf\n", area);
    printf("원의 둘레: %lf", cir);

    return 0;

}
