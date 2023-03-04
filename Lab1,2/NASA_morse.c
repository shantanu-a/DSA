#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* match(char* morse){

    char *characters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M","N", "O", "P", "Q", "R", "S", "T", "U",
                      "V", "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};


    char *morsecode[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---", "-.-",".-..","--","-.","---",".--.","--.-",
                     ".-.","...","-","..-", "...-",".--","-..-","-.--","--..", ".----","..---","...--","....-", ".....", "-....",
                     "--...","---..","----.","-----"};

    for(int i=0;i<36;i++){
        if(strcmp(morse,*(morsecode+i))==0){
            //printf("%s",*(characters+i));
            return *(characters+i);
        }
    }
}

int wordToLetters(char* word){
    char* letter=strtok(word," ");
    printf("%s",match(letter));

    while(letter!=NULL){
        letter=strtok(NULL," ");
        printf("%s",match(letter));
    }
    printf("\t");
}




int main(){
    
    FILE* file;
    file=fopen("msg.txt","r");
    char buffer[1000];

    char*words;
    char* letters;
    char* message;
    char* word1=(char*)malloc(100*sizeof(char));
    char* word2=(char*)malloc(100*sizeof(char));

    //char** code_words=(char**)malloc(100*sizeof(char*));

    // for(int i=0;i<100;i++){
    //     code_words[i]=(char*)malloc(100*sizeof(char));
    // }
    // int i=0;

    while(fgets(buffer,1000,file)){
        words=strtok(buffer,"/");
        //wordToLetters(words);
        //printf("1\n");
        //printf("%s",words);
        strcpy(word1,words);
        wordToLetters(word1);

        while(words!=NULL){
            //printf("1\n");
            //i++;
            words=strtok(NULL,"/");
            strcpy(word2,words);
            //wordToLetters(words);
            wordToLetters(word1);
            //strcpy(code_words[i],words);
        }
    }

    //printf("%s\n",code_words[0]);




    // while(fgets(buffer,1000,file)){
    //     words=strtok(buffer,"/");
    //     letters=strtok(NULL," ");
    //     printf("%s",match(letters));

    //     while(letters!=NULL){
    //         letters=strtok(NULL," ");
    //         printf("%s",match(letters));
            
    //     }
    //     words=strtok(NULL,"/");
    //     printf("%s\t",words);

    //     while(words!=NULL){
    //         printf("1\n");
    //         words=strtok(NULL,"/");
    //         printf("%s\t",words);
    //         letters=strtok(words," ");
    //         printf("%s\t",letters);
    //         //printf("%s",match(letters));

    //         while(letters!=NULL){
    //             printf("4");
    //             letters=strtok(NULL," ");
    //              printf("%s\t",letters);
    //             //printf("%s",match(letters));
    //         }
    //     }
    // }
}

//printf("%s",match(letters));
//message=strcat(message,letters);

//.--. . --- .--. .-.. . / --- ..-. / . .- .-. - .... / -.-- --- ..- .-. / .- - - . -. - .. --- -. / .--. .-.. . .- ... .