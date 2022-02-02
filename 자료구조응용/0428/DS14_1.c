#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int front = -1;
int rear = -1;
int tree[MAX_SIZE];

typedef struct node *treePointer;
typedef struct node
{
    int data;
    treePointer leftChild, rightChild;
} node;

treePointer queue[MAX_SIZE];

treePointer Create(int data)
{
    treePointer node = (treePointer)malloc(sizeof(*node));
    node->data = data;
    node->rightChild = NULL;
    node->leftChild = NULL;
    return node;
}

void Connect(treePointer t1, treePointer t2, treePointer t3)
{
    t1->leftChild = t2;
    t1->rightChild = t3;
}

void addq(treePointer ptr)
{
    queue[++rear] = ptr;
}

treePointer deleteq()
{
    return queue[++front];
}

void preorder(treePointer ptr)
{
    if (ptr)
    {
        printf("%d ", ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

void postorder(treePointer ptr)
{
    if (ptr)
    {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        printf("%d ", ptr->data);
    }
}

void inorder(treePointer ptr)
{
    if (ptr)
    {
        inorder(ptr->leftChild);
        printf("%d ", ptr->data);
        inorder(ptr->rightChild);
    }
}

int main()
{
    FILE *fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        fprintf(stderr, "File Open Error!");
        exit(EXIT_FAILURE);
    }

    int temp;
    int i;
    int treeSize = 0;

    treePointer temp1, temp2, temp3, root;

    while (!feof(fp))
    {
        fscanf(fp, "%d", &temp);
        if (temp != -1)
        {
            tree[++treeSize] = temp;
            addq(Create(temp));
        }
        else
        {
            tree[++treeSize] = temp;
            addq(NULL);
        }
    }

    printf("Level order: ");
    for (int j = 1; j <= treeSize; j++)
    {
        if (tree[j] != -1)
            printf("%3d", tree[j]);
    }
    printf("\n");
    
    temp1 = deleteq();
    i = front;
    root = temp1;
    temp2 = queue[++i];
    temp3 = queue[++i];

    while (i <= treeSize)
    {
        Connect(temp1, temp2, temp3);
        temp1 = deleteq();
        temp2 = queue[++i];
        temp3 = queue[++i];
    }

    printf("Preorder:   ");
    preorder(root);
    printf("\n");

    printf("Inorder:   ");
    inorder(root);
    printf("\n");

    printf("Postorder:   ");
    postorder(root);
    printf("\n");

    return 0;
}