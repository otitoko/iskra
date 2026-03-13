#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parsing/parsing.h"

//take input as s and return pointer to tokens
char** parse_input(char* s){

    int index = 0;
    int buf_size = 0;

    if(s == NULL){
        return NULL;
    }
    char* token = strtok(s," ");

    char** tokens = malloc(sizeof(char*));
    buf_size+=sizeof(char*);

    tokens[0] = token;
    index++;

    while(token != NULL){

        token = strtok(NULL," ");

        tokens = (char**) realloc(tokens, buf_size+sizeof(char*));
        tokens[index] = token;
        buf_size+=sizeof(char*);
        index++;
    }

    //lets binaries get executed with execl but introduces bug wherein realloc breaks
    //	tokens[index] = NULL;

    return tokens;
}


