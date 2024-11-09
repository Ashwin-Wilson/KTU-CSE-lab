#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include<unistd.h>
void main()
{
	int pid = fork();
	if(pid == 0){
   		char *args[]={"./EXEC",NULL};
    	printf("To child file\n");
    	execv(args[0],args);
	}
	else if(pid > 0){
		wait(NULL);
		printf("Back to patrent file\n");
	}
}
