#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linked_list.h"
#include "stack.h"
#include "heap_usage.h"
#include"element.h"
#define ADDITIONAL_MEMORY sizeof(int)
#define SIZE 7

//Linked list and stack definitions to convert recursive versions of algos to iterative using explicit stack
LIST createNewList(){
    LIST l1=(LIST)myalloc(sizeof(linked_list));
    l1->head=NULL;
    l1->count=0;
    return l1;
}

NODE createNewNode(Element data){
    NODE n1=(NODE)myalloc(sizeof(node));
    n1->next=NULL;
    n1->data=data;
    return n1;
}

void insertNodeIntoList(NODE node, LIST list){

    if(list->count==0){
        list->head=node;
        list->count++;
        return;
    }

    NODE temp=list->head;
    list->head=node;
    node->next=temp;
    list->count++;
}

void removeFirstNode(LIST list){
    if(list->count==0){
        printf("List is empty");
        return;
    }
    
    NODE temp;
    temp=(list->head)->next;
    list->head=temp;
    list->count--;
}

void destroyList(LIST list){
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


size_t heapMemoryAllocated = 0;
void *myalloc(size_t size)
{
    void *ptr = malloc(size + ADDITIONAL_MEMORY);
    if(ptr == NULL)
        return NULL;
    heapMemoryAllocated += size;
    *((int *)ptr) = size;
    return ptr + ADDITIONAL_MEMORY;
}
 
void myfree(void *ptr)
{
    int size = *((int *)(ptr - ADDITIONAL_MEMORY));
    heapMemoryAllocated -= size;
    free(ptr - ADDITIONAL_MEMORY);
}
 
//end of stack and linked list definitions



int swap(int A[],int a,int b){
    int temp=A[a];
    A[a]=A[b];
    A[b]=temp;
}

//Hoare partion algorithm

int part(int Ls[], int lo, int hi, int pInd){
    swap(Ls, pInd, lo);
    int pivPos, lt, rt, pv;
    lt = lo + 1;
    rt = hi;
    pv = Ls[lo];
    while (lt < rt){
        for (; lt <= hi && Ls[lt] <= pv; lt++);
// Ls[j]<=pv for j in lo..lt-1
        for (; Ls[rt] > pv; rt--);
// Ls[j]>pv for j in rt+1..hi
        if (lt < rt){
            swap(Ls, lt, rt);
            lt++;
            rt--;
        }
    }
    if (Ls[lt] < pv && lt <= hi) pivPos = lt;
    else pivPos = lt - 1;
    swap(Ls, lo, pivPos);
// Postcond.: (Ls[j]<=pv for j in lo..pivPos-1) and (Ls[j]>pv for j in pivPos+1..hi)
    return pivPos;
}

//Lomuto partition algorithm

int lomuto_part(int  A[],int low,int n,int pivot){
    int pivotValue=A[pivot];
    swap(A,n-1,pivot);
    int i=low;
    int j=low;

    while(j<=n-1){
        if(A[j]<=pivotValue){
            swap(A,j,i);
            i++;
        }
        j++;
    }
    swap(A,i,n-1);
    return i;
}

int three_way_partition(int A[],int low,int high,int l_value,int h_value){
    int start=low;
    int end=high-1;
    int i=0;

    while(i<=end){
        if(A[i]<l_value){
            swap(A,i,start);
            start++;
            i++;
        }
        else if(A[i]>h_value){
            swap(A,i,end);
            end--;
        }
        else{
            i++;
        }
    }
}

int qselect(int L[], int n, int k)
{
    int pivot = 0;
    int lo = 0;
    int hi = n - 1;
    int pInd = part(L, lo, hi, pivot);
    if (k <= pInd)
        return qselect(L, pInd, k);
    else if (k > pInd + 1)
        return qselect(L + pInd + 1, n - pInd - 1, k - pInd - 1);
    else
        return L[pInd];
}

int qselectIterative(int L[],int n,int k){
    int pivot = 0;
    int lo = 0;
    int hi = n - 1;
    int pInd = part(L, lo, hi, pivot);
    Stack* s=newStack();
}


//The main function has been commented out in order to the task1.c file to be able to import it partition functions. There are no errors is this file.

// int main(){
//     int A[]={3,4,6,7,8,1,2};
//     part(A,0,6,3);

//     for(int i=0;i<7;i++){
//         printf("%d\t",A[i]);
//     }
//     printf("\n");

//     int B[]={3,4,6,7,8,1,2};
//     lomuto_part(B,0,6,3);

//     for(int i=0;i<7;i++){
//         printf("%d\t",B[i]);
//     }
//     printf("\n");

//     int C[]={3,4,6,7,8,1,2};
//     three_way_partition(C,0,6,2,6);

//     int value=qselect(C,7,4);
//     printf("%d",value);

//     int k=3;
//     int lower_index=(SIZE-k)/2;
//     int higher_index=(SIZE+k)/2;

//     int lvalue=qselect(C,SIZE,lower_index);
//     int hvalue=qselect(C,SIZE,higher_index);

//     printf("%d %d\n",lvalue,hvalue);
//     three_way_partition(C,0,SIZE,lvalue,hvalue);

//     int finalLowIndex=qselect(C,SIZE,lower_index);
//     int finalHigherIndex=qselect(C,SIZE,higher_index);

//     int newArr[k+1];

//     int j=0;

//     for(int i=finalLowIndex;i<=finalHigherIndex;i++){
//         newArr[j]=C[i];
//         j++;
//     }

//     if(newArr[0]>newArr[k-1]){
//         for(int i=1;i<k;i++){
//             printf("%d\t",newArr[i]);
//         }
//     }
//     else{
//         for(int i=0;i<k-1;i++){
//             printf("%d\t",newArr[i]);
//         }
//     }
// }

int main(){

}