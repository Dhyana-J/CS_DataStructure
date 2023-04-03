//
//  main.c
//  BinaryTree
//
//  Created by Kaala on 2023/04/03.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node* initNode(int data, Node* leftChild, Node* rightChild) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->leftChild = leftChild;
    node->rightChild = rightChild;
    return node;
}

//preorder traversal : root->left->right
void preOrder(Node *root){
    if(root){
        printf("%d ",root->data);
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
}

//inorder traversal : left->root->right
void inOrder(Node *root){
    if(root){
        inOrder(root->leftChild);
        printf("%d ",root->data);
        inOrder(root->rightChild);
    }
}

//postorder traversal : left->right->root
void postOrder(Node *root){
    if(root){
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        printf("%d ",root->data);
    }
}

int main(void){
    Node* n7 = initNode(50, NULL, NULL);
    Node* n6 = initNode(37, NULL, NULL);
    Node* n5 = initNode(23, NULL, NULL);
    Node* n4 = initNode(5, NULL, NULL);
    Node* n3 = initNode(48, n6, n7);
    Node* n2 = initNode(17, n4, n5);
    Node* n1 = initNode(30, n2, n3);
    preOrder(n1);
    printf("\n");
    inOrder(n1);
    printf("\n");
    postOrder(n1);
    printf("\n");
    return 0;
}
