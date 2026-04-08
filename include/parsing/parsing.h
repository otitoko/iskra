#ifndef PARSING_H
#define PARSING_H

extern const int MANIP_STR_NUM;

char** tokenize(char* s);
int count_tokens(char** tokens);
int redirect_output(char** strarr, char* redirect);
int redirect_input(char** strarr, char* redirect);
int check_tokens(char** tokens);
int eval_redirect(int symbol,char* string, char** tokens, char* redirect);
char* return_string(char** tokens, int lower, int upper);
int find_upper(char** tokens);
int reset_fd(int saved_state,int stream);
char** trim_tokens(int argc, char** argv);

extern char* manip_str[];
extern int (*manip_functionspp[])(char*,char*);


struct tuple{
    int argc;
    char** argv;
};

#endif
