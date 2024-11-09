// PROGRAME FOR LINEAR SEARCH USING FUNCTION.
#include<stdio.h>

void main(){
	int arr[20],limit,i,num,result,flag=0;
	printf("How many values do you have :");
	scanf("%d",&limit);
	
	printf("\nEnter %d values : ",limit);
	
	for(i=0;i<limit;i++){
		scanf("%d",&arr[i]);
	}
	
	printf("\nEnter the number to search :");
	scanf("%d",&num);
	
	for(i=0;i<limit;i++){
		if(arr[i]==num){
			flag = 1;
			printf("\n%d found at position: %d\n",num,i+1);
			break;
		}
	}
	
	if(flag==0){
		printf("\n%d not found.\n",num);
	}
	
}
