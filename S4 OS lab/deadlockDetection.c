#include<stdio.h>

void main(){
	int n,i,res;
	printf("Enter no of process: ");
	scanf("%d",&n);
	printf("Enter no of resource: ");
	scanf("%d",&res);
	
	
	//int finish[n];
	struct process{
		int alloc[res];
		int req[res];
		int finish;
	}p[n];
	
	//setting p[i].finish as zero.
	for(i=0;i<n;i++) 
		p[i].finish = 0;
		
	//reading the alloc and req of each process.
//	for(i=0;i<n;i++){
//		printf("Enter process %d: (alloc) : ",i);
//		for(int j=0;j<res;j++)
//			scanf("%d",&p[i].alloc[j]);
			
//		printf("Enter process %d: (req) : ",i);
//		for(int j=0;j<res;j++)
//			scanf("%d",&p[i].req[j]);
//	}
	
	p[0].alloc[0] = 0;
	p[0].alloc[1] = 1;
	p[0].alloc[2] = 0;
	p[0].req[0] = 0;
	p[0].req[1] = 0;
	p[0].req[2] = 0;
	
	p[1].alloc[0] = 2;
	p[1].alloc[1] = 0;
	p[1].alloc[2] = 0;
	p[1].req[0] = 2;
	p[1].req[1] = 0;
	p[1].req[2] = 2;
	
	p[2].alloc[0] = 3;
	p[2].alloc[1] = 0;
	p[2].alloc[2] = 3;
	p[2].req[0] = 0;
	p[2].req[1] = 0;
	p[2].req[2] = 0;
	
	p[3].alloc[0] = 2;
	p[3].alloc[1] = 1;
	p[3].alloc[2] = 1;
	p[3].req[0] = 1;
	p[3].req[1] = 0;
	p[3].req[2] = 0;
	
	p[4].alloc[0] = 0;
	p[4].alloc[1] = 0;
	p[4].alloc[2] = 2;
	p[4].req[0] = 0;
	p[4].req[1] = 0;
	p[4].req[2] = 2;
		 
	
	
	//reading work or available
	int work[res];
	printf("Enter available: ");
	scanf("%d %d %d",&work[0],&work[1],&work[2]);
	
	//displaying the process details
	printf("Process\tallo\treq\n");
	for(i=0;i<n;i++){
		printf("p%d\t",i);
		for(int j=0;j<res;j++)
			printf("%d ",p[i].alloc[j]);
			
		printf("\t");
		
		for(int j=0;j<res;j++) 
			printf("%d ",p[i].req[j]);
		printf("\n");
	}
	
	printf("Available: %d %d %d\n",work[0],work[1],work[2]);
	//logic for deadlock detection algorithm
	int flag = 0;
	while(flag = 0){
		printf("in loop");
		int loc = -1;
		for(int j=0;j<n;j++){
			if(p[j].finish == 0 && p[j].req[0] <= work[0] && p[j].req[1] <= work[1] && p[j].req[2] <= work[2]){
				loc = j;
				break;
			}
		} 
		if(loc == -1){
			flag = 1;
		}
		else{
			work[0] = work[0] + p[loc].alloc[0]; 
			work[1] = work[1] + p[loc].alloc[1]; 
			work[2] = work[2] + p[loc].alloc[2]; 
			p[loc].finish = 1;
		}
	}
	
	printf("\n");
	for(int j=0;j<n;j++) 
			printf("%d \t",p[j].finish);
			
	printf("\n");
	
}
