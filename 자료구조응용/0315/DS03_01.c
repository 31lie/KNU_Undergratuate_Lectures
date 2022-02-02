#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y,temp) ((temp)=(x), (x)=(y), (y)=(temp))


void selection_sort(int array[],int n){
    clock_t start = clock();
    
    int i, j, least, temp;
    for (i=0; i<n-1 ; i++){
        least = i;

        for (j=i+1;j<n;j++){
            if (array[j]>array[least])
                least = j;
        }

        if (i!= least){
            SWAP(array[i], array[least], temp);
        }
    }
    clock_t end = clock();

    printf("%f", (float)(end-start)/CLOCKS_PER_SEC);
}




int main(){
    
    int num;

    FILE *fp = fopen("unsorted.txt", "w");
    FILE *fpp = fopen("sorted.txt", "w");

    if (fp==NULL || fpp==NULL){
        printf("File Open ERROR!");

        return 0;
    }

    printf("N: ");
    scanf("%d",&num);

    if (num>0 && num<=10000){
        int* array = malloc(sizeof(int)*num);

        srand(time(NULL));
        for (int i=0;i<num;i++){
            array[i] = rand();
            fprintf(fp,"%d ",array[i]);
        }  
           
        selection_sort(array, num);

        for (int i=0; i<num; i++){
            fprintf(fpp,"%d ",array[i]);
        }

        fclose(fp);
        fclose(fpp);
        free(array);
    }
    
    return 0;
}