/*********************
컴퓨터학부 심화컴퓨터전공
202011458 이윤서
5주차 1차시 과제
**********************/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//3번


int main()
{
	int value = 0x2F24263F;
	char* pc = (char*)&value;

	printf("변수명    저장값         주소값\n");
	printf("------------------------------------\n");
	printf(" value     %0#x    %u\n", value, &value);

	for (int i = 0; i <= 3; i++)
	{
		char ch = *(pc + i);
		printf("*(pc+%d)    %0#x    %2c    %u\n", i, ch, ch, pc + i);

	}

	 return 0;


}