#include <stdio.h>

#include "builtins/echo.h"


int echo(char* string){
	printf("%s", string);

	return 0;
}
