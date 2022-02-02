#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100


void fail(char* pat, int F[]){
    
    int i, j;
    int n = strlen(pat);
    F[0] = -1;
    for (i=1 ; i < n; i++){
        j = F[i-1]+1;
        while(pat[i] != pat[j] && j>0){
            j = F[j-1]+1;
        }
        if (pat[i] == pat[j])
            F[i]=j;
        else  
            F[i] = -1;
    }   
    
}



int main(){
    

    FILE *fp = fopen("input.txt","r");

    if (fp==NULL){
        printf("File Open Error!");
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    
    char *string = calloc(size, sizeof(char));
    char *pat = calloc(size, sizeof(char));

    fscanf(fp, "%s %s",string, pat);
    int patSize = strlen(pat); //10


    printf("Failure function:\n");
    printf("%5c", 'j');

    for (int i=0; i<patSize;i++){
        printf("%3d",i);
    }
    printf("\n");
    printf("%5s","pat");
    for (int i = 0; i < patSize; i++)
    {
        printf("%3c", pat[i]);

    }
    printf("\n");

    int F[MAX_LEN]={0,};
    fail(pat, F);
    printf("%5c", 'f');

    for (int i = 0; i < patSize; i++)
    {
        printf("%3d", F[i]);
    }
    printf("\n");

    int count=0;
    int match =0;

    for (unsigned s=0, f=0 ; s < strlen(string);){
        count++;
        while (string[s] == pat[f] && strlen(pat)){
            count++;
            s++;
            f++;
        }

        if (f>strlen(pat)-1){
            match = s-f;
            f = F[f-1];
        }
        else{
            if (F[f]==0)
                f=0;
            else if (F[f]>0)
                f=F[f]-1;
            s++;
        }
    }

    printf("The pattern %s is found at the position %d",pat,match);


    free(string);
    free(pat);
    fclose(fp);


    return 0;
}