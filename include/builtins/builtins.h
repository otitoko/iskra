#ifndef BUILTINS_H
#define BUILTINS_H

extern const int NUM_BUILTINS;

extern char* builtin_str[];
extern int (*builtin_functions[])(int, char**);

#endif
