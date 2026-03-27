#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "parsing/parsing.h"

char* manip_str[] = {
    ">",
    "<",
    ">>",
    "|",
    "&&"
};

int (*manip_functions[])(char**, char*, int, int) = {
    &redirect_string
};

//take input as s and return pointer to tokens
char** tokenize(char* s){
    
    int num_tokens = 0;
    int index = 0;
    int buf_size = 0;

    if(s == NULL){
        perror("empty string\n");
    }
    char* token = strtok(s," ");

    char** tokens = malloc(sizeof(char*));
    buf_size+=sizeof(char*);

    tokens[0] = token;
    index++;
    num_tokens++;

    while(token != NULL){

        token = strtok(NULL," ");

        tokens = (char**) realloc(tokens, buf_size+sizeof(char*));
        tokens[index] = token;
        buf_size+=sizeof(char*);
        index++;
        num_tokens++;
    }


    return tokens;
}

int count_tokens(char** tokens){
    int index = 0;

    while(tokens[index] != NULL){
        index++;
    }

    return index;
}

int redirect_string(char** strarr, char* redirect, int lower, int upper){
    int len = 0;
    for (int i = 0; i < count_tokens(strarr); i++){
        len+=strlen(strarr[i]);
    }


   // char* string = (char*) malloc((len*sizeof(char))+1);
    char* string = strarr[1];

    FILE* fileptr;

    fileptr = fopen(redirect, "w");


    int data_written = fwrite(string,sizeof(char), strlen(string), fileptr);

    if(strlen(string) != data_written){
        printf("String not written fully");
    }
    fclose(fileptr);
    return 0;
}


int redirect_check(char* arg){
    for (int i = 0; i < MANIP_STR_NUM; i++){
        if(strcmp(arg, manip_str[i]) == 0){
            return i;
        }
    }

    return -1;
}

int check_tokens(char** tokens){
    int i = 0;
    int symbol;
    while(tokens[i] != NULL){
        symbol = redirect_check(tokens[i]);
        if(symbol != -1){
            break;
        }
        i++;
    }
    switch(symbol){
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        default:
            return -1;
    }
}

int eval_redirect(int symbol,char* string, char** tokens, char* redirect){
    if(symbol == 0){
        return redirect_string(tokens, redirect, 0, 0);
    }
    if(symbol == 1){}
    if(symbol == 2){}
    if(symbol == 3){}
    if(symbol == 4){}


    return 0;
    
}
