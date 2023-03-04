#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"
#include "queue.h"
#include "element.h"
#include "heap_usage.h"

struct Queue {
    LIST list;
};

Queue *createQueue(){
    Queue* queue=(Queue*)myalloc(sizeof(Queue));
    queue->list=createNewList();
    return queue;
}

bool enqueue(Queue *queue, Element element){
    NODE node=createNewNode(element);
    LIST l1=queue->list;
    if(l1->count==0){
        insertNodeIntoList(node,l1);
        return true;
    }
    insertNodeAtEnd(node,l1);
    return true;
}

bool dequeue(Queue *queue){
    LIST l1=queue->list;

    if(l1->count==0){
        return false;
    }
    removeFirstNode(l1);
}

Element *front(Queue *queue){
    LIST l1=queue->list;
    if(l1->count==0){
        return NULL;
    }
    Element* e1=&((l1->head)->data);
    return e1;
}

int size(Queue *queue){
    LIST l1=queue->list;
    return l1->count;
}

bool isEmpty(Queue *queue){
    LIST l1=queue->list;
    if(l1->count==0) return true;
    return false;
}

void destroyQueue(Queue *queue){
    LIST l1=queue->list;
    destroyList(l1);
    myfree(queue);
}



