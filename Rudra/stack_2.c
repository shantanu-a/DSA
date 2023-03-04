#include"linked_list.h"
#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
#include"heap_usage.h"
# define STACK_SIZE 1000
struct Stack
{
 LIST ls;
};
Stack *newStack()
{
 Stack *mystack;
 mystack= (Stack*) myalloc(sizeof(Stack));
 mystack->ls=createNewList();
 return mystack;
}
// Returns a pointer to a new stack. Returns NULL if memory allocation fails
bool push(Stack *stack, Element element)
{
    if(stack->ls->count==STACK_SIZE)
    return false;
    NODE mynode = createNewNode(element);
    insertNodeIntoList(mynode, stack->ls);
    return true;

}
// Pushes element onto stack. Returns false if memory allocation fails
Element *top(Stack *stack)
{
    if (stack->ls->count==0)
    return NULL;
    return &(stack->ls->head->data);
}
// Returns a pointer to the top element. Returns NULL if stack is empty
bool pop(Stack *stack)
{
     if (stack->ls->count==0)
    return false;
    removeFirstNode(stack->ls);
    return true;
}
// Pops the top element and returns true. Returns false if stack is empty
bool isEmpty(Stack *stack)
{
    if ((stack->ls->count)==0)
    return true;
    return false;
}
// Returns true if stack is empty. Returns false otherwise
void freeStack(Stack *stack)
{
    destroyList(stack->ls);
    myfree(stack);
}
// Frees all memory associated with stack