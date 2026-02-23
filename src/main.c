#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "builtins/echo.h"

int print_prompt(){

	char* username = getenv("USER");
	char* pwd = getenv("PWD");

	printf("%s@%s# ",username, pwd);

	return 0;
}

int main(){
	while(1){
		
		print_prompt();
		char s[64];
		fgets(s,sizeof(s)-1,stdin);
		strtok(s," ");
	}

	return 0;
}

