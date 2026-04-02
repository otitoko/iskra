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

int (*manip_functions[])(char**, char*) = {
    &redirect_output
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
char* return_string(char** tokens, int lower, int upper){
    char* str = malloc(1*sizeof(char));
    str[0] = '\0';
    int old_size = 0;
    int extra_size;
    for(int i = lower; i < upper; i++){
       //append tokens[i] to str val 
      extra_size = strlen(tokens[i]); 
      str = realloc(str, old_size+extra_size+1);
      strcpy(str+old_size, tokens[i]);
      old_size+=extra_size;
      if(i+1 < upper){
          str[old_size] = ' ';
          old_size++;
      }
    }

    return str;
}

int find_upper(char** tokens){
    int i = 0;
    while(tokens[i] != NULL){
        for(int j = 0; j < MANIP_STR_NUM; j++){

            if(strcmp(tokens[i], manip_str[j]) == 0){
                return i;
            }
        }
    i++;
    }

    return 0;
}


int redirect_output(char** tokens, char* redirect){
/*    int lower = 1;
    int upper = find_upper(tokens);
    char* string = return_string(tokens,lower, upper);
*/
    FILE* fileptr;

    fileptr = fopen(redirect, "w");
    int fd = fileno(fileptr);

    dup2(fd, 1);
/*
    int data_written = fwrite(string,sizeof(char), strlen(string), fileptr);

    if(strlen(string) != data_written){
        printf("String not written fully");
    }
    */
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

//idk maybe remove string param
int eval_redirect(int symbol,char* string, char** tokens, char* redirect){
    if(symbol == 0){
        return redirect_output(tokens, redirect);
    }
    if(symbol == 1){}
    if(symbol == 2){}
    if(symbol == 3){}
    if(symbol == 4){}


    return 0;
    
}

int reset_fd(int saved_state){
    dup2(saved_state,1);

    return 0;
}

char** trim_tokens(int argc, char** argv){
    char** tokens = malloc(argc * sizeof(char*));
    int skip = 0;

    for(int i = 0; i < argc; i++){
        for(int j = 0; j < MANIP_STR_NUM; j++){
            if((strcmp(argv[i], manip_str[j]) == 0) || (skip == 1)){
                tokens[i] = NULL;
                skip = 1;
                break;
            }
            else{
                tokens[i] = malloc(strlen(argv[i]) +1);
                strcpy(tokens[i], argv[i]);
            }
        }
    }

    return tokens;
}
