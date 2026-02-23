#include <stdio.h>
#include <stdlib.h>

int main(){
	while(1){
		
		char* username = getenv("USER");
		char* pwd = getenv("PWD");

		printf("%s@%s# ",username, pwd);
		char s[64];
		fgets(s,sizeof(s)-1,stdin);
	}

	return 0;
}
