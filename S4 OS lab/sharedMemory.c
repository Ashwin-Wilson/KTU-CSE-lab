
#include<unistd.h>
#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>

 
extern int errno;
void main(){
 	char* c = (char*)malloc(100 * sizeof(char));
	int fd = open("test.txt", O_RDONLY);
	
	if(fd < 0){
		printf("File not found\n");
	}
	else{
		printf("File found\n");
		int sz = read(fd, c, 10);
  		//printf("called read(% d, c, 10). returned that %d bytes were read.\n", fd, sz);
   	 	c[sz] = '\0';
    	printf("Those bytes are as follows: %s\n", c);
		
	}
	close(fd);
	
}
