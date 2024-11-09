// PROGRAME FOR LINEAR SEARCH USING FUNCTION.
#include<stdio.h>
int arr[20],limit,i;

int srch(int num){
	int flag=0;
	
	for(i=0;i<limit;i++){
		if(arr[i]==num){
			flag=1;
			return i;
			break;
		}
	}
	
	if(flag==0){
		return 
	}
}

void main(){
	int num,result;
	printf("How many values do you have :");
	scanf("%d",&limit);
	
	printf("\nEnter %d values : ",limit);
	for(i=0;i<limit;i++){
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the number to search :");
	scanf("%d",&num);
	
	result = srch(arr,num,limit);
	
	if(result==21){
		printf("\n%d not found.",num);
	}
	else{
		printf("\n%d found at %d\n",num,result);
	}
}
