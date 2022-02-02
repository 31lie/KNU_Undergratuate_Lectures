/*********************
컴퓨터학부 심화컴퓨터전공
2020114658 이윤서
7주차 1차시 과제
**********************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//4번


int main()
{
    printf("컴퓨터학부 심화컴퓨터전공 2020114658 이윤서\n\n");

    char str[100];
    printf("영문 문장을 입력하세요: ");
    gets(str);

    for (int i = 0; str[i] != NULL; i++) {
        if (65 <= str[i] && str[i] <= 90) str[i] += 32;
        else if (97 <= str[i] && str[i] <= 122) str[i] -= 32;
    }
    printf("위에서 입력한 문자열에서 대문자와 소문자를 반대로 변환하면:\n %s", str);
    return 0;
}