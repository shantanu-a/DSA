#include<stdio.h>
#include<stdlib.h>

int main(){
    int i=0;
    FILE* file1;
    FILE* file2;
    file1=fopen("task5.c","r");

    char line[100];
    while(fgets(line,100,file1)){ 
        printf("%s\n",line);
    }   
}