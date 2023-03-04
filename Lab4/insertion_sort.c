#include<stdio.h>
#include<stdlib.h>

int insertInPlace(int arrayValue,int A[],int last);

int insertionSort(int A[],int n){
    for(int i=1;i<n;i++){
        insertInPlace(A[i],A,i);
    }
}

int insertInPlace(int arrayValue,int A[],int last){
    int j=last-1;
    while(j>=0 && arrayValue<A[j]){
        A[j+1]=A[j];
        j--;
    }
    A[j+1]=arrayValue;
}

int main(){
    int A[5]={5,3,1,4,2};

    insertionSort(A,5);

    for(int i=0;i<5;i++){
        printf("%d\t",A[i]);
    }
}