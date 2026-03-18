#include <stdio.h>

#include "builtins/echo.h"


int echo(char* argv){
    if(argv == NULL){
        return 1;
    }
	printf("%s\n", argv);

	return 0;
}
