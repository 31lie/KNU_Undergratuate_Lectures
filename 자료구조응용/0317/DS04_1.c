#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int main()
{
    int asize, bsize;
    int i = 0;

    FILE *fp = fopen("a.txt","r");
    FILE *fpp = fopen("b.txt","r");

    if (fp == NULL || fpp ==NULL) {
        puts("Can't file open");
        return 0;
    }

    fseek(fp,0,SEEK_END);
    fseek(fpp,0,SEEK_END);

    asize = ftell(fp);
    bsize = ftell(fpp);
    
    fseek(fp, 0, SEEK_SET);
    fseek(fpp, 0, SEEK_SET);

    int *num1 = malloc(sizeof(int)*asize);
    int *num2 = malloc(sizeof(int)*asize);
    int *result = malloc(sizeof(int)*(asize));

    //배열에 숫자 거꾸로 저장
    for (i = 0 ; i<asize ; i++){
        num1[(asize-1)-i] = fgetc(fp) - 48;
    }

    for (i=0 ; i<bsize ; i++){
        num2[(bsize-1)-i] = fgetc(fpp) - 48;
    }

    for (i=bsize ; i<asize ; i++){
        num2[i] = 0;
    }

    for (i = 0; i < asize; i++) {
        result[i] = num1[i];
    }
    
    for (i = 0; i<asize-1 ; i++) {
        result[i] = result[i] + num2[i];
        if (result[i] >= 10) {
            result[i] -= 10;
            result[i+1] += 1;
        }
    }
    result[asize-1]=result[i]+num2[i];
    printf("Addition:");
    for (i=asize-1;i>=0;i--){
        printf("%d",result[i]);
    }

    printf("\n");

    // 뺄셈
    for (i = 0; i < asize; i++)
    {
        result[i] = num1[i];
    }

    for (i = 0; i<asize ; i++) {
        if (result[i]-num2[i] < 0) {
            result[i] = result[i] + 10 - num2[i];
            result[i+1] -= 1;
        } else {
            result[i] = result[i] - num2[i];
        }
    }
   
    for (i=asize-1; i >=0; i--) {
        if (result[i]!=0){
            break;
        }
    }
    
    if (i==-1){
        printf("Substraction: 0");
    }

    else{
        printf("Substraction: ");
        for (int j = i; j>=0;j--){
            printf("%d", result[j]);
        }
    }
    
    //닫기
    fclose(fp);
    fclose(fpp);

    free(num1);
    free(num2);

    return 0;
}