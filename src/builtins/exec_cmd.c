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
extern int (*builtin_functions[])(int, char**);
extern const int NUM_BUILTINS;

int exec_builtin(int (*cmd)(int, char**),int argc, char** argv){

    if(cmd == NULL){
        //		return 1;
    }

    cmd(argc, argv);

    return 0;
}

//implement proper error handling
int exec_ext_cmd(char** argv){

    int pid = fork();
    int status;

    if( pid == 0 ){
        execvp(argv[0], argv);
    }
    else{
        waitpid(pid, &status, 0);
    }
    if(WIFEXITED(status)){
        int exit_status = WEXITSTATUS(status);
    }

    return 0;

}

int eval_cmd(int argc, char** argv){

    if (argc < 1){
        return 1;
    }

    for(int index_builtins = 0; index_builtins < NUM_BUILTINS; index_builtins++){
        if(strcmp(argv[0], builtin_str[index_builtins]) == 0){
            return exec_builtin(builtin_functions[index_builtins], argc , argv);
        }
    }

    return exec_ext_cmd(argv);
}
