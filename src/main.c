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
        int saved_out = dup(1);
        int saved_in = dup(0);

        print_prompt();

        char *user_input = NULL;


        user_input = recv_input(user_input);

        char **tokens = tokenize(user_input);

        int num_tokens = count_tokens(tokens);
        

        int symbol = check_tokens(tokens);
        int redirect = find_upper(tokens);

        char** trimmed_tokens = trim_tokens(num_tokens,tokens);

        eval_redirect(symbol, NULL, tokens, tokens[redirect+1]);
        eval_cmd(num_tokens, trimmed_tokens);

        reset_fd(saved_in, 0);
        reset_fd(saved_out, 1);

        free(tokens);
        free(trimmed_tokens);

    }

    return 0;
}
