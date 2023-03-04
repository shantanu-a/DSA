#include<stdio.h>
#include<stdlib.h>


long long rowWiseAdd(int ** matrix1,int** matrix2,int n){
    int** matrix3=(int**)malloc(sizeof(int*));

    for(int i=0;i<n;i++){
        matrix3[i]=(int*)malloc(sizeof(int));
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix3[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }
}