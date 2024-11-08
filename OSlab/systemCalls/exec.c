#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
	
	int pid = fork();
	
	if(pid == 0){
		char *arg[] = {"./exec",NULL};
		printf("\nTo child process");
		execv(arg[0], arg);
	}else if(pid > 0){
		wait(NULL);
		printf("\nBack to parent prcess");
	}
}
