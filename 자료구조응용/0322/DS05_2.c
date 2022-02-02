#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERMS 100

typedef struct{
    float coef;
    int expon;
    } polynomial;

polynomial terma[MAX_TERMS]={0,};
polynomial termb[MAX_TERMS]={0,};

int main()
{

    FILE *fa = fopen("a.txt", "r");
    FILE *fb = fopen("b.txt", "r");

    if (fa == NULL || fb == NULL)
    {
        printf("File Open Error!");
    }

    int a_term;
    int b_term;

    fscanf(fa, "%d", &a_term);
    fscanf(fb, "%d", &b_term);

    //a 저장
    for (int i = 0; i < a_term; i++)
    {
        fseek(fa, 1, SEEK_CUR);
        fscanf(fa, "%f", &terma[i].coef);
        fseek(fa, 1, SEEK_CUR);
        fscanf(fa, "%d", &terma[i].expon);
    }

    //b저장
    for (int i = 0; i < b_term; i++)
    {
        fseek(fb, 1, SEEK_CUR);
        fscanf(fb, "%f", &termb[i].coef);
        fseek(fb, 1, SEEK_CUR);
        fscanf(fb, "%d", &termb[i].expon);
    }

    //결과 출력


    float result[MAX_TERMS]={0,};

    for(int i=0;i<a_term;i++){
        result[terma[i].expon]+=terma[i].coef;   
    }

    for (int i = 0; i < b_term; i++){
        result[termb[i].expon] += termb[i].coef;
    }

    int terms=0;
    int cnt=0;

    for (int i=0;i<MAX_TERMS;i++){
        if (result[i]>0){
            terms++;
        }
    }


    for (int i = MAX_TERMS - 1; i >= 0; i--)
    {   
        if (result[i] > 0)
        {   
            if (i == 0){
                printf("%.1f", result[i]);
            }
            else{
                printf("%.1fx^%d", result[i], i);
            }
            cnt++;

            if (cnt < terms)
            {
                printf(" + ");
            }
            
        }   
    }
    fclose(fa);
    fclose(fb);
    
    return 0;
}

    
