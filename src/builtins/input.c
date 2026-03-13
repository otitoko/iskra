#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "builtins/input.h"

int print_prompt(){

        char* username = getenv("USER");
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));

        printf("%s@%s# ",username, cwd);

        return 0;
}

char* recv_input(char* buf){
	fgets(buf,sizeof(buf)-1,stdin);

	return buf;
}
