#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct bitsian
{
char name[40];
char rollno[15];
}bitsian;

void swap(bitsian details[],int a,int b){
    //printf("1\n");
    bitsian temp;
    strcpy(temp.name,details[a].name);
    strcpy(temp.rollno,details[a].rollno);

    strcpy(details[a].name,details[b].name);
    strcpy(details[a].rollno,details[b].rollno);

    strcpy(details[b].name,temp.name);
    strcpy(details[b].rollno,temp.rollno);
}

int partition(bitsian details[],int low,int high,char* pivot){
    //printf("2\n");
    int start=low;
    int end=high;
    int i=0;

    while(i<=end){
        //printf("%s\n",details[i].rollno);
        //printf("%s\n",pivot);
        int check=strncmp(details[i].rollno,pivot,13);
        printf("%d\n",check);
        if(check<0){
            //printf("1\n");
            swap(details,start,i);
            start++;
            i++;
        }
        else if(check>0){
            printf("2\n");
            swap(details,end,i);
            end--;
        }
        else{
            printf("3\n");
            i++;
        }
        //printf("%d\n",strcmp(details[i].rollno,pivot));
    }
}

int main(){
    FILE* file=fopen("bitsians.csv","r");
    if(file==NULL){
        printf("Error opening file");
        return 0;
    }
    int num_records=1028;
    fscanf(file,"%[d]",num_records);
    printf("%d",num_records);

    bitsian* details=(bitsian*)malloc(num_records*sizeof(bitsian));;
    
    int i=0;
    while(fscanf(file,"%[^,],%[^\n]",details[i].rollno,details[i].name)!=-1){
        i++;
    }

    //partition(details,0,1027,"2020AAPS0000P");
    //printf("%d\n",strcmp(details[1].rollno,"2020AAPS0000P"));
    
    // for(int i=0;i<num_records;i++){
    //     printf("%s\n",details[i].rollno);
    // }
}