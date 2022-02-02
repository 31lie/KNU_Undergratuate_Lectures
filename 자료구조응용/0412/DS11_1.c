#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct polyNode *polyPointer;
typedef struct polyNode
{
    int coef;
    int expon;
    polyPointer link;
} polyNode;

void attach(int coef, int expon, polyPointer *ptr)
{
    polyPointer temp = (polyPointer)malloc(sizeof(polyNode));
    temp->coef = coef;
    temp->expon = expon;
    (*ptr)->link = temp;
    *ptr = temp;
}

void printList(polyPointer list)
{
    printf("%dx^%d", list->coef, list->expon);
    list = list->link;
    for (; list; list = list->link)
    {
        if ((list->coef) < 0)
            printf(" %dx^%d", list->coef, list->expon);
        else if (list->expon == 0)
            printf(" + %d", list->coef);
        else
            printf(" + %dx^%d", list->coef, list->expon);
    }
    printf("\n");
}

int COMPARE(int x, int y) {
    if (x > y) {
        return 1;
    } else if (x == y) {
        return 0;
    } else {
        return -1;
    }
}

polyPointer padd(polyPointer a, polyPointer b)
{
    polyPointer c, rear, temp;
    int sum;
    rear = (polyPointer)malloc(sizeof(polyNode));
    c = rear;
    while (a && b)
    {
        switch (COMPARE(a->expon, b->expon))
        {
        case -1:
                attach(b->coef, b->expon,&rear);
                b = b->link;
                break;
        case 0:
            sum = a->coef + b->coef;
            if (sum) attach(sum, a->expon, &rear);
            a = a->link; b= b->link; break;
        case 1:
            attach(a->coef, a->expon, &rear);
            a = a->link;
        }
    }
    for (; a; a = a->link)
        attach(a->coef, a->expon, &rear);
    for (; b; b = b->link)
        attach(b->coef, b->expon, &rear);
    rear->link = NULL;
    temp = c;
    c = c->link;
    free(temp);
    return c;
}

int main()
{
    polyPointer a = (polyPointer)malloc(sizeof(polyNode));
    polyPointer b = (polyPointer)malloc(sizeof(polyNode));
    polyPointer rear = a;

    FILE *fa = fopen("a.txt", "r");
    FILE *fb = fopen("b.txt", "r");

    if (fa == NULL || fb == NULL)
    {
        printf("File Open Error!");
    }

    int aSize;
    int bSize;

    int coefficient, exponent;

    fscanf(fa, "%d", &aSize);
    fscanf(fb, "%d", &bSize);

    for (int i = 0; i < aSize; i++)
    {
        fscanf(fa, "%d", &coefficient);
        fscanf(fa, "%d", &exponent);
        attach(coefficient, exponent, &rear);
    }

    rear = b;
    for (int i = 0; i < bSize; i++)
    {
        fscanf(fb, "%d", &coefficient);
        fscanf(fb, "%d", &exponent);
        attach(coefficient, exponent, &rear);
    }

    printList(padd(a, b));
}