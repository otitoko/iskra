#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "builtins/echo.h"
#include "builtins/parsing.h"

char* builtin_str[] = {
	"echo"
};

int (*builtin_functions[]) (char*) = {
	&echo
};

int print_prompt(){

	char* username = getenv("USER");
	char* pwd = getenv("PWD");

	printf("%s@%s# ",username, pwd);

	return 0;
}

void exec_cmd(int (*cmd)(char*), char* args){

	if(cmd==NULL){
//		return 0;
	}

	cmd(args);
}

int main(){
	while(1){
		
		print_prompt();
		char s[64];
		fgets(s,sizeof(s)-1,stdin);
		char **tokens = parse_input(s);
		int i = 0;
		do { 
			if(strcmp(tokens[i], builtin_str[0]) == 0){
				exec_cmd(builtin_functions[0], tokens[i+1]);
			}
			i++;
		} while (tokens[i] != NULL);
	}

	return 0;
}
