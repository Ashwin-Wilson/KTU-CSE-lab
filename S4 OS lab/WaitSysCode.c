#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
void main(){
	int pid = fork();
	if(pid == 0){
		printf("I'm child\n");
	}
	else if(pid > 0){
		printf("I'm patrent\n");
		wait(NULL);
		printf("patrent waited for child\n");
		
	}
	else{
		printf("child process creation failed\n");
	}
}
