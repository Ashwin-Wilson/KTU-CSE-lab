#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
	char path[10];
	struct stat *buf;
	buf = (struct stat *)malloc(sizeof(struct stat));
	printf("Enter the path of file: ");
	scanf("%s",path);
	stat(path,buf);
	printf("userid : %d\n",buf->st_uid);
	printf("block size : %ld\n",buf->st_blksize);
	printf("time : %ld\n",buf->st_atime);
	printf("permission : %d\n",buf->st_mode);
	printf("no. of link : %ld\n",buf->st_nlink);
}
