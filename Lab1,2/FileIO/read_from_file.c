#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    FILE* file;
    file=fopen("first_program_text.txt","r");

    if (file == NULL)
        {
        printf("Error opening file");
        exit(1);
        }
    fscanf(file,"%d",&num);
    printf("Value of integer in the file is:%d",num);
    fclose(file);

}