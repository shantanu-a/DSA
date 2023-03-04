#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "queue.h"
#include "element.h"
#include "heap_usage.h"

#define ARRAY_SIZE 3

struct Queue{
    int front;
    int rear;
    int size;
    Element data[ARRAY_SIZE];
};

Queue* createQueue(){
    Queue* q=(Queue*) myalloc(sizeof(Queue));
    q->front=-1;
    q->rear=-1;
    q->size=0;
    return q;
}

bool enqueue(Queue* q,Element element){
    if(q->size==ARRAY_SIZE)return false;

    else if(q->size==0){
        q->front=0;
        q->rear=0;
        q->data[q->rear]=element;
        q->size++;
        return true;
    }

    else if(q->rear==ARRAY_SIZE-1 && q->size!=ARRAY_SIZE){
        q->rear=0;
        q->data[q->rear]=element;
        q->size++;
        return true;
    }

    else{
        q->rear++;
        q->data[q->rear]=element;
        q->size++;
        return true;
    }
}

bool dequeue(Queue* q){
    if(q->size==0) return false;

    if(q->front==q->rear) {
        q->front=-1;
        q->rear=-1;
        q->size=0;
        return true;
    }

    else if(q->front==ARRAY_SIZE-1){
        q->front=0;
        q->size--;
        return true;
    }
    else{
        q->front++;
        q->size--;
        return true;
    }
}

Element* front(Queue* q){
    return &(q->data[q->front]);
}

int size(Queue *q){
    return q->size;
}

bool isEmpty(Queue* q){
    if(q->size==0) return true;
    return false;
}

void destroyQueue(Queue *queue){
    myfree(queue);
}


