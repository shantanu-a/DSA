#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <sys/time.h>
#include "queue.h"
#include "element.h"
#include "heap_usage.h"
#define ARRAY_SIZE 1000

Element itoe (int i);

int main(){
    //functions to measure time taken
    struct timeval t1,t2;
    double time_taken;
    gettimeofday(&t1,NULL);
    //end
    
    Queue *q = createQueue();
    if(isEmpty(q))
        printf("Queue is empty\n");
    
    enqueue(q, itoe(1));
    int value = front(q)->int_value;
    printf("Front of queue is %d\n", value);

    enqueue(q, itoe(2));
    value = front(q)->int_value;
    printf("Front of queue is %d\n", value);

    value = front(q)->int_value;
    printf("Front of queue is %d\n", value);
    
    dequeue(q);

    value = front(q)->int_value;
    printf("Front of queue is %d\n", value);
    printf("Dequeue returned %s\n", dequeue(q)?"true":"false");

    printf("Trying to dequeue an empty queue\n");
    printf("Dequeue returned %s\n", dequeue(q)?"true":"false");

    printf("The heap memory used is:%ld \n",heapMemoryAllocated);

    //freeQueue(s);

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