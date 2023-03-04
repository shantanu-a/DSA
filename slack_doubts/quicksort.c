#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct person{
int id;
char *name;
int age;
int height;
int weight;
};

void swap(struct person* A,int a,int b){
    struct person temp;
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

int partition(struct person *A, int low, int high){
    struct person pivot=A[low];
    int pivot
    int start=low, end=high;
    struct person temp;
    while(start<end){
        while(A[start].height<pivot.height && start<=end){
            start++;
        }
        while(A[end].height>pivot.height){
            end--;
        }
        if(start<end){
            swap(A,start,end);
            start++;
            end--;
        }
    }
    if(A[start].height<pivot.height && start<=high){
        pivot=start;
    }
    else pivot=start-1;

    swap(A,low,pivot);
    swap(A,end,low);
    return end;
}
void quickSort(struct person A[], int low, int high){
    int partitionIndex; // Index of pivot after partition
    if (low < high){
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);  // sort left subarray
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}
int main(){
    int n=5;
    struct person arr[5]={{1,"Carl",24,180,70},{2,"Sam",25,175,75},{3,"Chuck",27,186,65},
    {4,"Harry",27,172,65},{5,"David",26,171,55}};
    for(int i=0;i<n;i++){
        printf("%d ",arr[i].height);
    }
    printf("\n");
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i].height);
    }
}