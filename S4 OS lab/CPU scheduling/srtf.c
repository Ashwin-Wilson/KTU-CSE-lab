#include <stdio.h>

struct process{
	int no;
	int at, bt, wt, tat, rt;
};

int smallestProcessIndex(struct process *pr, int ct, int limit){

	int min_bt = 9999, min_index = -1;
	
	for(int i=0;i<limit;i++){
	
		if(pr[i].rt != 0 && pr[i].at <= ct){
		
			if(pr[i].bt <= min_bt){
			
				min_bt = pr[i].bt;
				min_index = i;
			}
		}
	}
	return min_index;
}

void main(){
	int limit, i, j, ct=0, spi;
	float avg_wt = 0, avg_tat = 0;
	
	printf("\nEnter the number of process: ");
	scanf("%d",&limit);
	
	struct process pr[limit];
	
	for(i=0;i<limit;i++){
		printf("\nEnter AT & BT of process %d : ", i);
		scanf("%d %d",&pr[i].at, &pr[i].bt );
		pr[i].rt = pr[i].bt;
		pr[i].no = i;
	}
	
	printf("\nPrNo \t AT \t BT \t WT \t TAT \t RT");
	
	do{
		spi = smallestProcessIndex(pr, ct, limit);
		if(spi == -1){
			break;
		}
		
		pr[spi].rt--;
		ct++;
		
		if(pr[spi].rt == 0){
			pr[spi].tat = ct - pr[spi].at;
			pr[spi].wt = pr[spi].tat - pr[spi].bt;
			
			avg_wt += pr[spi].wt;
			avg_tat += pr[spi].tat;
			
			printf("\n%d \t %d \t %d \t %d \t %d \t %d", pr[spi].no, pr[spi].at, pr[spi].bt, pr[spi].wt, pr[spi].tat, pr[spi].rt);
		}
		
		
	}while(ct);
	
	printf("\nAverage Waiting Time: %f", avg_wt / limit);
	printf("\nAverage Turn Around Time: %f\n", avg_tat / limit);
}






















