#include <unistd.h>
void main(){
	int pid = fork();
	if(pid == 0){
		printf("I'm child\n");
	}
	else if(pid > 0){
		printf("I'm patrent\n");
	}
	else{
		printf("child process creation failed\n");
	}
}
