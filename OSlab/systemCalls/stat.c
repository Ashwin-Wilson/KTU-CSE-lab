#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void main(){

	char str[100];
	struct stat *bf = (struct stat*)malloc(sizeof(struct stat));
	
	printf("\nEnter the path of file: ");
	scanf("%s", str);
	
	stat(str, bf);
	
	printf("\nUser id: %d", bf->st_uid);
	printf("\nBlock size : %ld", bf->st_blksize);
	printf("\nTime : %ld", bf->st_atime);
	printf("\nNo. of links : %ld", bf->st_nlink);
}
