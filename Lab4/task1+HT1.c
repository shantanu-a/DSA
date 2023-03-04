#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person
{
int id;
char *name;
int age;
int height;
int weight;
};
typedef struct person person;

void insertInPlace_height(person a,person details[],int last);
void insertInPlace_name(person a,person details[],int last);

void insertionSort(person details[],int n,char* sorting_criterion){
    if(strcmp(sorting_criterion,"height")==0){
        for(int i=0;i<n;i++){
            insertInPlace_height(details[i],details,i);
        }
    }
    if(strcmp(sorting_criterion,"name")==0){
            for(int i=0;i<n;i++){
            insertInPlace_name(details[i],details,i);
        }
    }
}

void insertInPlace_height(person a,person details[],int last){
    int j=last-1;

    while(j>=0 && a.height<details[j].height){
        
        details[j+1].id=details[j].id;
        details[j+1].age=details[j].age;
        details[j+1].height=details[j].height;
        details[j+1].weight=details[j].weight;
        strcpy(details[j+1].name,details[j].name);
        j--;
    }

    details[j+1].id=a.id;
    details[j+1].age=a.age;
    details[j+1].height=a.height;
    details[j+1].weight=a.weight;
    strcpy(details[j+1].name,a.name);
}

void insertInPlace_name(person a,person details[],int last){
    int j=last-1;

    while(j>=0 && strcmp(a.name,details[j].name)<0){
        
        details[j+1].id=details[j].id;
        details[j+1].age=details[j].age;
        details[j+1].height=details[j].height;
        details[j+1].weight=details[j].weight;
        strcpy(details[j+1].name,details[j].name);
        j--;
    }

    details[j+1].id=a.id;
    details[j+1].age=a.age;
    details[j+1].height=a.height;
    details[j+1].weight=a.weight;
    strcpy(details[j+1].name,a.name);
}


// int main(){
//     int num;
//     printf("Enter number of details you want to enter:");
//     scanf("%d",&num);
//     int age,height,weight,id;
//     char * name=(char*)malloc(20*sizeof(char));

//     person details[num];

//     for(int i=0;i<num;i++){
//         printf("Enter id:");
//         scanf("%d",&id);
//         details[i].id=id;

//         printf("Enter name:");
//         scanf("%s",name);
//         details[i].name=(char*)malloc(20*sizeof(char));
//         strcpy(details[i].name,name);


//         printf("Enter age:");
//         scanf("%d",&age);
//         details[i].age=age;

//         printf("Enter height:");
//         scanf("%d",&height);
//         details[i].height=height;

//         printf("Enter weight:");
//         scanf("%d",&weight);
//         details[i].weight=weight;

//         printf("\n");
//     }

//     //insertionSort(details,num,"height");
//     insertionSort(details,num,"name");

//     for(int i=0;i<num;i++){
//         printf("%d %s %d %d %d\n",details[i].id,details[i].name,details[i].age,details[i].height,details[i].weight);
        
//     }

// }

// void prefixSum(int arr[],int n){
//     int prefix;
//     for(int i=1;i<n;i++){
//         prefix=arr[i-1]+arr[i];
//         arr[i]=prefix;
//     }
// }

// int main(){
//     int arr[5]={1,2,3,4,5};
//     prefixSum(arr,5);

//     for(int i=0;i<5;i++){
//         printf("%d\t",arr[i]);
//     }
// }