#ifndef EXEC_CMD_H
#define EXEC_CMD_H

int exec_builtin(int (*cmd)(char*), char* args);
int exec_ext_cmd(char** args);
int eval_cmd(char** args);

#endif
