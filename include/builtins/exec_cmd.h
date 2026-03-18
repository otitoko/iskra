#ifndef EXEC_CMD_H
#define EXEC_CMD_H

int exec_builtin(int (*cmd)(int, char**),int argc, char** argv);
int exec_ext_cmd(char** argv);
int eval_cmd(int argc,char** argv);

#endif
