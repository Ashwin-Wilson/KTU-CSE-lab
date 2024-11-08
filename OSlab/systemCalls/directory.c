#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

struct dirent *d;

void main(){
	
	char path[100];
	
	printf("\nEnter the path of directory : ");
	scanf("%s",path);

	DIR *dptr = opendir(path);
	
	if(dptr == NULL){
		printf("\nDir not found");
	}else{
		d = readdir(dptr);
		printf("\nDir name : %s", d->d_name);
		printf("\nInode number : %ld", d->d_ino);
	}
	
	closedir(dptr);
}
