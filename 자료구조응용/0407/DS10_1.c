#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct NODE{
    struct NODE *next;
    int data;
};

void addNode(struct NODE *target, int data){
    struct NODE *newNode = malloc(sizeof(struct NODE)); 
    newNode->next = target -> next;                     
    newNode->data = data;                              
    target->next = newNode;
}

void concatenate(struct NODE *list1, struct NODE *list2){
    struct NODE *temp;
    if (!list1) exit(1);
    if (!list2) exit(1);

    for (temp = list1; temp->next; temp = temp->next);
    temp -> next = list2->next;
}

struct NODE *middle, *trail;
struct NODE* invert(struct NODE *lead){
    middle = NULL;
    while (lead){
        trail = middle;
        middle = lead;
        lead = lead->next;
        middle -> next = trail;
    }
    return middle;
}


int main()
{
    FILE *fp1 = fopen("input1.txt","r");
    FILE *fp2 = fopen("input2.txt","r");

    if (fp1==NULL || fp2 == NULL){
        printf("File Open Error!");
    }

    int num;
    
    struct NODE *head1 = malloc(sizeof(struct NODE));
    struct NODE *curr = malloc(sizeof(struct NODE));
    head1->next = NULL;
    curr = head1;

    while (!feof(fp1)){
        fscanf(fp1, "%d",&num);
        addNode(curr,num);
        curr = curr->next;
    }  

    curr = head1->next;
    printf("First:\n");
    while (curr !=NULL){
        printf("(%p, %d, %p)   ",curr,curr->data,curr->next);
        curr = curr ->next;
    }

    struct NODE *head2 = malloc(sizeof(struct NODE));
    head2->next = NULL;
    curr = head2;

    while (!feof(fp2)){
        fscanf(fp2, "%d", &num);
        addNode(curr, num);
        curr = curr->next;
    }

    curr = head2->next;
    printf("\n\nSecond:\n");
    while (curr != NULL){
        printf("(%p, %d, %p)   ", curr, curr->data, curr->next);
        curr = curr->next;
    }

    concatenate(head1, head2);
    curr = head1->next;
    printf("\n\nConcatenate:\n");
    while (curr != NULL)
    {
        printf("(%p, %d, %p)   ", curr, curr->data, curr->next);
        curr = curr->next;
    }

    invert(head1);
    curr = middle;
    printf("\n\nInvert:\n");
    while (curr != NULL)
    {
        printf("(%p, %d, %p)   ", curr, curr->data, curr->next);
        curr = curr->next;
    }
}
