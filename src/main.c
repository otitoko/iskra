#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "builtins/echo.h"
#include "builtins/parsing.h"
#include "builtins/exec_cmd.h"
#include "builtins/input.h"

char* builtin_str[] = {
	"echo"
};

int (*builtin_functions[]) (char*) = {
	&echo
};

int main(){
	while(1){

		print_prompt();

		char *s = NULL;
		size_t len = 0;
		getline(&s, &len, stdin);
		s[strcspn(s, "\n")] = 0;
	//	recv_input(s);
		char **tokens = parse_input(s);
		int i = 0, j = 0;
		do { 
			do {
				if(strcmp(tokens[i], builtin_str[j]) == 0){
					exec_builtin(builtin_functions[j], tokens[i+1]);
					i++;
				}
				else{
					exec_ext_cmd(tokens);
					i++;
				}
			j++;
			} while (builtin_str[j] != NULL);
			i++;
		} while (tokens[i] != NULL);
		free(tokens);
	}

	return 0;
}
