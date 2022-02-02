/*
 프로그래밍 기초 10주차 1차시 과제
 2020114658 이윤서
 */

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

 //1번

void print(int* pi, int size);
void increment(int* pi, int size, int inc);

int main()
{
    int data[] = { 3,21,35,57,24,82,8 };
    int inc;

    printf("컴퓨터학부 심화컴퓨터전공 2020114658 이윤서\n\n");
    print(data, sizeof(data) / sizeof(int));
    printf("배열의 각 원소에 더할 상수를 입력하세요 -> ");
    scanf_s("%d", &inc);

    increment(data, sizeof(data) / sizeof(int), inc);
    print(data, sizeof(data) / sizeof(int));

    return 0;
}

void print(int* pi, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%3d", *(pi + i));
    }
    printf("\n");

}

void increment(int* pi, int size, int inc)
{
    for (int i = 0; i < size; i++)
    {
        *(pi + i) += inc;
    }
}