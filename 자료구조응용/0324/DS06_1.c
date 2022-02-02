#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_TERMS 101
#define MAX_COL 10


typedef struct{
    int col;
    int row;
    int value;
} term;

void row_major_order_print(term* matrix){
    for (int i=0;i<(matrix->value+1);i++){
        if ((matrix+i)->value!=0){
            printf("%3d%3d%3d\n",(matrix+i)->row, (matrix+i)->col, (matrix+i)->value);
        }
    }
}

void fastTranspose(term a[], term b[]){
    int rowTerms[MAX_COL], startingPos[MAX_COL];
    int i, j, numCols = a[0].col, numTerms = a[0].value;
    b[0].row=numCols; b[0].col = a[0].row;
    b[0].value = numTerms;

    if (numTerms>0){
        for (i=0;i<numCols;i++)
            rowTerms[i]=0;
        for (i = 1; i<=numTerms;i++)
            rowTerms[a[i].col]++;
        startingPos[0]=1;
        for (i=1;i<numCols;i++)
            startingPos[i]=startingPos[i-1]+rowTerms[i-1];
        for (i=1;i<=numTerms;i++){
            j = startingPos[a[i].col]++;
            b[j].row = a[i].col ; b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}





int main() {

    term a[MAX_TERMS];
    term result[MAX_TERMS];

    FILE *fa = fopen("mat1.txt","r");
    FILE *fb = fopen("mat2.txt", "r");

    //파일 오픈 에러
    if (fa==NULL || fb==NULL){
        printf("File Open Error!");
    }

    //a,b 두 행렬 크기 저장
    int a_row, a_col=0;
    int b_row, b_col=0;

    fscanf(fa, "%d", &a_row);
    fscanf(fa, "%d", &a_col);

    fscanf(fb, "%d", &b_row);
    fscanf(fb, "%d", &b_col);

    int aval, bval=0 ;
    int cnt=0;

    if ((a_row==b_row)&&(a_col==b_col)){
        a[0].row = a_row;
        a[0].col = a_col;

        for (int i=0 ; i< a_row*a_col;i++){
            fscanf(fa,"%d",&aval);
            fscanf(fb, "%d", &bval);

            if ((aval+bval)!=0){
                cnt++;
                a[cnt].row = i / a_row;
                a[cnt].col = i % a_col;
                a[cnt].value = aval + bval;
            }
        }

        a[0].value = cnt;
    }

    printf("Matrix Addition\n");
    row_major_order_print(a);

    
    printf("Transpose Addition\n");
    fastTranspose(a,result);
    row_major_order_print(result);

    return 0;
}

