#include <stdio.h>

#include "builtins/echo.h"


int echo(int argc,char** argv){
    if(argc < 1){
        return 1;
    }
    for(int i = 1; i < argc; i++){


        printf("%s", argv[i]);
        printf(" ");
    }

    printf("\n");

	return 0;
}
