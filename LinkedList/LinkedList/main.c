//
//  main.c
//  LinkedList
//
//  Created by Kaala on 2022/12/29.
//

#include <stdio.h>
#include <stdlib.h>
#define INF 10000


/*---------------------------------
// 배열 기반 리스트
// 연결리스트보다 데이터 검색능력 효율적, 삽입삭제 비효율적(데이터 다 옮겨야함)

int arr[INF];
int count = 0;

void addBack(int data){
    arr[count++] = data;
}

void addFirst(int data){
    for (int i = count; i>=1; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = data;
    count++;
}

void removeAt(int index){
    for(int i = index; i < count-1; i++){ // 배열의 끝 요소는 제외시켜야함
        arr[i] = arr[i+1];
    }
    count--;
}

void show(){
    for(int i = 0; i < count; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    addBack(1);
    addFirst(0);
    addBack(10);
    addFirst(11);
    addFirst(12);
    show();
    removeAt(3);
    show();
    return 0;
}
 
 ---------------------------------*/


// 단방향 연결리스트
// 삽입 삭제 배열보다 빠름, 검색이 비효율적(배열은 인덱스가 있는데 이건 없다)

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head;

void addFront(Node *root, int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = root->next;
    root->next = node;
}

void removeFront(Node *root){
    Node *front = root->next;
    root->next = front->next;
    free(front);
}

void freeAll(Node *root){
    Node *cur = head->next;
    while(cur!=NULL){
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}

void showAll(Node *root){
    Node *cur = head->next;
    while(cur!=NULL){
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]){
    
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    
    addFront(head, 2);
    addFront(head, 9);
    addFront(head, 1);
    addFront(head, 8);
    removeFront(head);
    removeFront(head);
    showAll(head);
    freeAll(head);
    
    return 0;
}
