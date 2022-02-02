/****************************************
 프로그래밍 기초 11주차 1차시 과제
 2020114658 이윤서
 **********************************/

 //2번

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int len;
	char* str;

	printf("심화컴퓨터전공 2020114658 이윤서\n\n");
	printf("입력할 영문자의 갯수를 입력 >> ");
	scanf("%d", &len); // 11
	str = (char*)calloc(len+1,sizeof(char));
	printf("11개의 영문자 입력 >> ");
	scanf("%s", str); // objective-C    o b j e c t i v e - C 0
	printf("%s\n", str);
	free(str);
	return 0;
}