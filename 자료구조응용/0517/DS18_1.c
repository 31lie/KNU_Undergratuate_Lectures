#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

#define MAX_VERTEX 100
#define FALSE 0
#define TRUE 1


typedef struct node* nodePointer;
typedef struct node {
    int vertex;
    nodePointer link;
} node;

nodePointer front, rear;

nodePointer adjLists[MAX_VERTEX];
short int visited[MAX_VERTEX];
node queue[MAX_VERTEX];


void dfs(int v){
    nodePointer w;
    visited[v] = TRUE;
    printf("%3d", v);
    for (w = adjLists[v] ; w ; w = w->link) {
        if (!visited[w->vertex])
            dfs(w->vertex);
    }
}

void addq(int item) {
    nodePointer temp = malloc(sizeof(temp));
    temp -> vertex = item;
    temp -> link = NULL;
    if (!front){
        front = rear = temp;
    }
    else {
    rear -> link = temp;
    rear = rear -> link;
    }
}

int deleteq() {
    int temp = front -> vertex;
    front = front -> link;
    return temp;
}

void bfs(int v) {
    nodePointer w;
    front = rear = NULL;
    printf("%3d",v);
    visited[v] = TRUE;
    addq(v);
    while (front) {
        v = deleteq();
        for (w = adjLists[v] ; w ; w= w->link) {
            if (!visited[w->vertex]) {
                printf("%3d", w->vertex);
                addq(w->vertex);
                visited[w->vertex] = TRUE;
            }
        }
    }
}





int main() {


    FILE *fp =fopen("input.txt","r");
    
    if (fp==NULL) {
        fprintf(stderr,"File Open Error!");
        exit(EXIT_FAILURE);
    }

    int vertCnt;
    int data = 0;
    fscanf(fp,"%d",&vertCnt);


    nodePointer head;
    for (int i=0 ; i < vertCnt ; i++) {
        int firstcheck = 0;
        for (int j = 0; j < vertCnt; j++) {
            fscanf(fp, "%d", &data);
            if (data == 1) {
                nodePointer temp = malloc(sizeof(*temp));
                temp -> link = NULL;
                temp -> vertex = j;
                if (firstcheck ==0) {
                    adjLists[i] = temp;
                    head = temp;
                    firstcheck = 1;
                }
                else {
                    head -> link = temp;
                    head = head->link;
                }
            }
        }
    }


    for (int i=0 ; i<vertCnt ; i++) {
        printf("Vertex %d: ",i);
        head = adjLists[i];
        while (head) {
            printf(" %d ",head->vertex);
            head = head -> link;
        }
        printf("\n");
    }

    printf("DFS:  ");
    dfs(0);
    printf("\n");

    for (int i = 0 ; i < vertCnt*vertCnt ; i++) {
        visited[i] = FALSE;
    }

    printf("BFS:  ");
    bfs(0);

    
    return 0;
}   