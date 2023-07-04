#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int hash1(int key,int size){
    return key % size;
}

int hash2(int key,int size){
    int p = (int)log2(size);
    int power_of_2_just_less_than_size= (int)pow(2, p);
    return (int)(key % power_of_2_just_less_than_size);
}

int hash3(int key,int size){
    return key % 997;
}

int mulHash(int key, int size)
{
    double A = 0.6180339887;
    double frac = key * A - (int)(key * A);
    return (int)(size*frac);
}

int hash4(int key,int size){
    return key % 887;
}

int hash5(long long key,int size){
    long long value=key*997;
    int final_value=value%size;
    return final_value;
}


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

long long calculateKeyWithRadix(char* name){
    int length=sizeof(name)/sizeof(char);
    long long key=0;

    for(int i=length-1;i>=0;i--){
        int ascii=name[i];
        key+=ascii*pow(64,length-i);
    }
    printf("%d\n",key);
    return key;
}



int main(){
    FILE* fp=fopen("t1_data.txt","r");

    if(fp==NULL){
        printf("Error opening file");
        return 1;
    }

    char* buffer=(char*)malloc(1024*sizeof(char));
    fgets(buffer,1024,fp);
    int num_records=atoi(buffer);

    LIST hash[2*num_records];

    for(int i=0;i<2*num_records;i++){
        
        hash[i]=createNewList();
    }

    int collisions=0;


    int key;
    char* name=(char*)malloc(100*sizeof(char));

    while(fscanf(fp, "%d,%[^\n]\n", &key, name)!=-1){
        long long name_key=calculateKeyWithRadix(name);
        int hash_value=mulHash(name_key,1000);

        NODE node=createNewNode(name);

        if(hash[hash_value]->occupied==1) collisions++;

        insertIntoList(hash[hash_value],node);

    }
    printf("The number of collisions are %d\n",collisions);
}


