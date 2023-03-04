#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    FILE * file;
    file=fopen("first_program_text.txt","a");

    if (file == NULL)
    {
        printf("Error opening file");
        exit(1);
    }

    printf("Enter a number:");
    scanf("%d",&num);

    fprintf(file,"%d",num);
    fclose(file);
}