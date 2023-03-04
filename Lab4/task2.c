//To run this file, comment out the main function in the other file 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/time.h>
#include "task1+HT1.c"
#include<stdbool.h>


int main(){
    printf("1\n");
    struct timeval t1,t2;
    double time_taken;

    FILE* file=fopen("dat1000.csv","r");
    char buffer[1000];
    char*token;

    person details[1000];
    int i=0;

    // while(fgets(buffer,1000,file)){

    //     //printf("2\n");
    //     char* input=strtok(buffer,", ");
    //     printf("%s\n",input);
    //     details[i].id=atoi(input);

    //     input=strtok(NULL,", ");
    //     details[i].name=(char*)malloc(sizeof(char)*50);
    //     strcpy(details[i].name,input);
    //     //printf("3\n");

    //     input=strtok(NULL,", ");
    //     details[i].age=atoi(input);

    //     input=strtok(NULL,", ");
    //     details[i].height=atoi(input);

    //     input=strtok(NULL,", ");
    //     details[i].weight=atoi(input);  
    //     i++; 
    // }

    while(i!=1000){
        fgets(buffer,1024,file);
        token=strtok(buffer,", ");
        printf("%s\n",token);
        details[i].id=atoi(token);

        token=strtok(NULL,", ");
        details[i].name=(char*)malloc(sizeof(char)*50);
        strcpy(details[i].name,token);
        //printf("3\n");

        token=strtok(NULL,", ");
        details[i].age=atoi(token);

        token=strtok(NULL,", ");
        details[i].height=atoi(token);

        token=strtok(NULL,", ");
        details[i].weight=atoi(token);  
        i++; 

        
        
    }
    printf("4\n");

    gettimeofday(&t1,NULL);

    //insertionSort(details,1000,"height");
    printf("5\n");

    gettimeofday(&t2,NULL);

    time_taken = ((t2.tv_sec) - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;

    // for(int i=0;i<1000;i++){
    //     printf("%d\n",details[i].id);
    // }

    //printf("Time taken is %lf\n",time_taken);

}

