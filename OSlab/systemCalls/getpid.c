#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
	int pid = fork();
	
	if(pid == 0){
		printf("\nChild process : %d", getpid());		
	}else if(pid > 0){
		wait(NULL);
		printf("\nParent process : %d", getpid());		
	}else{
		printf("\nProcess creation failed!");		
	}
}


