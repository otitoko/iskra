#include <unistd.h>
#include <stdio.h>

#include "builtins/cd.h"

int cd(char* argv){
    if(argv == NULL){
    } 

    int ret_val = chdir(argv);

    if (ret_val < 0){
        printf("something");
    }

    return ret_val;
}
