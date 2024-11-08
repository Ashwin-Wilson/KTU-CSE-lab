#include <stdio.h>
struct process{
	int bt,at,wt,tat;
};
void main(){
	int limit, ct, i;
	float av_wt=0, av_tat=0;
	
	printf("Enter number of Process: ");
	scanf("%d",&limit);

	struct process pr[limit];
	for(i=0;i<limit;i++){
		printf("Enter details of process %d",i+1);
		printf("\nBT: ");
		scanf("%d",&pr[i].bt);
		printf("AT: ");
		scanf("%d",&pr[i].at);
	}
	
	struct process temp;
	for(i=limit-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(pr[j].at > pr[j+1].at){
				temp = pr[j];
				pr[j] = pr[j+1];
				pr[j+1] = temp;	
			}
		}
	}
	
	pr[0].wt = 0;
	pr[0].tat = pr[0].bt;
	ct = pr[0].bt;
	av_tat = pr[0].bt;
	for(i=1;i<limit;i++){
		pr[i].wt = ct - pr[i].at;
		ct = ct + pr[i].bt;
		pr[i].tat = ct - pr[i].at;
		av_wt += pr[i].wt;
		av_tat += pr[i].tat;
	}
	
	printf("\nPro\tat\tbt\twt\ttat");
	for(i=0;i<limit;i++){
		printf("\np%d\t%d\t%d\t%d\t%d\n",i+1,pr[i].at,pr[i].bt,pr[i].wt,pr[i].tat);
	}
	printf("Average Waiting time: %f", av_wt/limit);
	printf("\nAverage turn around time: %f", av_tat/limit);
	
	
}
