#include "element.h"
#include "stack.h"
#include <stdlib.h>
#include"heap_usage.h"
#define STACK_SIZE 1000
struct Stack
{
int top;
Element data[STACK_SIZE];
};
Stack *newStack()
{
Stack *s = (Stack *)myalloc(sizeof(Stack));
if(s != NULL)
s->top = -1;
return s;
}
bool push(Stack *s, Element e)
{
if(s->top == STACK_SIZE - 1)
return false;
s->data[++(s->top)] = e;
return true;
}
Element *top(Stack *stack){
    return &(stack->data[(stack->top)]);
}
// Returns a pointer to the top element. Returns NULL if stack is empty
bool pop(Stack *s)
{
    if(s->top == - 1)
    return false;
    (s->top)--;
    return true;
}
// Pops the top element and returns true. Returns false if stack is empty
bool isEmpty(Stack *s)
{
     if(s->top == - 1) return true;
     return false;
}
// Returns true if stack is empty. Returns false otherwise
void freeStack(Stack *stack)
{
    myfree(stack);
}