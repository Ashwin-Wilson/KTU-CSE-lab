#include <stdio.h>

struct block{
	int isAlloc, bno, bsize;
};

struct file{
	int fno, fsize, bno, bsize;
};

int bestBlock(struct block *b, int fsize, int blimit){
	int bestBlock = 99999, index = -1, i;
	for(i=0;i<blimit;i++){
		if(b[i].isAlloc == 0 && b[i].bsize >= fsize){\
			if(b[i].bsize <= bestBlock){
				bestBlock = b[i].bsize;
				index = i;
			}
		}
	}
	return index;
}

void main(){
	int flimit, blimit, i, j, index;
 	
 	printf("\nEnter the number of blocks : ");
 	scanf("%d",&blimit);
 	
 	struct block b[blimit];
 	
 	for(i=0;i<blimit;i++){
 	
 		printf("\nEnter size of block %d: ",i);
 		scanf("%d",&b[i].bsize);
 		b[i].bno = i;
 		b[i].isAlloc = 0;
 		
 	}
 	
 	printf("\nEnter the number of files : ");
 	scanf("%d",&flimit);
 	
 	struct file f[flimit];
 	
 	for(i=0;i<flimit;i++){
 		printf("\nEnter size of file %d: ",i);
 		scanf("%d",&f[i].fsize);
 		f[i].fno = i;
 		
 		index = bestBlock(b, f[i].fsize, blimit);
 		if(index == -1){
 			f[i].bno = -1;
 			f[i].bsize = -1;
 		}else{
 			f[i].bno = b[index].bno;
 			f[i].bsize = b[index].bsize;
 			b[index].isAlloc = 1;
 		}
 		
 	}
 	
 	printf("\nFno \t Fsize \t Bno \t Bsize \t fragment");
 	for(i=0;i<flimit;i++){
 		if(f[i].bno == -1){
 			printf("\n%d \t %d \t !alloc !alloc !alloc", f[i].fno, f[i].fsize);
 		}else{
	 		printf("\n%d \t %d \t %d \t %d \t %d", f[i].fno, f[i].fsize, f[i].bno, f[i].bsize, f[i].bsize - f[i].fsize);	
 		}
 	
 	}
 	
 	
 	
}
