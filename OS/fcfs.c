#include <stdio.h>

struct process{
	int prNo;
	int bt,at,wt,tat;
};


void main()
{
    int limit;
    float av_wt = 0, av_tat = 0;
    int ct = 0;
    printf("Enter number of processes: ");
    scanf("%d", &limit);
	
	struct process pr[limit];
	
    for(int i=0;i<limit;i++){
    	pr[i].prNo = i+1;	
        printf("\n\nProcess %d",i+1);
        printf("\nEnter Burst Time: ");
        scanf("%d",&pr[i].bt);
        printf("Enter Arrival Time: ");
        scanf("%d",&pr[i].at);
    }
    
    struct process temp;
   	for(int j=limit-1;j>=0;j--){
  	  	for(int i=0;i<j;i++){
    		if(pr[i].at > pr[i+1].at){
    			temp = pr[i];
    			pr[i] = pr[i+1];
    			pr[i+1] = temp;
    		}
    	} 
    }
    
    pr[0].wt = 0;
    pr[0].tat = pr[0].bt;
    ct = pr[0].bt;
    av_tat = pr[0].bt;
    
    for(int i=1;i<limit;i++){
    	pr[i].wt = ct - pr[i].at;
    	ct = ct + pr[i].bt;
    	pr[i].tat = ct - pr[i].at;
    	av_wt = pr[i].wt + av_wt;
    	av_tat = pr[i].tat + av_tat;
    }
    
    printf("Process No \t AT \t BT \t WT \t TAT\n");
    for(int i=0;i<limit;i++){
    	printf("Process %d:\t%d\t%d\t%d\t%d\n", pr[i].prNo, pr[i].at, pr[i].bt, pr[i].wt, pr[i].tat);
    }
    
    av_wt = av_wt / limit;
    av_tat = av_tat / limit;
    printf("\nAverage Waiting Time : %f",av_wt);
    printf("\nAverage Turn Around Time : %f\n",av_tat);
   
}
