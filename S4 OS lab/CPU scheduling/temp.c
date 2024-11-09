#include<stdio.h>
#define executed 1
#define not_exec 0
//structure for a process
typedef struct process
{
    int arr;        //arrival time
    int bt;         //burst time
    int wt;		//waiting time
    int ft;		//finish time
    int status;
} process;

void srtf(process *pr,int n,float *awt,float *atat);
int shortestProcess(process *pr,int n,int ct);
int sumArray(int *arr,int n);
void dispArray(int *arr,int n);

int main()
{
    int n,i;
    float awt,atat;
    process pr[20];
    printf("\nEnter the no. of processes:");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        printf("\nEnter the arrival and burst time of process %d: ",i+1);
        scanf("%d %d",&pr[i].arr,&pr[i].bt);
    }
    srtf(pr,n,&awt,&atat);
    printf("\nThe average waiting time(AWT)=%.2f",awt);
    printf("\nThe average turnaround time(ATAT)=%.2f\n",atat);
    return 0;
}
void srtf(process *pr,int n,float *awt,float *atat)
{
	int i,ct=0,spi;	//ct->current time,spi->shortest process index
	//initialising each process as not executed
	for(i=0;i<n;i++)
	{
		pr[i].status=not_exec;
		pr[i].wt=0;
	}
	do
	{
	    //printf("spi=%d",spi);
		spi=shortestProcess(pr,n,ct);
		if(spi==-1)
            break;

		//increase the waiting time of processes which have arrived but are not executing
		for(i=0;i<n;i++)
		{
            if(i!=spi && pr[i].status!=executed && ct>=pr[i].arr)
                pr[i].wt++;
        }
		//printf("wt=%d",pr[spi].wt);
		ct++;		//updating current time
		pr[spi].ft=ct-pr[spi].arr;		//finish time of the executed process
        pr[spi].bt--;
        if(pr[spi].bt<=0)
        {
            pr[spi].status=executed;
            pr[spi].ft=ct-pr[spi].arr;
        }
	}while(ct);

	for(i=0;i<n;i++)
	{
		(*awt)+=pr[i].wt;
		(*atat)+=pr[i].ft;
	}
	*awt=*awt/n;
	*atat=*atat/n;

	printf("\nWaiting Times:");
	for(i=0;i<n;i++)
	{
		printf("\t%d",pr[i].wt);
	}

	printf("\nturnaround Times:");
	for(i=0;i<n;i++)
	{
		printf("%d\t",pr[i].ft);
	}

}
//returns the index of shortest process arrived beore the current time ct
int shortestProcess(process *pr,int n,int ct)
{
	int i,min_bt=99999,min_index=-1;
	for(i=0;i<n;i++)
	{
		if(pr[i].status==not_exec && pr[i].arr<=ct)
		{
			if(pr[i].bt<min_bt)
			{
			    min_bt=pr[i].bt;
				min_index=i;
			}
		}
	}
	return min_index;
}

//to give the sum of the array
int sumArray(int *arr,int n)
{
    int sum=0,i;
    for(i=0; i<n; i++)
    {
        sum+=arr[i];
    }
    return sum;
}

//to display an array
void dispArray(int *arr,int n)
{
    int i=0;
    for(i=0; i<n; i++)
    {
        printf("%d",arr[i]);
    }
}
