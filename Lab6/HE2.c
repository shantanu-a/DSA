#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "linked_list.h"
#define ARRAY_SIZE 5

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
//end of stack and linked list definitions

int swap(int A[],int a,int b){
    //printf("s\n");
    int temp=A[a];
    A[a]=A[b];
    A[b]=temp;
}


int lomuto(int A[],int low,int high,int pivot){\
    //printf("l\n");
    int pivotValue=A[pivot];
    //printf("%d,%d\n",pivotValue,pivot);
    swap(A,high,pivot);

    int i=low;
    int j=low;

    while(j<high){
        //printf("w\n");
        if(A[j]<=pivotValue){
            swap(A,i,j);
            i++;
        }
        j++;
    }
    swap(A,i,high-1);
    return i;
}

int three_way_partition(int A[],int low,int high,int pivot,int l_value,int h_value){
    printf("3\n");
    int start=low;
    int end=high;
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

// L[] is the input array of length n
// kth smallest element is returned
// int qselect(int L[], int n, int k)
// {
// int pivot = 0;
// int lo = 0;
// int hi = n - 1;
// int pInd = part(L, lo, hi, pivot);
// if (k <= pInd)
// return qselect(L, pInd, k);
// else if (k > pInd + 1)
// return qselect(L + pInd + 1, n - pInd - 1, k - pInd - 1);
// else
// return L[pInd];
// }

int quickselect(int A[],int low,int n,int k){
    printf("q\n");
    int pivot=n;
    printf("%d\n",pivot);
    pivot=lomuto(A,low,n,pivot);

    if(k<=pivot){
        quickselect(A,low,pivot+1,k);
    }
    else if(k>pivot+1){
        quickselect(A,pivot+1,n-pivot-1,k-pivot-1);
    }
    else{
        return pivot;
    }
}

int main(){
    int A[]={1,3,5,7,9};

    int k;
    printf("Enter value for k:");
    scanf("%d",&k);

    if(k==ARRAY_SIZE){
        for(int i=0;i<ARRAY_SIZE;i++){
            printf("%d\t",A[i]);
        }
        return 1;
    }
    else if(k>ARRAY_SIZE){
        printf("Invalid");
        return 1;
    }

    int lower_index=(ARRAY_SIZE-k)/2;
    int higher_index=(ARRAY_SIZE+k)/2;

    int lower_value=quickselect(A,0,ARRAY_SIZE-1,lower_index);
    int higher_value=quickselect(A,0,ARRAY_SIZE-1,higher_index);

    three_way_partition(A,0,ARRAY_SIZE-1,0,A[lower_value],A[higher_value]);

    lower_value=quickselect(A,0,ARRAY_SIZE-1,lower_index);
    higher_value=quickselect(A,0,ARRAY_SIZE-1,higher_index);

    for(int i=lower_value;i<=higher_value;i++){
        printf("%d\t",A[i]);
    }
    return 1;

}