#include <stdlib.h>
#include <stdio.h>

#include "builtins/input.h"

int print_prompt(){

        char* username = getenv("USER");
        char* pwd = getenv("PWD");

        printf("%s@%s# ",username, pwd);

        return 0;
}

char* recv_input(char* buf){
	fgets(buf,sizeof(buf)-1,stdin);

	return buf;
}
