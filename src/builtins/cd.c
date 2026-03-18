#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "builtins/cd.h"

int cd(int argc, char** argv){

    int ret_val;

    if (argc > 2){
        printf("cd: too many args");
        return 1;
    }

    if(argc == 1){
        char* home_dir = getenv("HOME");
        ret_val = chdir(home_dir);
    } 
    else{
        ret_val = chdir(argv[1]);
    }


    if (ret_val < 0){
        printf("cd error");
    }

    return ret_val;
}
