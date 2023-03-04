#include<stdio.h>
#include<stdlib.h>

int lengthNTR(char *str){
    if (*str == '\0'){
        return 0;
    }
    else{
    return 1 + lengthNTR(str + 1);
    }
}

int lengthTR(char *str,int acc){
    if(*str=='\0'){
        return acc;
    }
    return lengthTR(str+1,++acc);
}

int lengthIterative(char* str){
    int length=0;
    while(*str!='\0'){
        length++;
        str=str+1;
    }
    return length;
}

int main(){
    char* name="Shantanu";
    int length=lengthNTR(name);
    printf("%d\n",length);

    length=lengthTR(name,0);
    printf("%d\n",length);

    length=lengthIterative(name);
    printf("%d\n",length);
}