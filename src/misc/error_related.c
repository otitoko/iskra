#include <stddef.h>

#include "misc/error_related.h"


int null_check(char* arg){
    if(arg == NULL){
        return 1;
    }
    return 0;
}
