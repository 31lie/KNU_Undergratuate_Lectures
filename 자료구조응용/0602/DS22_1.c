#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int record[MAX][2];

void SWAP(int* x, int* y) {
    int temp;
    for (int i=0 ; i<2 ; i++) {
        temp = x[i];
        x[i] = y[i];
        y[i] = temp;
    }
}

void printList(int size) {
    for (int i=1 ; i<size+1 ; i++) {
        for (int j=0 ; j<2 ; j++){
            printf("%5d",record[i][j]);
        }
        printf("\n");
    }
}


void quickSort(int key, int left, int right) {
    int pivot, i, j;

    if (left<right) {
        i = left; j=right + 1;
        pivot = record[left][key];
        do {
            do i++; while (record[i][key] < pivot);
            do j--; while (record[j][key] > pivot);
            if (i<j) SWAP(record[i],record[j]);
        } while (i<j);
        SWAP(record[left],record[j]);
        
        quickSort(key,left,j-1);
        quickSort(key,j+1,right);
    }
}

int main() {

    FILE *fp = fopen("input.txt","r"); 

    if (fp == NULL) {
        fprintf(stderr,"File open Error!");
        exit(EXIT_FAILURE);
    }

    int recordNum;
    fscanf(fp,"%d",&recordNum);

    int temp;
    for (int i=1 ; i<recordNum+1 ; i++) {
        for (int j=0 ; j<2 ; j++) {
            fscanf(fp,"%d",&temp);
            record[i][j] = temp;
        }
    }


    printf("K1\n");
    quickSort(0, 1, recordNum);
    printList(recordNum);
    printf("\n");

    printf("K2\n");
    quickSort(1, 1, recordNum);
    printList(recordNum);
    printf("\n");
}