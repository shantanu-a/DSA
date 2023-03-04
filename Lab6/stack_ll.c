#include "stack.h"
#include "linked_list.h"
#include "linked_list.c"
#include "heap_usage.h"

struct Stack{
    LIST top;
};
 

Stack* newStack(){
    Stack *s = (Stack *)myalloc(sizeof(Stack));
    LIST list=createNewList();
    s->top=list;
    return s;
}

bool push(Stack *stack, Element element){
    NODE node=createNewNode(element);
    insertNodeIntoList(node,stack->top);
    return true;
}

Element *top(Stack *stack){
    LIST l1=stack->top;
    NODE n1=l1->head;
    return &(n1->data);
}

bool pop(Stack *stack){
    LIST l1=stack->top;

    if(l1->count==0){
        return false;
    }

    removeFirstNode(l1);
    return true; 
}

bool isEmpty(Stack *stack){
    LIST l1=stack->top;

    if(l1->count==0){
        return true;
    }
    return true;
}

void freeStack(Stack *stack){
    LIST l1=stack->top;
    destroyList(l1);
    myfree(stack);
}