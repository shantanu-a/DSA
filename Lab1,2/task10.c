#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Dynamic array of structs

struct student {
    char* ID;
    float cg;
};
typedef struct student* Student;

int main(){
    Student* s;
    s=(Student*)malloc(sizeof(Student));
    *s=(Student)malloc(sizeof(struct student));

    FILE* file;

    file=fopen("data.txt","r");

    char line[100];
    int i=0;

    while(fgets(line,100,file)){
        *s=realloc(*s,(i+1)*sizeof(struct student));

        char* input=strtok(line,",");

        ((*s)+i)->ID=(char*)malloc(20*sizeof(char));
        strcpy(((*s)+i)->ID,input);

        input = strtok(NULL, ",");

        ((*s)+i)->cg=atof(input);

        i++;
    }

    printf("%s  %f\n",(*s+2)->ID,(*s+2)->cg);
}
