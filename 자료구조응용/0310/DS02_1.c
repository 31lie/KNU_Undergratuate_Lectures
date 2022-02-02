#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
    int num;
    int prime=1;

    while(1){
        printf("Number: ");
        scanf("%d", &num);

        if (num > 0)
        {
            for (int i = 2; i < num; i++)
            {
                if (num % i == 0)
                {
                    prime = 0;
                    break;
                }
            }

            if (prime == 0)
            {
                printf("Not Prime");
            }
            else
            {
                printf("Prime");
            }
            break;
        }

        else
        {
            printf("Input Error. Try again!\n\n");
        }
    }
    
}