#include <stdio.h>

#include "builtins/echo.h"


int echo(char* argv){
	printf("%s", argv);

	return 0;
}
