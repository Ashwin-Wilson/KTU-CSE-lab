#include<stdio.h>
void sort(int arr[20],int limit){
	int i,j,temp,count;
	count = limit-1;
	for(i=count;i>0;i--){
		for(j=0;j<i;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("\nSorted array :\n");
	for(i=0;i<limit;i++){
		printf("%d\t ",arr[i]);
	}
	printf("\n");
}
void main(){
	int arr[20],i,limit,j;

	printf("How many numbers do you have : ");
	scanf("%d",&limit);
	
	printf("\nEnter %d elements : \n",limit);
	for(i=0;i<limit;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,limit);		
}
