#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#include <stdio.h>

#include "builtins/exec_cmd.h"
#include "builtins/echo.h"
#include "builtins/cd.h"
#include "builtins/builtins.h"
#include "misc/error_related.h"

extern char* builtin_str[];
extern int (*builtin_functions[])(char*);
extern const int NUM_BUILTINS;

int exec_builtin(int (*cmd)(char*), char* args){

    if(cmd == NULL){
        //		return 1;
    }

    cmd(args);

    return 0;
}

//implement proper error handling
int exec_ext_cmd(char** args){

    int pid = fork();
    int status;

    if( pid == 0 ){
        execvp(args[0], args);
    }
    else{
        waitpid(pid, &status, 0);
    }
    if(WIFEXITED(status)){
        int exit_status = WEXITSTATUS(status);
    }

    return 0;

}

int eval_cmd(char** args){

    if (args == NULL){
        return 1;
    }

    for(int index_builtins = 0; index_builtins < NUM_BUILTINS; index_builtins++){
        if(!null_check(args[0])){
            if(strcmp(args[0], builtin_str[index_builtins]) == 0){
                return exec_builtin(builtin_functions[index_builtins], args[index_builtins+1]);
            }
        }
    }

    return exec_ext_cmd(args);
}
