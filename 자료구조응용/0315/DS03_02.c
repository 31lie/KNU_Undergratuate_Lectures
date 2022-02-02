#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(){

    char input[11];
    int ISBN[10];

    printf("ISBN: ");
    scanf("%s",input);


    if (input[9] == 'X')
        ISBN[9] = 10;

    for (int i=0;i<10;i++) {       
        if (input[i]=='?')
            ISBN[i] = 11;
        
        else if (ISBN[i]!=10){
            ISBN[i] = input[i]-'0';
        }
    }
    int sum = 0;
    int mul = 0;

    for (int i=0;i<10;i++){
        if (ISBN[i]!=11){
            sum = sum + ISBN[i]*(10-i);
        }
        else {
            mul = 10-i;
        }
    }
    
    for (int i=0;i<11;i++){
        if ((sum + mul*i)%11==0){
            if (i==10){
                printf("Missing Digit: %c", 'X');
                break;
            }
            printf("Missing Digit: %d",i);
            break;
        }
    }
    

    return 0;

}