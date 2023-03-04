#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE* file1;
    FILE* file2;

    file1=fopen("test1.txt","w");
    file2=fopen("test2.txt","w");

    if(file1 == NULL){
        printf("Error opening file!");
        exit(1);
    }


    fprintf(file1,"This is text from text1");
    fclose(file1);

    FILE* file3=fopen("test1.txt","r");
    char line[100];
    
    while(fgets(line,100,file1)){
        fprintf(file2,"%s",line);
    }

    fclose(file1);
    fclose(file2);

    file1=fopen("test1.txt","w");
    fprintf(file1,"");
}