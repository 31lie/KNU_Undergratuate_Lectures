#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node *treePointer;
typedef struct node {
    char data;
    treePointer leftChild, rightChild;
} node;

treePointer Create() {
    treePointer node = (treePointer) malloc(sizeof(*node));
    node -> rightChild = NULL;
    node -> leftChild = NULL;

    return node;
}

void preorder(treePointer ptr){
    if (ptr) {
        printf("%c",ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

void postorder(treePointer ptr){
    if (ptr) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        printf("%c", ptr->data);
    }
}

void inorder(treePointer ptr){
    if (ptr){
        inorder(ptr->leftChild);
        printf("%c", ptr->data);
        inorder(ptr->rightChild);
    }
}

int main(){

    treePointer root = Create();
    treePointer N1 = Create();
    treePointer N2 = Create();
    treePointer N3 = Create();
    treePointer N4 = Create();
    treePointer N5 = Create();
    treePointer N6 = Create();
    treePointer N7 = Create();
    treePointer N8 = Create();

    root -> data = '+' ;
    N1 -> data = '*' ; 
    N2 -> data = 'E';
    N3 -> data = '*';
    N4 -> data = 'D';
    N5 -> data = '/';
    N6 -> data = 'C';
    N7 -> data = 'A';
    N8 -> data = 'B';

    root -> leftChild = N1; root -> rightChild = N2;
    N1 -> leftChild = N3; N1 -> rightChild = N4;
    N3 -> leftChild = N5; N3->rightChild = N6;
    N5 -> leftChild = N7; N5->rightChild = N8; 

    printf("Preorder:   ");
    preorder(root);
    printf("\n");
    printf("Inorder:   ");
    inorder(root);
    printf("\n");
    printf("Postorder:   ");
    postorder(root);

}