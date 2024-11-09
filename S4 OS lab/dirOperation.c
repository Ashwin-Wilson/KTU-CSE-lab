#include<stdio.h>
#include<unistd.h>
#include<dirent.h>

struct dirent *d;
void main(){
	char buff[100];
	DIR *dptr;
	printf("Enter the directory.\n");
	scanf("%s",buff);
	dptr = opendir(buff);
	if(dptr == NULL){
		printf("Directory not found.\n");
	}else{
		while( d=readdir(dptr)){
			printf("Dir name: %s \n",d->d_name);
			//printf("Dir name: %ld \n",d->d_ino);
		}
	closedir(dptr);
	}
}
