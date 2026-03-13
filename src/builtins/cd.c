#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "builtins/cd.h"

int cd(char* argv){
    int ret_val = 0;

    if(argv == NULL){
        char* home_dir = getenv("HOME");
        ret_val = chdir(home_dir);
    } 
    else{
        ret_val = chdir(argv);
    }


    if (ret_val < 0){
        printf("something");
    }

    return ret_val;
}
