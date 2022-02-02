#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

#define FALSE 0
#define TRUE 1

typedef enum{ lparen, rparen, plus, minus, times, divide, mod, eos, operand} precedence;

int stack[MAX_SIZE]; //수식에 대한 스택
char infix[MAX_SIZE]={'\0',}; //수식을 저장하는 문자배열

precedence get_token(char* symbol, int* n){
    switch (*symbol = infix[(*n)++]){
    case '(' : return lparen;
    case ')' : return rparen;
    case '+' : return plus;
    case '-' : return minus;
    case '*' : return times;
    case '/' : return divide;
    case '%' : return mod;
    case '\0' : return eos;
    default : return operand;
    }
}

const int isp[] = {0, 19, 12, 12, 13, 13, 13,0};
const int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

int eval(void);
void stack_push(int* top, int item);
int stack_pop(int* top);
void postfix(void);
void print_token(precedence token, char** str);


//후위 표현 수식 계산
int eval(){ 
    precedence token;
    char symbol;
    int op1, op2;
    int n=0;
    int top = -1;

    token = get_token(&symbol, &n);
    while (token != eos){
        if (token == operand)
            stack_push(&top, symbol-'0');
        else{
            op2 = stack_pop(&top);
            op1 = stack_pop(&top);
            switch (token){
                case plus : 
                    stack_push(&top, op1+op2);
                    break;
                case minus:
                    stack_push(&top, op1 - op2);
                    break;
                case times:
                    stack_push(&top, op1 * op2);
                    break;
                case divide:
                    stack_push(&top, op1 / op2);
                    break;
                case mod:
                    stack_push(&top, op1 % op2);
                    break;
                default:
                    break;
            }
        }
        token = get_token(&symbol, &n);
    }
    return stack_pop(&top);
}


//스택 푸쉬
void stack_push(int* top, int item){    
    if ((*top) ==MAX_SIZE){
        fprintf(stderr, "The stack is full! \n"); //버퍼 방지
        exit(1);
    }
    stack[++(*top)] = item;
}

//스택 팝
int stack_pop(int* top){
    if((*top) ==-1 )
        return eos;
    return stack[(*top)--];
}

//후위 표현 변환
void postfix() {    

    char symbol;
    char postfix[MAX_SIZE] = {0,};
    char* str = postfix;
    precedence token;
    int n=0, top =0;

    stack[0] = eos;

    for (token=get_token(&symbol, &n) ; token!=eos ; token = get_token(&symbol, &n)){

        if (token == operand){
            *str++ = symbol;
        }
        else if (token == rparen){
            while (stack[top] != lparen)
                print_token(stack_pop(&top), &str)
;
            stack_pop(&top);
        }

        else{
            while (isp[stack[top]]>=icp[token])
                print_token(stack_pop(&top), &str);
            stack_push(&top, token);
        }
    }

    while ( (token = stack_pop(&top)) != eos && top > -1)
        print_token(token,&str);

    printf("Postfix: %s\n", postfix);
    strcpy(infix, postfix);
}

//토큰 -> 연산자 문자로 삽입
void print_token(precedence token, char** str){
    switch(token)
    {
        case plus: *(*str)++ = '+';
            return;
        case minus: *(*str)++ = '-';
            return;
        case divide: *(*str)++ = '/';
            return;
        case times: *(*str)++ = '*';
            return;
        case mod: *(*str)++ = '%';
            return;
        case eos : return;
        default : return;
    }
}
//------------------------------------------------------
int main(){

    FILE *fp = fopen("input.txt","r");
    
    int i=0;
    char buf;

    while (!feof(fp)){
        infix[i] = fgetc(fp);
        i++;
        if (fread(&buf,1,1,fp)==0) break;
        else fseek(fp,-1,SEEK_CUR);
    }

    int j=0;
    while (infix[j]!='\0'){
        printf("%c", infix[j]);
        j++;
    }
    printf("\n");
        
        
    
    postfix();
    printf("Result: %d", eval());

    fclose(fp);
    return 0;
}