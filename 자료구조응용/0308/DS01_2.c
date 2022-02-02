#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

    FILE *fp = fopen("input.txt","r");

    int i,k;
    int data[10]={0,};

    k=0;
    while (fscanf(fp,"%d",&i) !=EOF){
        data[k]=i;
        k++;
    }

    fclose(fp);

    int min=data[0], max=data[0];

    for (int i=0;i<10;i++){
        if (min>data[i]){
            min=data[i];
        }
        if (max<data[i]){
            max=data[i];
        }
    }

    printf("Min: %d\nMax: %d",min,max);
    for (int i=0;i<10;i++);


    return 0;
}