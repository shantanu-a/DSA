#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>

typedef struct node * NODE;
struct node{
    int ele;
    NODE next;
};


typedef struct linked_list * LIST;
struct linked_list{
    int count;
    NODE head;
};


LIST createNewList()
{
    LIST myList;
    myList = (LIST) malloc(sizeof(struct linked_list));
    myList->count=0;
    myList->head=NULL;
    return myList;
}


NODE createNewNode(int value)
{
    NODE myNode;
    myNode = (NODE) malloc(sizeof(struct node));
    myNode->ele=value;
    myNode->next=NULL;
    return myNode;
}



// Recursive function to compute sum of integers in a linked list
long long llSumNTR(NODE head)
{
    if (head == NULL)
        return 0;
    long long sum=head->ele + llSumNTR(head->next);
    return sum; // Pay close attention here
}

// This is just a wrapper function to take LIST as input, but run the recursive sum function on its NODEs starting from the head
long long llSumNTRWrapper(LIST list)
{
    long long sum=llSumNTR(list->head);
    return sum;
}

long long llSumTR(NODE node,int acc){
    if(node==NULL)return acc;
    return llSumTR(node->next,(acc+node->ele));
}

long long llSumTRWrapper(LIST list){
    return llSumTR(list->head,0);
}

long long llSumIterative(NODE node){
    int acc=0;
    while(node!=NULL){
        acc+=node->ele;
        node=node->next;
    }
    return acc;
}

long long llSumIterativeWrapper(LIST list){
    return llSumIterative(list->head);
}

// Driver code
int main()
{
    // Reads the file numbers1000.txt and creates a linked list with those integers
    FILE *fp;
    fp = fopen("numbers10000.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    int num;
    LIST myList = createNewList();
    while (fscanf(fp, "%d", &num) != EOF)
    {
        NODE myNode = createNewNode(num);
        myNode->next = myList->head;
        myList->head = myNode;
        myList->count++;
    }
    fclose(fp);

    struct timeval t1,t2,t3,t4,t5,t6;
    double time_taken;

    gettimeofday(&t1,NULL);
    long long sum=llSumNTRWrapper(myList);
    printf("%lld\t",llSumNTRWrapper(myList));
    gettimeofday(&t2,NULL);
    time_taken = ((t2.tv_sec) - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("%lf\n",time_taken);

    gettimeofday(&t3,NULL);
    printf("%lld\t",llSumTRWrapper(myList));
    gettimeofday(&t4,NULL);
    time_taken = ((t4.tv_sec) - t3.tv_sec) * 1e6;
    time_taken = (time_taken + (t4.tv_usec - t3.tv_usec)) * 1e-6;
    printf("%lf\n",time_taken);

    gettimeofday(&t5,NULL);
    printf("%lld\t",llSumIterativeWrapper(myList));
    gettimeofday(&t6,NULL);
    time_taken = ((t6.tv_sec) - t5.tv_sec) * 1e6;
    time_taken = (time_taken + (t6.tv_usec - t5.tv_usec)) * 1e-6;
    printf("%lf\n",time_taken);
}



