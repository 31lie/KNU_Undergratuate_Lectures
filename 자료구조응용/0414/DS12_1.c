#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct node *nodePointer;

typedef struct node
{
    int data;
    nodePointer link;
} node;

int main()
{

    FILE *fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        fprintf(stderr,"File Open Error!");
        return 0;
    }

    int object, pair, k;

    fscanf(fp, "%d", &object);
    fscanf(fp, "%d", &pair);

    short int *out = (short int *)calloc(object, sizeof(short int));
    nodePointer *seq = (nodePointer *)calloc(object, sizeof(nodePointer));

    for (int k = 0; k < object; k++)
    {
        out[k] = TRUE;
    }

    nodePointer x, y, top;
    int i, j;

    for (k = 0; k < pair; k++)
    {
        x = malloc(sizeof(node));
        fscanf(fp, "%d", &i);
        fscanf(fp, "%d", &j);

        x->data = j;
        x->link = seq[i];
        seq[i] = x;
        x = malloc(sizeof(node));
        x->data = i;
        x->link = seq[j];
        seq[j] = x;
    }

    for (i = 0; i < object; i++)
    {
        if (out[i] == TRUE)
        {
            printf("\nnew class: %5d", i);
            out[i] = FALSE;
            x = seq[i];
            top = NULL;
            for (;;)
            {
                while (x)
                {
                    j = x->data;
                    if (out[j] == TRUE)
                    {
                        printf("%5d", j);
                        out[j] = FALSE;
                        y = x->link;
                        x->link = top;
                        top = x;
                        x = y;
                    }
                    else
                        x = x->link;
                }
                if (!top)
                    break;
                x = seq[top->data];
                top = top->link;
            }
            
        }
    }

    free(x);
    fclose(fp);

    return 0;
}