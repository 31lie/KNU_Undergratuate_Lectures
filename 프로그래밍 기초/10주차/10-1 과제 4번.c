/*
 프로그래밍 기초 10주차 1차시 과제
 2020114658 이윤서
 */


#include <stdio.h>
#include <stdarg.h> 

double vasum(char*, ...);

int main()
{
    printf("컴퓨터학부 심화컴퓨터전공 2020114658 이윤서\n\n");

    printf("%f\n", vasum("dfdf", 3, 20.75412, 51, 21.9012));
    return 0;
}

double vasum(char* type, ...)
{
    va_list argp;

    int i = 0;
    double total = 0;
    va_start(argp, type);
    while (type[i] != '\0')
    {
        switch (type[i])
        {
        case 'd':
            total += va_arg(argp, int);
            break;
        case 'f':
            total += va_arg(argp, double);
            break;
        default:
            break;
        }
        i++;
    }
    va_end(argp);
    return total;
}