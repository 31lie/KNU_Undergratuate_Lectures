#include <stdio.h>
#include <stdlib.h>

int dataNum, tableSize;
int *ht;

int h(int key) {
    return key % tableSize;
}

int *search(int k) {
    int homeBucket, currentBucket;

    homeBucket = h(k);
    for (currentBucket = homeBucket ; ht[currentBucket] && ht[currentBucket] != k; ) {
        currentBucket = (currentBucket+1) % tableSize;
        if (currentBucket == homeBucket)
            return NULL;
    }
    if (ht[currentBucket] == k)
        return &ht[currentBucket];
    return NULL;
}

void makeHT(int key) {
    int hash = h(key);
    while (ht[hash])
        hash++;
    ht[hash] = key;
}

int main() {

    FILE *fp = fopen("input.txt","r");

    if (fp==NULL) {
        fprintf(stderr, "File Open Error!");
        exit(EXIT_FAILURE);
    }

    int SerachNum;
    fscanf(fp,"%d",&tableSize);
    fscanf(fp,"%d",&dataNum);
    fscanf(fp,"%d",&SerachNum);

    ht = (int*) calloc(tableSize,sizeof(int));

    int temp;
    for (int i=0 ; i<dataNum ; i++) {
        fscanf(fp,"%d",&temp);
        makeHT(temp);
    }

    printf("Hash Table: \n");
    for (int i=0; i<tableSize ; i++) {
        if (ht[i]==0)
            printf("%d: \n", i);
        else
            printf("%d: %d\n",i,ht[i]);
    }
    printf("\n");

    int findNum;
    printf("Serach: \n");
    for (int i=0 ; i<SerachNum ; i++) {
        fscanf(fp, "%d", &findNum);
        if (search(findNum)) {
            printf("S");
        }
        else 
            printf("F");
    }

}