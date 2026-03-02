#ifndef EXEC_CMD_H
#define EXEC_CMD_H

void exec_builtin(int (*cmd)(char*), char* args);
void exec_ext_cmd(char** args);

#endif
