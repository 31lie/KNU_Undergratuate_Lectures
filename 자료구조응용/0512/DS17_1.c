#include <stdio.h>
#include <stdlib.h>


int winner=0;

int CalNode(int cnt) {
    int size =0;
    while (cnt>0) {
        size = size + cnt;
        cnt /=2;
    }
    return size;
}

void levelOrder(int* arr, int size) {
    printf("Level Order:   ");
    for (int i=1; i<size+1 ; i++){
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

void iterInorder(int* arr, int size){
    printf("Inorder: ");
    int stack[size];
    int top = -1;
    int i = 1;
    while (1){
        while (size >= i){
            top++;
            stack[top] = i;
            i = i * 2;
        }
        if (top == -1)
            return;
        i = stack[top];
        top--;
        printf(" %d ", arr[i]);
        i = i*2+1;
    }
}

void winnerTree(int* arr, int size, int arrSize) {
    int index = size;
    while (index != 1) {
        for (int i = index; i < arrSize; i = i + 2){
            if (arr[i] >= arr[i + 1]){
                arr[i / 2] = arr[i+1];
            }
            else
                arr[i / 2] = arr[i];
        }
        index = index/2;
        arrSize = arrSize/2;
    }
    winner = arr[1];
    printf("Winner:  %d",winner);
    printf("\n");
}

int findRun(int* arr, int size, int arrSize, int winner) {
    int run=1;
    for (int i=0; i<size ; i++){
        if (arr[i+size]==winner){
            run = i+1;
        }
    }
    return run;
}


int main() {

    FILE *fp = fopen("input.txt","r");

    if (fp==NULL) {
        fprintf(stderr,"File Open Error!");
        exit(EXIT_FAILURE);
    }

    int runCount;
    fscanf(fp,"%d",&runCount);

    int **runArr = calloc(10,sizeof(int*));
    for (int i=0 ; i<10 ; i++){
        runArr[i] = calloc(runCount, sizeof(int));
    }
    
    for (int i=0;i<runCount;i++){
        int temp = 0;
        int count = 0;
        while (temp != -1) {
            fscanf(fp, "%d", &temp);
            runArr[i][count] = temp;
            count++;
        }
    }
    
    int Arrsize = CalNode(runCount);
    int *SelecTree = malloc(sizeof(int)*Arrsize+1);
    SelecTree[0] = '\0';
    int level =0;

    for (int i=0; i<runCount ; i++) {
        SelecTree[runCount+i] = runArr[i][level];
    }

    winnerTree(SelecTree,runCount,Arrsize);
    levelOrder(SelecTree,Arrsize);
    iterInorder(SelecTree,Arrsize);

    int run = findRun(SelecTree,runCount,Arrsize,winner);

    SelecTree[runCount+run-1] = runArr[run][1];
    printf("\n\n");
    winnerTree(SelecTree, runCount, Arrsize);
    levelOrder(SelecTree, Arrsize);
    iterInorder(SelecTree, Arrsize);
}   


