#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int capacity = 1;
int top = -1;
int* stack;



void pop(){
    if (top!=-1)
        top-=1;
}

void stackFull(){
    stack = (int *)realloc(stack, 2 * capacity * sizeof(*stack));
    capacity *=2;
}

void push(int num)
{
    if (top == capacity - 1)
        stackFull();
    stack[++top] = num;
}

int main(){

    FILE *fp = fopen("input.txt","r");

    if (fp==NULL){
        printf("File Open Error!");
    }

    stack = (int *) malloc(sizeof(*stack));
    char order;
    int num;

    while (!feof(fp)){
        fscanf(fp,"%c ",&order);
        if(order=='I'){
            fscanf(fp,"%d",&num);
            push(num);
        }
        if(order=='D'){
            pop();
        }
    }

    printf("Capacity: %d\n",capacity);
    printf("Stack: ");
    for (int i=0;i<=top;i++){
        printf("%2d",stack[i]);
    }
    
    return 0;
}