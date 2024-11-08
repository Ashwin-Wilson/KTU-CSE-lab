#include <stdio.h>
#include <stdlib.h>

struct process {
	int no;
	int at,bt,wt,tat,rm;
};

int shortestProcessIndex(struct process *pr, int ct, int limit){

	int min_bt = 9999, min_index = -1, i;
	
	for(i=0;i<limit;i++){
		if(pr[i].rm != 0 && pr[i].at <= ct){
			if(pr[i].bt <= min_bt){
				min_bt = pr[i].bt;
				min_index = i;
			}
		}
	}
	return min_index;
}

void main(){

	int limit, i, j, spi,ct=0;
	float avg_wt = 0, avg_tat = 0;
	
	printf("Enter the number of processes: ");
	scanf("%d",&limit);
	
	struct process pr[limit];
	
	//for reading the process details
	for(i=0;i<limit;i++){
		printf("\nEnter the AT & BT of processes %d: ",i);
		scanf("%d %d",&pr[i].at ,&pr[i].bt);
		pr[i].rm = pr[i].bt;
		pr[i].no = i;
	}
	
	printf("\nprNo \t AT \t BT \t WT \t TAT \t RT");
	
	do{
		spi = shortestProcessIndex(pr, ct, limit); //shortest process index
		if(spi == -1){
			printf("\npposf");
			break;
		}
		
		ct = ct + pr[spi].bt;
		pr[spi].rm = 0;
		pr[spi].tat = ct - pr[spi].at;
		pr[spi].wt = pr[spi].tat - pr[spi].bt;
		
		avg_wt += pr[spi].wt;
		avg_tat += pr[spi].tat;
		
		printf("\n%d \t %d \t %d \t %d \t %d \t %d", pr[spi].no, pr[spi].at, pr[spi].bt, pr[spi].wt, pr[spi].tat, pr[spi].rm);
		
	}while(ct);	
	
	printf("\nAverage Waiting time: %f", avg_wt / limit);
	printf("\nAverage Turn around time: %f", avg_tat / limit);
}

