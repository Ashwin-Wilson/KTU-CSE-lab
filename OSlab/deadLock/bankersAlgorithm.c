#include <stdio.h>

struct process{
	int alloc[10];
	int max[10];
	int need[100];
	int finish;
};

int processIndex(struct process *pr, int plimit, int rlimit, int *avail){
	int index = -1, i, j, flag;
	
	for(i=0;i<plimit;i++){
	
		if(pr[i].finish == 0){
			flag = 0;
			for(j=0;j<rlimit;j++){
				if(pr[i].need[j] > avail[j]){
					flag = 1;
					break;
				}
			}
			if(flag == 0){
				pr[i].finish = 1;
				for(j=0;j<rlimit;j++){
					avail[j] += pr[i].alloc[j];
				}
				return i;	
			}
		}
	}
	return index;
	
}

void main(){
	
	int plimit, rlimit, i, j, index;
	
	printf("\nEnter the number of processes : ");
	scanf("%d", &plimit);
	
	struct process pr[plimit];
	
	printf("\nEnter the number of resources : ");
	scanf("%d", &rlimit);
	
	int avail[rlimit];
	int work[rlimit];
	
	printf("\nEnter the alloction matrix \n");
	
	for(i=0;i<plimit;i++){
		pr[i].finish = 0;
		for(j=0;j<rlimit;j++){
			scanf("%d", &pr[i].alloc[j]);
		}
	}
	
	printf("\nEnter the Max matrix \n");
	
	for(i=0;i<plimit;i++){
	
		for(j=0;j<rlimit;j++){
			scanf("%d", &pr[i].max[j]);
			pr[i].need[j] = pr[i].max[j] - pr[i].alloc[j];
		}
	}
	
	printf("\nEnter the avoid matrix: ");
	
	for(i=0;i<rlimit;i++){
		scanf("%d", &avail[i]);
		work[i] = avail[i];
	}
	
	
	for(i=0;i<plimit;i++){
		
		for(j=0;j<rlimit;j++){
			printf("%d\t", pr[i].need[j]);
		}
		printf("\n");
	}
	
	printf("\nSafe sequence is :  \n");
	do{
		
		index = processIndex(pr, plimit, rlimit, avail);
		if(index == -1){
		 break;
		}
		else{
			printf("pr%d\t", index);
		}
	}while(1);
	
}
