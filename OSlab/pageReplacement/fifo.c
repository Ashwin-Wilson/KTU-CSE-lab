#include <stdio.h>

void main(){

	int rlimit, flimit, i, count=0, isExist, j, hit=0, pageFault;	
	
	printf("\nEnter the number of reference string : ");
	scanf("%d",&rlimit);
	
	int refStr[rlimit];
	
	for(i=0;i<rlimit;i++){
		scanf("%d",&refStr[i]);
	}
	
	printf("\nEnter the number of frames : ");
	scanf("%d",&flimit);
	
	int frame[flimit];
	
	for(i=0;i<flimit;i++){
		frame[i] = -1;
	}
	
	printf("\nPage replacement Process: \n");
	
	for(i=0;i<rlimit;i++){
	
		isExist = 0;
		for(j=0;j<flimit;j++){
			if(refStr[i] == frame[j]){
				isExist = 1;
				hit++;
				break;
			}
		}
		
		if(isExist == 0){
			frame[count] = refStr[i];
			count++;
		}
		
		for(j=0;j<flimit;j++){
			printf("%d \t", frame[j]);
		}
		
		if(isExist != 0){
				printf("hit");
		}
		printf("\n");
		
		if(count == flimit){
			count = 0;
		}
	}
	
	printf("\nNumber of page fault : %d", rlimit - hit);
	printf("\nNumber of hit : %d", hit);
	
}
