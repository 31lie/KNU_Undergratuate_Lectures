#include <stdio.h>
#include <stdlib.h>

typedef struct node *treePointer;
typedef struct node {
    int key;
    treePointer leftChild, rightChild;
} node;

node* modifiedSearch(treePointer tree, int key){
    if (!tree) return NULL;
    while (tree){
        if (key == tree->key) return NULL;

        if (key < tree->key) {
            if (tree->leftChild ==NULL) return tree;
            tree = tree->leftChild;
        }
        else { 
            if(tree->rightChild ==NULL) return tree;
            tree = tree->rightChild;
        }
    }
    return tree;
}

treePointer iterSearch(treePointer tree, int k){
    while (tree){
        if (k == tree->key)
            return tree;
        if (k < tree->key)
            tree = tree->leftChild;
        else
            tree = tree->rightChild;
    }
    return NULL;
}

void insert(treePointer *node, int k) {
    treePointer ptr;
    treePointer temp = modifiedSearch(*node, k);
    if (temp || !(*node)) {
        ptr = (treePointer) malloc(sizeof(*ptr));
        ptr -> key = k;
        ptr -> leftChild = ptr -> rightChild = NULL;
        if (*node) {
            if (k<temp->key) temp -> leftChild = ptr;
            else temp -> rightChild = ptr;
        }
        else *node = ptr;
    }
}

void inorder(treePointer ptr){
    if (ptr) {
        inorder(ptr->leftChild);
        printf(" %d ", ptr->key);
        inorder(ptr->rightChild);
    }
}

void preorder(treePointer ptr){
    if (ptr) {
        printf(" %d ", ptr->key);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

void postorder(treePointer ptr){
    if (ptr) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        printf(" %d ", ptr->key);
    }
}

int main() {

    FILE *fp = fopen("input1.txt","r");
    FILE *fsearch = fopen("input2.txt","r");

    if (fp==NULL || fsearch ==NULL) {
        fprintf(stderr,"File Open Error!");
        exit(EXIT_FAILURE);
    }

    treePointer searchTree = NULL;

    int temp_key;
    while (!feof(fp)) {
        fscanf(fp,"%d",&temp_key);
        insert(&searchTree,temp_key);
    }

    printf("Preorer: ");
    preorder(searchTree);
    printf("\n");

    printf("Inorder: ");
    inorder(searchTree);
    printf("\n");

    printf("PostOrder: ");
    postorder(searchTree);
    printf("\n");

    printf("Search: ");
    int find;
    while (!feof(fsearch)) {
        fscanf(fsearch,"%d",&find);
        if (iterSearch(searchTree,find)) {
            printf(" 1 ");
        }
        else
            printf(" 0 ");

    }

    fclose(fp);
    fclose(fsearch);

    return 0;
}