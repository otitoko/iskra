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
#include "builtins/exit.h"



int main(){
    while(1){

        print_prompt();

        char *user_input = NULL;

        user_input = recv_input(user_input);

        char **tokens = tokenize(user_input);

        int num_tokens = count_tokens(tokens);
        

        int symbol = check_tokens(tokens);
        eval_redirect(symbol, NULL, tokens, tokens[3]);
        eval_cmd(num_tokens, tokens);

        free(tokens);

    }

    return 0;
}
