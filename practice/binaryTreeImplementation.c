#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

typedef struct node* Node;

typedef struct node{
    int data;
    Node left;
    Node right;
}node;


Node create(int data){
    Node n=malloc(sizeof(node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;

    return n;
}

void insert(node n){
    
}


