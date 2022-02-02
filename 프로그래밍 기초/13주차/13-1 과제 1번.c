/****************************************
 프로그래밍 기초 13주차 1차시 과제
 2020114658 이윤서
 **********************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int main(void)
{
    printf("컴퓨터학부 심화컴퓨터전공 2020114658 이윤서\n\n");

    FILE* fp = NULL;
    char name[SIZE];
    char word[SIZE];
    char line[SIZE];
    int num = 0;

    printf("파일 이름: ");
    gets(name);

    if ((fp = fopen(name, "r")) == NULL)
    {
        printf("파일오픈오류\n");
        exit(1);
    }

    printf("검색할 단어: ");
    gets(word);
    while (!feof(fp))
    {
        num++;
        fgets(line, SIZE, fp);
        if (strstr(line, word) != NULL)
        {
            printf("[output]\n");
            printf("%s\n",name);
            printf("line %d\n",num);
            printf("%s\n",line);
        }
    }
    fclose(fp);
    return 0;
}
