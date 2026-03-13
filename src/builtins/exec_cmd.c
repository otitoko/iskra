#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#include "builtins/exec_cmd.h"

void exec_builtin(int (*cmd)(char*), char* args){

	if(cmd == NULL){
//		return 0;
	}

	cmd(args);
}

//implement proper error handling
void exec_ext_cmd(char** args){

	int pid = fork();
	if( pid == 0 ){
		execvp(args[0], args);
	}
	else{
		waitpid(pid, NULL, 0);
	}

}
