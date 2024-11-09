#include<stdio.h>
#include<stdlib.h>
int arr[20],i,j,limit;
void insertion(){
	int index,val,temp;
	printf("Enter the position for insertion:");
	scanf("%d",&index);
	if(index>=limit){
		printf("Enter valid index..!");
	}
	else{
		printf("Enter the value to be inserted:");
		scanf("%d",&val);
		
		limit++;
		for(i=limit-1;i>=(index-1);i--){
			temp = arr[i+1];
			arr[i+1] = arr[i];
			arr[i] = temp;
		}
		arr[index-1] = val;
		printf("%d inserted at %d position.\n",val,index);
		for(i=0;i<limit;i++){
			printf("%d\t",arr[i]);
		}			
	}
}
void deletion(){
	int index,val,flag=0;
	printf("Enter the value to be deleted: ");
	scanf("%d",&val);
	for(i=0;i<limit;i++){
		if(arr[i]==val){
			flag = 1;
			for(j=i;j<limit;j++){
				arr[j] = arr[j+1];
			}
			limit--;
			break;
		}
	}
	if(flag == 0){
		printf("%d not found. Unable to delete.",val);
	}
	else{
		for(i=0;i<limit;i++){
			printf("%d\t",arr[i]);
		}
	}
}
void searching(){
	int val,flag=0;
	printf("Enter the value to be Searched: ");
	scanf("%d",&val);
	for(i=0;i<limit;i++){
		if(arr[i]==val){
			printf("%d found at position %d",val,i+1);
			flag = 1;
			break;
		}
	}
	if(flag == 0){
		printf("%d not found.",val);
	}
}
void display(){
	if(limit){
		printf("\nEntered array is: ");
		for(i=0;i<limit;i++){
			printf("%d\t",arr[i]);
		}
	}
	else{
		printf("\nNo elements to display.");
	}
}
void main(){
	int choice;
	printf("How many elements do you have: ");
	scanf("%d",&limit);
	printf("\nEnter %d values: \n",limit);
	for(i=0;i<limit;i++){
		scanf("%d",&arr[i]);
	}
	while(1){
		printf("\nEnter you choice:");
		printf("\n1:Insertion\n2:Deletion\n3:Searching\n4:Display\n5:Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				insertion();
				break;
			case 2:
				deletion();
				break;
			case 3:
				searching();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
			default: 
		 		printf("invalid choice");
		 		break;
		}
	}
}
