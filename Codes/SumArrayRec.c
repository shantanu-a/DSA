#include<stdio.h>
#include<stdlib.h>

int sumArray(int A[],int low, int high){
    if(low==high){
        return A[low];
    }
    int mid=(high+low)/2;
    int sum1=sumArray(A,low,mid);
    int sum2=sumArray(A,mid+1,high);
    return sum1+sum2;
}

int main(){
    int A[]={1,2,3,4,5,6,7,8,9,10};
    printf("%d",sumArray(A,0,9));
}