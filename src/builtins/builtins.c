#include "builtins/builtins.h"
#include "builtins/echo.h"
#include "builtins/cd.h"
#include "builtins/exit.h"
#include "parsing/parsing.h"

const int NUM_BUILTINS = 3;
const int MANIP_STR_NUM = 5;
char* builtin_str[] = {
    "echo",
    "cd",
    "exit"
};

int (*builtin_functions[])(int, char**) = {
    &echo,
    &cd,
    &iskra_exit
};

