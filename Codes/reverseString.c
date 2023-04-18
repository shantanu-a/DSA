#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char input[]="the sky is the limit the sky is the limit the sky is the limit the sky is the limit the sky is the limit";
    
    char** words=malloc(20*sizeof(char*));
    for(int i=0;i<20;i++){
        words[i]=(char*)malloc(100*sizeof(char));
    }
    int size=20;
    
    int count=0;
    
    char* pch;
    pch=strtok(input," ");
    strcpy(words[count],pch);
    count++;
    
    while(pch!=NULL){
        pch=strtok(NULL," ");
        if(count==size-1){
            words=realloc(words,2*count*sizeof(char*));
            for(int i=count+1;i<2*count;i++){
                words[i]=(char*)malloc(100*sizeof(char));
            }
            size=2*count;
        }
        if(pch!=NULL){
            strcpy(words[count],pch);
            count++;
        }      
    }
    for(int i=count-1;i>=0;i--){
        printf("%s ",words[i]);
    }
    return 0;
}
