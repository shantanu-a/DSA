#include<stdio.h>
#include<stdlib.h>

int merge(int A[],int start,int mid,int end);
void mergeAux(int L1[],int start1,int end1,int L2[],int start2,int end2,int L3[],int start_aux,int end_aux);

int mergeSort(int A[],int start,int end){
    if(end-start<1) return 0 ;

    int mid=(start+end)/2;

    mergeSort(A,start,mid);
    mergeSort(A,mid+1,end);
    merge(A,start,mid,end);
}

int merge(int A[],int start,int mid,int end){
    int* C=(int*) malloc(sizeof(int)*(end - start + 1));
    mergeAux(A,start,mid,A,mid+1,end,C,0,end-start);

    for(int i = 0; i < end-start + 1; i++)
    {
        A[start + i] = *(C+i);
    }
    free(C);
}

void mergeAux(int L1[],int start1,int end1,int L2[],int start2,int end2,int L3[],int start_aux,int end_aux){
  
    if(start1==(end1-1) && start2!=(end2-1)){
        printf("1\n");
        L3[start_aux]=L2[start2];
        mergeAux(L1,start1,end1,L2,start2+1,end2,L3,start_aux+1,end_aux);
    }

    else if(start1!=(end1-1) && start2==(end2-1)){
        printf("2\n");
        L3[start_aux]=L1[start1];
        mergeAux(L1,start1+1,end1,L2,start2,end2,L3,start_aux+1,end_aux);
    }

    else if(start1==(end1-1) && start2==(end2-1)){
        printf("end\n");
        return;
    }

    else if(L1[start1]>=L2[start2]){
        printf("3\n");
        L3[start_aux]=L2[start2];
        mergeAux(L1,start1,end1,L2,start2+1,end2,L3,(start_aux+1),end_aux);
    }   
    else{
        printf("4\n");
        L3[start_aux]=L1[start1];
        mergeAux(L1,start1+1,end1,L2,start2,end2,L3,start_aux+1,end_aux);
    }
}

// void mergeAux (int L1[], int s1, int e1, int L2[], int s2, int e2, int L3[], int s3, int e3){
//     int i,j,k;
// // Traverse both arrays
//     i=s1; j=s2; k=s3;
//     while (i <= e1 && j <= e2) {
// // Check if current element of first array is smaller
// // than current element of second array
// // If yes, store first array element and increment first
// // array index. Otherwise do same with second array
//         if (L1[i] < L2[j])
//             L3[k++] = L1[i++];
//         else
//             L3[k++] = L2[j++];
//     }
// // Store remaining elements of first array
//     while (i <= e1) L3[k++] = L1[i++];
// // Store remaining elements of second array
//     while (j <= e2) L3[k++]=L2[j++];
// }


int main(){
    int n;
    scanf("%d",&n);
    int A[n];

    for(int i=0;i<n;i++){
        scanf("%d",A+i);
    }

    mergeSort(A,0,n);

    for(int i=0;i<n;i++){
        printf("%d\t",A[i]);
    } 
}