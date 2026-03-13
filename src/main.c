#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "builtins/echo.h"
#include "builtins/parsing.h"
#include "builtins/exec_cmd.h"
#include "builtins/input.h"
#include "builtins/cd.h"

#define NUM_BUILTINS 2

char* builtin_str[] = {
    "echo",
    "cd"

};

int (*builtin_functions[]) (char*) = {
    &echo,
    &cd
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
        int token = 0;
        int is_builtin = 0;

        do { 

            for(int index_builtins = 0; index_builtins < NUM_BUILTINS; index_builtins++){
                
                if(strcmp(tokens[token], builtin_str[index_builtins]) == 0){
                    exec_builtin(builtin_functions[index_builtins], tokens[token+1]);
                    is_builtin = 1;
                    break;
                }

            }

            if(!is_builtin){
                exec_ext_cmd(tokens);
            }
            token++;
        } while (tokens[token] != NULL);
        free(tokens);
    }

    return 0;
}
