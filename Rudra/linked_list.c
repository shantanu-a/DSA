#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"
#include"heap_usage.h"

LIST createNewList()
{
LIST myList;
myList = (LIST) myalloc(sizeof(linked_list));
myList->count=0;
myList->head=NULL;
return myList;
}
// This function allocates memory for a new list and returns a pointer to it.
// The list is empty and the count is set to 0.

NODE createNewNode(Element data)
{
    NODE myNode;
myNode = (NODE) myalloc(sizeof(node));
(myNode->data)= data;
myNode->next=NULL;
return myNode;
}
// This function allocates memory for a new node and returns a pointer to it.
// The next pointer is set to NULL and the data is set to the value passed in.

void insertNodeIntoList(NODE n1, LIST l1)
{
     n1->next=l1->head;
    l1->head=n1;
    (l1->count)++;
}
// This function inserts a node at the beginning of the list.

void removeFirstNode(LIST l1)
{
    if(l1->count==0)
    {
        printf("not possible");
        return ;
    }
    NODE temp = l1->head;
    l1->head= temp->next;
    myfree(temp);
    (l1->count)--;
}
// This function removes the first node from the list.

void insertNodeAtEnd(NODE node, LIST list)
{
  NODE temp = list->head;
  while(temp->next!= NULL)
  {
    temp=temp->next;
  }  
  temp->next=node;
  node->next=NULL;
}
// This function inserts a node at the end of the list.

void destroyList(LIST list)
{
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
