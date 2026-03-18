#ifndef PARSING_H
#define PARSING_H

char** parse_input(char* s);
int count_tokens(char** tokens);

struct tuple{
    int argc;
    char** argv;
};

#endif
