#include<stdio.h>
#include<stdlib.h>
int arr[20],i,j,limit,maxLimit;
void push(){
	int val;
	if(limit<maxLimit){
		printf("Enter value to push: ");
		scanf("%d",&val);
		arr[limit] = val;
		limit++;
		printf("Stack updated:\n");
		for(i=0;i<limit;i++){
			printf("%d \t",arr[i]);
		}
	}
	else{
		printf("Stack reached max limit. OVERFLOW.\nPush not possible..!!");
	}
}
void pop(){
	int temp;
	if(limit>0){
		temp = arr[limit-1];
		limit--;
		printf("Stack updated:\n");
		for(i=0;i<limit;i++){
			printf("%d \t",arr[i]);
		}	
	}
	else{
		printf("No values in STACK. UNDERFLOW.\nPop not possible..!!");
	}
}
void display(){
	if(limit>=0){
		printf("\nStack is:  ");
		for(i=0;i<limit;i++){
			printf("%d\t",arr[i]);
		}
	}
	else{
		printf("\nNo elements to display.: ");
	}
}
void main(){
	int choice;
	printf("Enter max limit of your stack: ");
	scanf("%d",&maxLimit);
	printf("How many elements do you have: ");
	scanf("%d",&limit);
	
	printf("\nEnter %d values: \n",limit);
	for(i=0;i<limit;i++){
		scanf("%d",&arr[i]);
	}
	while(1){
		printf("\nEnter you choice:");
		printf("\n1:Push\n2:Pop\n3:Display\n4:Exit\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default: 
		 		printf("invalid choice");
		 		break;
		}
	}	
}
