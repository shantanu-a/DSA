#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define TABLE_SIZE 1024

typedef enum Operation {filled,empty,deleted} operation;

typedef struct student student;
struct student{
long long int ID;
char name[30];
};

struct hash_table_element{
    operation o;
    student s;
};

int mulHash(int ID, int size)
{
    double A = 0.6180339887;
    double frac = ID * A - (int)(ID * A);
    return (int)(size*frac);
}
int hash(int ID, int m, int i){
    return (int)((mulHash(ID,TABLE_SIZE)+i)% m);
}

void insert(struct hash_table_element *table, struct student *stud){
    int i = 0;
    int h = hash(stud->ID, 1024, i);
    while (table[h].o == filled) {
        i++;
        h = hash(stud->ID, 1024, i);
    }
    table[h].s = *stud;
    table[h].o = filled;

}
  
void delete(struct hash_table_element *table, int ID, int m){
    int i=0;
    int h = hash(ID, 1024, i);

    while(table[h].o==filled || table[h].o==deleted){
        i++;
        h = hash(ID, 1024, i);
    }
    if(table[h].o==empty){
        printf("Element not available\n");
        return;
    }
    printf("Element deleted\n");
    table[h].o = deleted;
}

// struct student *search(struct hash_table_element *table, int ID, int m){

//     int i=0;
//     int key=hash(ID,TABLE_SIZE,i);
//     while((table+key)->o!=0){
//         printf("search\n");
//         if((table+key)->s.ID==ID){
//             return &(table+key)->s;
//         }
//     }
// }


int main(){
    struct hash_table_element* hash_table_array=(struct hash_table_element*)malloc(1024*sizeof(struct hash_table_element));

    for(int i=0;i<TABLE_SIZE;i++){
        // printf("1\n");
        (hash_table_array+i)->o=empty;
    }
    // printf("2\n");

    FILE* fp=fopen("t1_queries.txt","r");
    char* buffer=(char*)malloc(sizeof(char)*1024);

    

    while(fgets(buffer,1024,fp)){
        if(buffer[0]=='1'){
            char* operation=strtok(buffer,", ");
            char* ID=strtok(NULL,", ");
            char* name=strtok(NULL,"\n");
            int int_ID=atoi(ID);

            student* stud=(student*)malloc(sizeof(student));
            stud->ID=int_ID;
            strcpy(stud->name,name);
            insert(hash_table_array,stud);
        }

        if(buffer[0]=='2'){
            char* operation=strtok(buffer,", ");
            char* value=strtok(NULL,"\n");
            int int_ID=atoi(value);

            printf("%s\n",value);

            delete(hash_table_array,int_ID,2);
        }

        // if(buffer[0]=='3'){
        //     // printf("3\n");
        //     char* operation=strtok(buffer,", ");
        //     char* ID=strtok(NULL,"\n");
        //     int int_ID=atoi(ID);

        //     // printf("%s\n",ID);

        //     // student* stud=search(hash_table_array,int_ID,3);

        //     // printf("The name of the student is %d\n", stud->ID);
        // }

    }
    // int i=0;

    // while(i<1024){
    //     printf("%s\n",(hash_table_array+i)->s.name);
    //     i++;
    // }

}
