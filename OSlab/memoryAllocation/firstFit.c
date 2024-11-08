 #include <stdio.h>
 
 struct block{
 	int bno, bsize;
 };
 
 struct file{
 	int fno, fsize, bno, bsize;
 };
 
 void main(){
 
 	int flimit, blimit, i, j;
 	
 	printf("\nEnter the number of files : ");
 	scanf("%d",&flimit);
 	
 	struct file f[flimit];
 	
 	for(i=0;i<flimit;i++){
 		printf("\nEnter size of file %d: ",i);
 		scanf("%d",&f[i].fsize);
 		f[i].fno = i;
 		f[i].bno = -1;
 		f[i].bsize = -1;
 	}
 	
 	
 	printf("\nEnter the number of blocks : ");
 	scanf("%d",&blimit);
 	
 	struct block b[blimit];
 	
 	for(i=0;i<blimit;i++){
 	
 		printf("\nEnter size of block %d: ",i);
 		scanf("%d",&b[i].bsize);
 		b[i].bno = i;
 		
 		for(j=0;j<flimit;j++){
 			if(f[j].bno == -1 && f[j].fsize <= b[i].bsize){
 				f[j].bno = b[i].bno;
 				f[j].bsize = b[i].bsize;
 				break;
 			}
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
