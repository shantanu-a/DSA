#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/time.h>
#define FILESIZE 100000

struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};
typedef struct person person;

void swap(person A[],int a,int b){
    person temp;
    temp.name=(char*)malloc(100*sizeof(char));

    temp.id=A[a].id;
    temp.age=A[a].age;
    temp.height=A[a].height;
    temp.weight=A[a].weight;
    strcpy(temp.name,A[a].name);

    A[a].id=A[b].id;
    A[a].age=A[b].age;
    A[a].height=A[b].height;
    A[a].weight=A[b].weight;
    strcpy(A[a].name,A[b].name);

    A[b].id=temp.id;
    A[b].age=temp.age;
    A[b].height=temp.height;
    A[b].weight=temp.weight;
    strcpy(A[b].name,temp.name);
}

int hoare_part(person A[],int low,int high,int pivot){
    int pivot_value=A[pivot].height;
    swap(A,low,pivot);
    int left=low+1;
    int right=high;
    
    while(left<right){
        for(;left<=right && A[left].height<=pivot_value;left++);

        for(;A[right].height>pivot_value;right--);

        if(left<right){
            swap(A,left,right);
            left++;
            right--;
        }
        
    }
    if(A[left].height<pivot_value && left<=high){
        pivot=left;
    }
    else pivot=left-1;

    swap(A,low,pivot);
    return pivot;
    
}

int lomuto_part(person A[],int low,int high,int pivot){
    int pivot_value=A[pivot].height;
    swap(A,pivot,high);
    int i=low;
    int j=low;
    
    while(j<high){
        if(A[j].height<=pivot_value){
            swap(A,i,j);
            i++;
        }
        j++;
    }
    return i;
}

int three_way_part(person A[],int low,int high,int pivot,int l,int h){
    int start=low;
    int end=high;

    int low_count=0;
    int i=0;
    while(i<=end){
        if(A[i].height<l){
            swap(A,start,i);
            low_count++;
            start++;
            i++;
        }
        else if(A[i].height>h){
            swap(A,end,i);
            end--;
        }
        else{
            i++;
        }
    }
    return low_count+1;
}


int main(){
    FILE* file=fopen("dat100000.csv","r");
    struct timeval t1,t2;
    double time_taken;

    person details[FILESIZE];


    for(int i=0;i<FILESIZE;i++){
            details[i].name=(char*)malloc(sizeof(char)*100);
    }
    int i=0;

    while(fscanf(file, "%d,%[^,],%d,%d,%d\n", &(details[i].id), details[i].name, &(details[i].age), &(details[i].height), &(details[i].weight))!=-1){
        i++;
    }
    printf("Pivot:%d\n",details[450].height);

    gettimeofday(&t1,NULL);

    hoare_part(details,0,999,450);
    //lomuto_part(details,0,999,450);
    //three_way_part(details,0,999,450,details[450].height,details[450].height);

    gettimeofday(&t2,NULL);

    time_taken = ((t2.tv_sec) - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;

    // for(int i=0;i<FILESIZE;i++){
    //     printf("%d\n",details[i].height);
    // }

    printf("Time taken is %Lf\n",time_taken);

}