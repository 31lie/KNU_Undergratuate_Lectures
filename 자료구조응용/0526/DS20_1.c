#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define _CRT_SECURE_NO_WARNINGS

#define FALSE 0
#define TRUE 1

int *distance;
short int *found;

int choose(int* distance, int n, short int* found) {
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;
    for (i=0; i<n ; i++) {
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minpos = i;
        }
    }
    return minpos;
}

void shortestPath(int v, int** cost,int* distance, int n, short int* found) {
    int i, u, w;
    for (i=0 ; i<n ; i++) {
        found[i] = FALSE;
        distance[i] = cost[v][i];
    }
    found[v] = TRUE;
    distance[v] = 0;
    for (i=0 ; i< n-2 ; i++) {
        u = choose(distance,n,found);
        found[u] = TRUE;
        for (w=0 ; w<n ; w++) {
            if (!found[w]) {
                if (distance[u] + cost[u][w] < distance[w])
                    distance[w] = distance[u] + cost[u][w];
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

    int vertexNum, startEdge;

    fscanf(fp,"%d",&vertexNum);
    fscanf(fp,"%d",&startEdge);

    int **cost = (int**) malloc(sizeof(int*) * vertexNum);
    for (int i=0 ; i<vertexNum ; i++) {
        cost[i] = (int*) malloc(sizeof(int) *vertexNum);
    }

    int temp;
    for (int i=0 ; i<vertexNum ; i++) {
        for (int j=0 ; j < vertexNum ; j++) {
            fscanf(fp,"%d",&temp);
            if (temp==0){
                temp = INT_MAX/3;
            }
            cost[i][j] = temp;
        }
    }

    found = (short int*) malloc(sizeof(short int)*vertexNum);
    distance = (int*) malloc(sizeof(int) * vertexNum);

    shortestPath(startEdge, cost, distance, vertexNum, found);

    for (int i=0 ; i<vertexNum ; i++){
        printf("%6d",distance[i]);
    }
}