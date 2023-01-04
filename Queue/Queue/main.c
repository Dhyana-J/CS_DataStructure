//
//  main.c
//  Queue
//
//  Created by Kaala on 2023/01/04.
//

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
#define INF 99999999

// Front Data... Rear

/*
 // Queue using Array
 
 int queue[SIZE];
 int front = 0;
 int rear = 0;
 
 void push(int data){
 if (rear>=SIZE){
 printf("큐 오버플로우 발생\n");
 return;
 }
 queue[rear++] = data;
 }
 
 int pop(){
 if (front==rear){
 printf("큐 언더플로 발생\n");
 return -INF;
 }
 return queue[front++];
 }
 
 void show(){
 printf("Front ");
 for (int i = front; i<rear; i++){
 printf("%d ",queue[i]);
 }
 printf("Rear\n");
 }
 
 int main(int argc, const char * argv[]) {
 push(10);
 push(9);
 push(11);
 push(20);
 pop();
 show();
 return 0;
 }
 */

// Queue using LinkedList

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Queue{
    Node *front;
    Node *rear;
    int count;
}Queue;


void push(Queue *queue, int data){
    Node *node = (Node*)malloc(sizeof(Node)); // 큐에 들어갈 데이터박스
    node->data = data;
    node->next = NULL;
    if(queue->count == 0){ //큐에 데이터가 없을 경우, 첫 데이터는 프론트와 리어 둘다 겸함
        queue->front = node;
    } else {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->count++;
}

int pop(Queue *queue){
    if(queue->count == 0){
        printf("큐 언더플로 발생\n");
        return -INF;
    }
    Node *node = queue->front; //여기서 변수 사용 안하면 메모리해제를 못해줌
    int data = node->data;
    queue->front = node->next;
    free(node);
    queue->count--;
    return data;
}

void show(Queue *queue){
    Node *cur = queue->front;
    printf("Front ");
    while(cur!=NULL){
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("Rear\n");
}

int main(){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;
    push(queue,10);
    push(queue,9);
    push(queue,11);
    push(queue,20);
    pop(queue);
    show(queue);
    return 0;
}
