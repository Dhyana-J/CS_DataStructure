//
//  main.c
//  CalculatorUsingStack
//
//  Created by Kaala on 2023/01/02.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define INF 99999999


typedef struct Node{
    char data[100];
    struct Node *next;
} Node;

typedef struct Stack{
    Node* top;
} Stack;

void push(Stack *stack, char *data){
    Node *node = (Node*)malloc(sizeof(Node));
    strcpy(node->data, data);
    node->next = stack->top;
    stack->top = node;
}

char* getTop(Stack *stack){
    Node *top = stack->top;
    return top->data;
}

char* pop(Stack *stack){
    if (stack->top == NULL){
        printf("스택 언더플로우 발생\n");
        return NULL;
    }
    Node *node = stack->top;
    char *data = (char*)malloc(sizeof(char)*100);
    strcpy(data,node->data);
    stack->top = node->next;
    free(node);
    return data;
}

int getPriority(char *i){
    if(!strcmp(i, "(")) return 0; //strcmp : 문자열이 일치하면 0을 반환함
    if(!strcmp(i, "+") || !strcmp(i, "-")) return 1;
    if(!strcmp(i, "*") || !strcmp(i, "/")) return 2;
    return 3;
}


char* transition(Stack *stack, char **s, int size){ // **s 는 문자열(피연산자, 연산자)들의 배열
    char resultString[1000] = "";
    for (int i = 0; i<size; i++){
        if(!strcmp(s[i],"+")||!strcmp(s[i],"-")||!strcmp(s[i],"*")||!strcmp(s[i],"/")){
            while(stack->top != NULL && getPriority(getTop(stack)) >= getPriority(s[i]) ){
                strcat(resultString,pop(stack));
                strcat(resultString," ");
            }
            push(stack,s[i]);
        }
        else if (!strcmp(s[i],"(")) push(stack,s[i]);
        else if (!strcmp(s[i],")")){
            while(strcmp(getTop(stack),"(")){ // "("가 나올 때 까지 반복
                strcat(resultString,pop(stack));
                strcat(resultString," ");
            }
            pop(stack);
        }
        else {strcat(resultString, s[i]); strcat(resultString," ");} // 숫자인 경우
    }
    while(stack->top != NULL){
        strcat(resultString,pop(stack)); strcat(resultString," ");
    }
    return resultString;
}


void calculate(Stack *stack, char **s, int size){
    int x,y,z;
    for(int i=0; i<size; i++){
        if(!strcmp(s[i],"+")||!strcmp(s[i],"-")||!strcmp(s[i],"*")||!strcmp(s[i],"/")){
            x = atoi(pop(stack)); // atoi? ASCII to INT
            y = atoi(pop(stack));
            if(!strcmp(s[i],"+")) z = y + x;
            if(!strcmp(s[i],"-")) z = y - x;
            if(!strcmp(s[i],"*")) z = y * x;
            if(!strcmp(s[i],"/")) z = y / x;
            char buffer[100];
            sprintf(buffer, "%d", z); // 계산된 숫자 형태의 결과를 문자로 바꿈
            push(stack, buffer);
        }
        else {
            push(stack,s[i]);
        }
    }
    printf("%s ",pop(stack));
}


int main(int argc, const char * argv[]) {
    
    Stack stack;
    stack.top = NULL;
    
    char a[100] = "( ( 3 + 4 ) * 5 ) - 5 * 7 * 5 - 5 * 10";
//    char a[100] = "( 3 + 5 ) + 2 * 7 * 2 - 10 * 3";
    
    
    //후위표기변환과정
    int size = 1;
    for(int i=0; i<strlen(a); i++){ // 문자열 a에 저장된 문자 개수 세팅
        if (a[i] == ' ') size++;
    }
    char *ptr = strtok(a, " ");
    char **input = (char**)malloc(sizeof(char*)*size); //후위표기법, 계산기 입력값으로 쓰일 변수
    for(int i=0; i<size; i++){
        input[i] = (char*)malloc(sizeof(char)*100);
    }
    for(int i=0; i<size; i++){
        strcpy(input[i],ptr); // 공백 이전 문자열을 input[i]에 담음
        ptr = strtok(NULL, " ");
    }
    char b[1000] = "";
    strcpy(b,transition(&stack,input,size));
    printf("후위 표기법: %s\n",b);
    
    
    //계산과정
    size = 1;
    for(int i=0; i<strlen(b)-1; i++){// 마지막 공백 제거해야하므로 -1해줌
        if(b[i]== ' ') size++;
    }
    char *ptr2 = strtok(b," ");
    for(int i=0; i<size; i++){
        strcpy(input[i],ptr2);
        ptr2 = strtok(NULL, " ");
    }
    calculate(&stack,input,size);
    printf("\n");
    
    return 0;
}

