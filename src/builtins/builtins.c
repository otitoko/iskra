#include "builtins/builtins.h"
#include "builtins/echo.h"
#include "builtins/cd.h"

const int NUM_BUILTINS = 2;

char* builtin_str[] = {
    "echo",
    "cd"
};

int (*builtin_functions[])(int, char**) = {
    &echo,
    &cd
};
