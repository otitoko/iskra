#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "builtins/echo.h"
#include "parsing/parsing.h"
#include "builtins/exec_cmd.h"
#include "input/input.h"
#include "builtins/cd.h"
#include "builtins/builtins.h"



int main(){
    while(1){

        print_prompt();

        char *user_input = NULL;

        user_input = recv_input(user_input);

        char **tokens = parse_input(user_input);
        //change this ASAP
        eval_cmd(2, tokens);

        free(tokens);
    }

    return 0;
}
