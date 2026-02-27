#include <stdio.h>

#include "builtins/parsing.h"


char** parse_input(char* s){

        int index = 0;
        int buf_size = 0;

        if(s == NULL){
                //end
        //      return s;
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

        return tokens;
}
