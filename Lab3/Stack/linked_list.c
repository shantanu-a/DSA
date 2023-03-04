#include<stdio.h>
#include<stdlib.h>
#include "element.h"
#include "linked_list.h"
#include "heap_usage.h"

LIST createNewList(){
    LIST l1=(LIST)myalloc(sizeof(linked_list));
    l1->head=NULL;
    l1->count=0;
    return l1;
}

NODE createNewNode(Element data){
    NODE n1=(NODE)myalloc(sizeof(node));
    n1->next=NULL;
    n1->data=data;
    return n1;
}

void insertNodeIntoList(NODE node, LIST list){

    if(list->count==0){
        list->head=node;
        list->count++;
        return;
    }

    NODE temp=list->head;
    list->head=node;
    node->next=temp;
    list->count++;
}

void removeFirstNode(LIST list){
    if(list->count==0){
        printf("List is empty");
        return;
    }
    
    NODE temp;
    temp=(list->head)->next;
    list->head=temp;
    list->count--;
}

void destroyList(LIST list){
    if(list->count==0){
        myfree(list);
        return;
    }

    NODE temp=list->head;
    NODE forward;

    while(list->count--){
        forward=temp->next;
        myfree(temp);
        temp=forward;
    }
    myfree(list);
    
}