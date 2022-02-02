#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEGREE 101

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
    } polynomial;

int main()
{


    FILE *fa = fopen("a.txt","r");
    FILE *fb = fopen("b.txt","r");

    if (fa==NULL || fb==NULL){
        printf("File Open Error!");
    }
    
    polynomial pa;
    polynomial pb;
    polynomial result;

    memset(&pa,0,sizeof(polynomial));
    memset(&pb, 0, sizeof(polynomial));
    memset(&result, 0, sizeof(polynomial));

    fscanf(fa, "%d", &pa.degree);
    fscanf(fb, "%d", &pb.degree);

    //a 구조체 저장
    float coef;
    int expo, temp;


    for (int i=0; i<pa.degree;i++){
        fseek(fa,1,SEEK_CUR);
        fscanf(fa, "%f", &coef);
        fseek(fa, 1, SEEK_CUR);
        fscanf(fa, "%d", &expo);
        pa.coef[expo]=coef;
    }

    
    //b 구조체 저장
    for (int i = 0; i < pb.degree; i++){
        fseek(fb, 1, SEEK_CUR);
        fscanf(fb, "%f", &coef);
        fseek(fb, 1, SEEK_CUR);
        fscanf(fb, "%d", &expo);
        pb.coef[expo] = coef;
    }
    
    //연산 후 result 구조체 저장
    int resultterm=0;
    for (int i=0; i<MAX_DEGREE; i++){
        if (pa.coef[i]!=0 || pb.coef[i]!=0){
            result.coef[i] = pa.coef[i]+pb.coef[i];
            resultterm++;

        }
        
    }

    
    //출력


    int cnt=0;

    for (int i=MAX_DEGREE-1; i>=0;i--){
        if (result.coef[i] > 0){
            if (i==0){
                printf("%.1f", result.coef[i]);
            }
            else{
                printf("%.1fx^%d", result.coef[i], i);
            }
            
            cnt++;
            if (cnt<resultterm){
                printf(" + ");
            }
        }

    }
    
    fclose(fa);
    fclose(fb);  
     
    return 0;
}