#include "stack.h"
#include "heap_usage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Element iftoe (int i, float f);
#include <sys/time.h>
struct timeval t1, t2;

int main(int argc, char *argv[])
{
    double time_taken=0,time_taken2=0,total_time=0;
    FILE *fp;
    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }

    char *line = malloc(100); 
    /* 
    Here we used malloc() and not myalloc() because as do not want to track 
    the memory usage of the line variable. We only want to track the heap
    usage of the stack.
    */

    /*
        Write code to initialize a stack and a time-performance variable
    */
    gettimeofday(&t1, NULL);
    Stack* testStack = newStack();
    gettimeofday(&t2, NULL);
    time_taken = (time_taken + t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken+ (t2.tv_usec - t1.tv_usec)) * 1e-6;
    int score = 0;
    float cg = 0;
    int i = 0;
    gettimeofday(&t1, NULL);
    while(fgets(line, 100, fp) != NULL)
    {
        char *token;
        token = strtok(line, ",");
        score = atoi(token);
        token = strtok(NULL, ",");
        cg = atof(token);
       // printf("%d: Score: %d, CG: %f\t", i, score, cg);
        // You can uncomment the above line to print the values read from the file

        /*
            Write code to push the score and cg values into the stack while tracking the time and heap performance
        */
        push(testStack,iftoe(score,cg));
        i++;
    }
    gettimeofday(&t2, NULL);
        time_taken = (time_taken + (t2.tv_sec - t1.tv_sec)) * 1e6;
        time_taken = (time_taken+ (t2.tv_usec - t1.tv_usec)) * 1e-6;
    fclose(fp);

    /*
        Write code to print the time taken and heap space utilized for pushing the values into the stack
    */
    printf("\nheap usage when pushing : %lu",heapMemoryAllocated);
    printf("\nstack filling took %f seconds to execute", time_taken);
    size_t maxHeapMeomry = heapMemoryAllocated;

    /*
        Write code to empty the stack and print and measure the time taken for the emptying process
    */
    gettimeofday(&t1, NULL);
    while (!(isEmpty(testStack)))
    {
        pop(testStack);
        //printf("popped");
    }
    gettimeofday(&t2, NULL);   
    time_taken2 = (time_taken2 + (t2.tv_sec - t1.tv_sec)) * 1e6;
    time_taken2 = (time_taken2 + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("\n stack emptying took %f seconds to execute", time_taken2);
    

    /*
        Print the total time taken for the entire process and the maximum heap usage throughout the process
    */
    freeStack(testStack);
    printf("\nheap usage at end : %lu",heapMemoryAllocated);
    printf("\n total time %f seconds", (time_taken+time_taken2));
}
Element iftoe(int i, float f)
{
    Element e;
    e.int_value = i;
    e.float_value = f;
    return e;
}