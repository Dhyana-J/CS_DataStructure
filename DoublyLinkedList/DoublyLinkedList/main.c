//
//  main.c
//  DoublyLinkedList
//
//  Created by Kaala on 2022/12/30.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ascending order doubly linked list
// 양방에서 접근 가능하지만, 그만큼 포인터가 사용되므로 메모리 잡아먹음

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;


Node *head, *tail;


void insert(int data){
    Node* node = (Node*)malloc(sizeof(Node)); //node to insert
    node->data = data;
    Node *cur;
    cur = head->next;
    while(cur->data < data && cur!=tail){
        cur = cur->next;
    }
    Node *prev = cur->prev;
    prev->next = node;
    node->prev = prev;
    cur->prev = node;
    node->next = cur;
}


void removeFront(){
    Node *target = head->next;
    Node *next = target->next;
    head->next = next;
    next->prev = head;
    free(target);
}

void show(){
    Node* cur = head->next;
    while(cur!=tail){
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("\n");
}


int main(int argc, const char * argv[]) {
    head = (Node*)malloc(sizeof(Node));
    tail = (Node*)malloc(sizeof(Node));
    
    head->next = tail;
    tail->prev = head;
    
    insert(1);
    insert(3);
    insert(2);
    insert(9);
    insert(5);
    removeFront();
    show();
    
    return 0;
}
