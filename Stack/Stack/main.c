//
//  main.c
//  Stack
//
//  Created by Kaala on 2022/12/31.
//

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
#define INF 99999999

/*-- Stack using LinkedList --*/
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack{
    Node *top;
} Stack;


void push(Stack *stack, int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack *stack){
    if(stack->top == NULL){
        printf("스택 언더플로우 발생\n");
        return INF;
    }
    Node *node = stack->top;
    int data = node->data;
    stack->top = node->next;
    free(node);
    return data;
}

void show(Stack *stack){
    Node* cur = stack->top;
    printf("--- 스택의 최상단 ---\n");
    while(cur!=NULL){
        printf("%d\n",cur->data);
        cur = cur->next;
    }
    printf("--- 스택의 최하단 ---\n");
}


/* --- Stack using array
 
 int stack[SIZE]; // 메모리 공간 비효율 발생. 배열을 사용하면 미리 할당해두어야한다.
 int top = -1;
 
 void push(int data){
 if(top == SIZE-1){
 printf("스택 오버플로우 발생\n");
 return;
 }
 stack[++top] = data;
 }
 
 void pop(){
 if(top == -1){
 printf("스택 언더플로우 발생\n");
 return -INF;
 }
 stack[top--];
 }
 
 void show(){
 printf("--- 스택 상단 ---\n");
 for(int i = top; i>=0; i--){
 printf("%d\n",stack[i]);
 }
 printf("--- 스택 하단 ---\n");
 }
 
 */

int main(int argc, const char * argv[]) {
    Stack s;
    s.top = NULL;
    
//    push(10);
//    push(9);
//    push(8);
//    push(3);
//    pop();
//    push(999);
//    show();
    
    push(&s,10);
    push(&s,9);
    push(&s,8);
    push(&s,3);
    pop(&s);
    push(&s,999);
    show(&s);
    
    return 0;
}
 
 

