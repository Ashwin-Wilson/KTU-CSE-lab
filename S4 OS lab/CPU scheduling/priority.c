#include <stdio.h>

struct process{
	int no;
	int at, bt, wt, tat, rt, prio;
};

int maxPriorityIndex(struct process *pr, int ct, int limit){

	int max_prio = 9999, max_prio_index = -1;
	
	for(int i=0;i<limit;i++){
	
		if(pr[i].rt != 0 && pr[i].at <= ct){
		
			if(pr[i].prio <= max_prio){
			
				max_prio = pr[i].prio;
				max_prio_index = i;
			}
		}
	}
	return max_prio_index;
}

void main(){
	int limit, i, j, ct=0, mpi;
	float avg_wt = 0, avg_tat = 0;
	
	printf("\nEnter the number of process: ");
	scanf("%d",&limit);
	
	struct process pr[limit];
	
	for(i=0;i<limit;i++){
		printf("\nEnter AT & BT & Priority of process %d : ", i);
		scanf("%d %d %d",&pr[i].at, &pr[i].bt, &pr[i].prio );
		pr[i].rt = pr[i].bt;
		pr[i].no = i;
	}
	
	printf("\nPrNo \t AT \t BT \t Prio \t WT \t TAT \t RT");
	
	do{
		mpi = 	maxPriorityIndex(pr, ct, limit);	
		if(mpi == -1){
			break;
		}
		
		pr[mpi].rt--;
		ct++;
		
		if(pr[mpi].rt == 0){
			
			pr[mpi].tat = ct - pr[mpi].at;
			pr[mpi].wt = pr[mpi].tat - pr[mpi].bt;
			
			avg_wt += pr[mpi].wt;
			avg_tat += pr[mpi].tat;
			
			printf("\n%d \t %d \t %d \t %d \t %d \t %d \t %d", pr[mpi].no, pr[mpi].at, pr[mpi].bt, pr[mpi].prio, pr[mpi].wt, pr[mpi].tat, pr[mpi].rt);
			
		}	
		
	}while(ct);
	
	printf("\nAverage Waiting Time: %f", avg_wt / limit);
	printf("\nAverage Turn Around Time: %f\n", avg_tat / limit);
	
	
}


















