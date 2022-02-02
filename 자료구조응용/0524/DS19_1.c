#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int Check[MAX_SIZE][MAX_SIZE] = {0,};
int row, col;

void findSmall(int rowSize, int colSize) {
    int small = 10000;
    for (int i=0 ; i<rowSize+1 ; i++) {
        for (int j=0 ; j<colSize+1; j++) {
            if (j>i) {
                if ((Check[i][j]>0)&&(small>=Check[i][j])) {
                    small = Check[i][j];
                    row = i;
                    col = j;
                    ;
                }
            }
        }
    }
    Check[row][col] = -1;
}

int main() {
    FILE *fp = fopen("input.txt","r");

    if (fp==NULL) {
        fprintf(stderr, "File Open Error!");
        exit(EXIT_FAILURE);
    }
    

    int NodeCnt = 0;
    fscanf(fp,"%d",&NodeCnt);
    int temp = 0;
    int EdgeCnt = 0;
    


    // 간선 개수 세기 + 배열 저장
    int Graph[MAX_SIZE][MAX_SIZE] = {0,};
    for (int i=0 ; i<NodeCnt ; i++) {
        for (int j=0 ; j<NodeCnt ; j++) {
            fscanf(fp,"%d",&temp);
            if ((j>i) && temp !=0) {
                EdgeCnt++;   
                Graph[i][j] = temp;
            }
        }   
    }


    for (int i = 0; i < NodeCnt; i++){
        for (int j = 0; j < NodeCnt; j++) {
            Check[i][j] = Graph[i][j];
        }
    }

    //가중치 배열 생성
    int **E = (int **)malloc(sizeof(int *) * 2);
    for (int i = 0; i < 2; i++) {
        E[i] = (int*)malloc(sizeof(int) * EdgeCnt);
    }

    //가중치 배열 오름차순 저장
    for (int i=0 ; i<=EdgeCnt ; i++){
        findSmall(NodeCnt,NodeCnt);
        E[0][i] = row;
        E[1][i] = col;
    }



    //서브트리 확인 배열
    int *s = (int*)malloc(sizeof(int)*NodeCnt);
    for (int i=0 ; i<NodeCnt ; i++) {
        s[i]=i;
    }

    //선택된 간선을 기억하는 배열
    int **T = (int**)malloc(sizeof(int*)*2);
    for (int i=0 ; i<2 ; i++){
        T[i] = (int *)malloc(sizeof(int)*(NodeCnt - 1));
    }


    //크루스칼 알고리즘
    int edgCount = 0;
    int i=0 ;
    int v1, v2;
    int s1, s2;
    int count=0;

    while (edgCount < (NodeCnt-1)) {
        v1 = E[0][i];
        v2 = E[1][i];
        s1 = s[v1];
        s2 = s[v2];
        if (s1 != s2) {
            for (int j = 0; j < NodeCnt ; j++){
                if (s[j] == s2) {
                    s[j] = s1;
                }
            }
            T[0][edgCount] = v1;
            T[1][edgCount] = v2;
            edgCount++;
            count = count + Graph[v1][v2];

        }
        i++;
    }

    printf("Selected Edges: ");

    for (int s = 0 ; s < NodeCnt-1 ; s++) {
        if (s==NodeCnt-2)
            printf("(%d, %d)", T[0][s], T[1][s]);
        else
            printf("(%d, %d), ", T[0][s], T[1][s]);
    }
    printf("\nCost: %d",count);
    
}


