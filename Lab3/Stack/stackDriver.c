#include "stack.h"
#include <stdio.h>
#include <sys/time.h>
#include "heap_usage.h"
#include "element.h"

Element itoe (int i);
int main()
{
    //functions to measure time taken
    struct timeval t1,t2;
    double time_taken;
    gettimeofday(&t1,NULL);
    //end
    
    Stack *s = newStack();
    if(isEmpty(s))
        printf("Stack is empty\n");
    
    push(s, itoe(1));
    int value = top(s)->int_value;
    printf("Top of stack is %d\n", value);

    push(s, itoe(2));
    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);

    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);
    
    pop(s);

    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);
    printf("Pop returned %s\n", pop(s)?"true":"false");

    printf("Trying to pop an empty stack\n");
    printf("Pop returned %s\n", pop(s)?"true":"false");

    printf("The heap memory used is:%ld \n",heapMemoryAllocated);

    freeStack(s);
    printf("The heap memory used is:%ld \n",heapMemoryAllocated);

    //functions to measure time taken
    gettimeofday(&t2, NULL);

    time_taken = ((t2.tv_sec) - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;

    printf("The tasks took %f seconds to execute\n\n", time_taken);
    //end
    return 0;
}
Element itoe (int i)
{
    Element e;
    e.int_value = i;
    e.float_value = 0;
    return e;
}