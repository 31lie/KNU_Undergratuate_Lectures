#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int valid(n,k){
    if (n>=1 && n<1000000 && k<100 && k>=1){
        return 1;
    }
    else {
        return 0;
    }
}

int factorial(int n)
{   
    int output=1;
    if (n>1) {
        for (int i=n; i>0 ; i--){
            output*=i;
        }
    }
    return output;
}

int positioncheck(int n)
{
    int count=0;
    while(n!=0){
        n=n/10;
        ++count;
    }
    return count;

}

int calc(int n, int count){
    int total=0;
    int temp=0;
    int position = positioncheck(n);

    for (int i=0 ; i<position ; i++){
        temp = n%10;
        total = total + factorial(temp);
        n=n/10;
  
    }
    return total;
}



int main()
{
    int num, cnt;
    printf("N, K: ");
    scanf("%d %d",&num, &cnt);

    if (valid(num,cnt)){
        printf("%4d  ", num);
        for (int i = 0; i < (cnt - 1); i++)
        {
            num = calc(num, cnt);
            printf("%d  ", num);
        }
    }

    else{
        printf("Not valid input");
    }
}