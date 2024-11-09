
#include<unistd.h>
#include<fcntl.h>
#include<sys/file.h>
#include<sys/file.h>
//#include <errno.h>
#include <stdio.h>

 
extern int errno;
void main(){
	int fd = open("test.txt", O_RDONLY);
	
	if(fd < 0){
		printf("File not found\n");
	}
	else{
		printf("File found\n");
		
	}
	
	
}
