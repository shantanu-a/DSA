#include<stdio.h>

int main(){
    int arr2[5]={1,2,3,4,5};
    int arr1[5]={6,7,8,9,10};
    int arr[10];

    int count1=0,count2=0;

    for(int i=0;i<10;i++){
        if(count1!=5 && count2!=5){
            if(arr1[count1]<=arr2[count2]){
                arr[i]=arr1[count1];
                count1++;            
            }
            else if(arr1[count1]>arr2[count2]){
                arr[i]=arr2[count2];
                count2++;            
            }

        }
        else if(count1==5){
            arr[i]=arr2[count2];
            count2++;
        }
        else if(count2==5){
            arr[i]=arr1[count1];
            count1++;
        }
    }
    
    for(int i=0;i<10;i++){
        printf("%d\n",arr[i]);
    }
}