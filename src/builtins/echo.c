#include <stdio.h>

#include "builtins/echo.h"


int echo(char* argv){
	printf("%s\n", argv);

	return 0;
}
