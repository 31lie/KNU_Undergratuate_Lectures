#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n==MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

typedef struct {
    int key;
} element;

element heap[MAX_ELEMENTS];
int n=0;


void push(element item, int *n) {
    int i;
    if (HEAP_FULL(*n)) {
        fprintf(stderr, "The heap is full. \n");
        exit(EXIT_FAILURE);
    }

    i = ++(*n);
    while ((i !=1) && (item.key > heap[i/2].key)){
        heap[i] = heap[i/2];
        i /=2 ;
    }
    heap[i] = item;
}

void iterInorder(element heap[], int size) {
    int stack[MAX_ELEMENTS];
    int top = -1;
    int i=1;
    while (1) {
        while (size>=i) {
            top++;
            stack[top] = i;
            i = i*2;
        }
        if (top==-1)
            return;
        i = stack[top];
        top--;
        printf(" %d ",heap[i].key);
        i=i*2+1;
    }
}


element pop(int *n) {
    int parent, child;
    element item, temp;
    if (HEAP_EMPTY(*n)) {
        fprintf(stderr, "The heap is empty\n");
        exit(EXIT_FAILURE);
    }

    item = heap[1];

    temp = heap[(*n)--];
    parent = 1;
    child = 2;
    while (child <= *n) {
        if ((child < *n) && (heap[child].key < heap[child+1].key)) {
            child++;
        }
        if (temp.key >= heap[child].key) break;
        heap[parent] = heap[child];
        parent = child;
        child *=2;
    }
    heap[parent] = temp;
    return item;
}

void levelOrder(element heap[], int size) {
    printf("Level Order: ");
    for (int i = 1; i <= size; i++) {
        printf(" %d ", heap[i].key);
    }
    printf("\n");
}



int main() {

    FILE *fp = fopen("input.txt","r");

    if (fp==NULL) {
        fprintf(stderr,"File Open Error!");
        exit(EXIT_FAILURE);
    }

    element data;
    int heapSize = 0;
    while (!feof(fp)) {
        fscanf(fp,"%d",&data.key);
        push(data, &n);
        heapSize++;
    }

    
    levelOrder(heap, heapSize);
    printf("Inorder: ");
    iterInorder(heap,heapSize);
    printf("\n");

    pop(&n);
    levelOrder(heap, heapSize-1);
    printf("Inorder: ");
    iterInorder(heap, heapSize-1);
    printf("\n");

    pop(&n);
    levelOrder(heap,heapSize-2);
    printf("Inorder: ");
    iterInorder(heap, heapSize - 2);
    printf("\n");
}
