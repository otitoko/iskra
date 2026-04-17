#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "input/input.h"

#include "readline/readline.h"
#include "readline/history.h"

#define HISTORY_SIZE 10

char* history[10];

int get_prompt(){

    char* username = getenv("USER");
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));

    printf("%s@%s# ",username, cwd);

    return 0;
}

char* recv_input(char* buf){

    buf = readline("harc@coded> ");

    return buf;
}

