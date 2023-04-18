#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int mulHash(int key, int size)
{
    double A = 0.6180339887;
    double frac = key * A - (int)(key * A);
    return (int)(size*frac);
}

// struct student
// {
//     long long int ID;
//     char name[30];
// };

typedef struct node* NODE;
struct node{
    char name[30];
    NODE next;
};

typedef struct linked_list* LIST;
struct linked_list{
    int count;
    int occupied;
    NODE head;
    NODE tail;
};

LIST createNewList()
{
    LIST myList;
    myList = (LIST) malloc(sizeof(struct linked_list));
    myList->count=0;
    myList->occupied=0;
    myList->head=NULL;
    myList->tail=NULL;
    return myList;
}

NODE createNewNode(char* name)
{
    NODE myNode;
    myNode = (NODE) malloc(sizeof(struct node));
    strcpy(myNode->name,name);
    myNode->next=NULL;
    return myNode;
}

void insertIntoList(LIST ls,NODE node){
    if(ls->count==0){
        ls->head=node;
        ls->tail=node;
        ls->count++;
        ls->occupied=1;
        return;
    }

    ls->tail->next=node;
    ls->tail=node;
    ls->count++;
}



int main(){
    printf("1\n");
    FILE* fp=fopen("t1_data.txt","r");

    if(fp==NULL){
        printf("Error opening file");
        return 1;
    }
    printf("2\n");
    char* buffer=(char*)malloc(1024*sizeof(char));
    fgets(buffer,1024,fp);
    int num_records=atoi(buffer);
    printf("%d\n",num_records);

    LIST hash[2*num_records];

    for(int i=0;i<2*num_records;i++){
        
        hash[i]=createNewList();
    }
    printf("3\n");
    int collisions=0;


    int key;
    char* name=(char*)malloc(100*sizeof(char));
    int i=0;

    while(i!=500){
        // printf("4\n");
        fscanf(fp, "%d,%[^\n]\n", &key, name);
        int hash_value=key%(2*num_records);

        NODE node=createNewNode(name);

        if(hash[hash_value]->occupied==1) collisions++;

        insertIntoList(hash[hash_value],node);
        i++;

    }
    printf("The number of collisions are %d\n",collisions);

}

