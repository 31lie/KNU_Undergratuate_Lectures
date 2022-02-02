#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int divisionSum(int x)
{
    int sum=0;
    for (int i=1;i<x;i++){
        if (x%i==0){
            sum= sum+i;
        }
    }
    return sum;
}

int main(){
    
    int num1, num2;
    printf("First number: ");
    scanf("%d",&num1);
    printf("Second number: ");
    scanf("%d", &num2);

    if (divisionSum(num1)==num2 && divisionSum(num2) ==num1){
        printf("Amicable");
    }
    else{
        printf("Not Amicable");
    }
    return 0;
}