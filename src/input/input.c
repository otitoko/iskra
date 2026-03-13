#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "input/input.h"

int print_prompt(){

    char* username = getenv("USER");
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));

    printf("%s@%s# ",username, cwd);

    return 0;
}

char* recv_input(char* buf){
    size_t len = 0;
    getline(&buf, &len, stdin);

    buf[strcspn(buf, "\n")] = 0;

    return buf;
}
