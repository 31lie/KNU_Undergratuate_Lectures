#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct node *nodePointer;
typedef struct node {
    int vertex;
    nodePointer link;
} node;

typedef struct hdnodes {
    int count;
    nodePointer link;
} hdnodes;

hdnodes graph[MAX_VERTICES];

void topSort(hdnodes graph[], int n) {
    int i, j, k, top;
    nodePointer ptr;
    top = -1;
    for (i=0 ; i<n ;i++) {
        if (!graph[i].count) {
            graph[i].count = top;
            top = i;
        }
    }
    for (i=0 ; i<n ; i++) {
        if (top==-1) {
            fprintf(stderr,"\nNetwork has a cycle. Sort terminated. \n");
            exit(EXIT_FAILURE);
        }
        else {
            j = top;
            top = graph[top].count;
            printf("%3d",j);
            for (ptr=graph[i].link; ptr ; ptr = ptr->link) {
                k = ptr->vertex;
                graph[k].count--;
                if (!graph[k].count) {
                    graph[k].count = top;
                    top=k;
                }
            }
        }
    }
}

int main() {

    FILE *fp = fopen("input.txt","r");

    if (fp==NULL) {
        fprintf(stderr,"File Open Error!");
        exit(EXIT_FAILURE);
    }

    int vertexNum;
    fscanf(fp,"%d",&vertexNum);
    
    int** input = (int**) malloc(sizeof(int*)*vertexNum);
    for (int i=0 ; i<vertexNum ; i++) {
        input[i] = malloc(sizeof(int)*vertexNum);
    }

    int num;
    for (int i=0 ; i<vertexNum ; i++){
        for (int j=0 ; j<vertexNum ; j++) {
            fscanf(fp,"%d",&num);
            input[i][j] = num;
        }
    }

    nodePointer temp;
    nodePointer end;

    for (int i=0; i<vertexNum ; i++){
        graph[i].link = NULL;
        for (int j=0 ; j<vertexNum ; j++) {
            if(input[i][j]!=0){
                temp = malloc(sizeof((*temp)));
                temp -> vertex = j;
                temp->link = NULL;
                if (!graph[i].link) {
                    graph[i].link = temp;
                    end = temp;
                }
                else {
                    end -> link = temp;
                    end = temp;
                }
                graph[j].count++;
            }
        }
    }


    topSort(graph, vertexNum);

}