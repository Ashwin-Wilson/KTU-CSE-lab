#include<stdio.h>
#include<stdlib.h>
int i,maxLimit,arr[20],front=-1,rear=-1;
void dequeue(){
	front++;
	if(front<=rear){
		printf("\nEntered queue is: ");
		for(i=front;i<=rear;i++){
			printf("%d\t",arr[i]);
		}	
	}
	
	else{
		front = -1;
		rear = -1;
		printf("\nNo elements in queue.");
	}
	
}
void enqueue(){
	if(rear<maxLimit-1){
		if(front == -1)
			front=0;
		printf("Enter the element to be inserted");
		scanf("%d",&arr[++rear]);
		
		printf("\nEntered queue is: ");
		for(i=front;i<=rear;i++){
			printf("%d\t",arr[i]);
		}
	}
	else{
		printf("Queue is full.");
	}
	
}
void display(){
	if(rear != -1){
		printf("\nEntered queue is: ");
		for(i=front;i<=rear;i++){
			printf("%d\t",arr[i]);
		}
	}
	else{
		printf("\nNo elements to display.");
	}
}
void main(){
	int choice;
	printf("Enter max limit of your queue: ");
	scanf("%d",&maxLimit);
	printf("\nEnter %d values: \n",maxLimit);
	for(i=0;i<maxLimit;i++){
		scanf("%d",&arr[i]);
	}
	front=0;
	rear=maxLimit-1;
	while(1){
		printf("\nEnter you choice:");
		printf("\n1:Enqueue\n2:Dequeue\n3:Display\n4:Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default: 
		 		printf("invalid choice");
		 		break;
		}
	}
}
