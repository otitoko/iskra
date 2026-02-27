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

//take input as s and return pointer to tokens
char** parse_input(char* s){

	int index = 0;
	int buf_size = 0;

	if(s == NULL){
		//end
	//	return s;
	}
	char* token = strtok(s," ");
	
	char** tokens = malloc(sizeof(char*));
	buf_size+=sizeof(char*);

	tokens[0] = token;
	index++;

	while(token != NULL){
	
	token = strtok(NULL," ");

	tokens = (char**) realloc(tokens, buf_size+sizeof(char*));
	tokens[index] = token;
	buf_size+=sizeof(char*);
	index++;
	}

	return tokens;
}

int main(){
	while(1){
		
		print_prompt();
		char s[64];
		fgets(s,sizeof(s)-1,stdin);
		char **tokens = parse_input(s);
		int i = 0;
		do { 
			printf("%s\n", tokens[i]); 
			i++;
		} while (tokens[i] != NULL);
	}

	return 0;
}
