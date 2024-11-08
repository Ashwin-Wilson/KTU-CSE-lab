#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
void main(){
	int pid = fork();
	if(pid == 0){
		printf("I'm child\n");
		printf("child ID : %d\n",getpid());
	}
	else if(pid > 0){
		printf("I'm parent\n");
		printf("parent ID : %d\n",getpid());
	}
	else{
		printf("child process creation failed\n");
	}
}
