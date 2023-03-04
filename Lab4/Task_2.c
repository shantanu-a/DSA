#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/time.h>
#include "task1+HT1.c"
#include<stdbool.h>
#define FILESIZE 1000


int main(){
    struct timeval t1,t2;
    double time_taken;

    FILE* file=fopen("dat1000.csv","r");
    char buffer[1000];
    char*token;

    person details[FILESIZE];
    

    for(int i=0;i<FILESIZE;i++){
        details[i].name=(char*)malloc(sizeof(char)*50);
    }
    int i=0;

    while(fscanf(file, "%d,%[^,],%d,%d,%d\n", &(details[i].id), details[i].name, &(details[i].age), &(details[i].height), &(details[i].weight))!=-1){
        printf("%d\n",details[i].age);
        i++;
    }

    gettimeofday(&t1,NULL);

    insertionSort(details,FILESIZE,"name");

    gettimeofday(&t2,NULL);

    time_taken = ((t2.tv_sec) - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;

    // for(int i=0;i<FILESIZE;i++){
    //     printf("%s\n",details[i].name);
    // }

    printf("Time taken is %lf\n",time_taken);

}
