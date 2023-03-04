#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"
#include "queue.h"
#include "element.h"
#include "heap_usage.h"

LIST createNewList(){
    LIST l1=(LIST)myalloc(sizeof(linked_list));
    l1->count=0;
    l1->head=NULL;
    l1->tail=NULL;
    return l1;
}

NODE createNewNode(Element data){
    NODE n1=(NODE)myalloc(sizeof(node));
    n1->data=data;
    n1->next=NULL;
    return n1;
}

void insertNodeIntoList(NODE node, LIST list){
    NODE temp=list->head;
    list->head=node;
    list->tail=node;
    node->next=temp;
    list->count++;
}


void removeFirstNode(LIST list){
    NODE temp=(list->head)->next;
    list->head=temp;
    list->count--;
}

void insertNodeAtEnd(NODE node, LIST list){
    NODE temp=list->tail;
    temp->next=node;
    list->tail=temp->next;
    list->count++;
}

void destroyList(LIST list){
    NODE temp=list->head;
    NODE temp_next;

    while(list->count--){
        temp_next=temp->next;
        myfree(temp);
        temp=temp_next;
    }
    myfree(list);
}
