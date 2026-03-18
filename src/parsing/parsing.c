#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parsing/parsing.h"


//take input as s and return pointer to tokens
char** parse_input(char* s){
    
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
