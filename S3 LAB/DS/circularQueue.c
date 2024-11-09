#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int a[MAX], r=-1, f= -1;
void enqueue(){
	if(f== (r+1)%MAX)
		printf("OVERFLOW");
	else if(f== -1 && r== -1){
		f=r=0;
		printf("Enter the item to  insert: ");
		scanf("%d",&a[r]);
	}
	else{
		r= (r+1)%MAX;
		printf("Enter the item to  insert: ");
		scanf("%d",&a[r]);
	}
}
void dequeue(){

	int k;
	if(f == -1){
		printf("Underflow");
	}
	else{
		k= a[f];	
		printf("deleted item: %d",k);
		if(f==r)
			f=r=-1;
		else
			f = (f+1)%MAX;
	}
}
void display(){
	int i = f;
	if(f== -1 && r== -1)
		printf("Queue is empty.");
	else{
		printf("Queue is: ");
		while(i != r){
			printf("%d\t",a[i]);
			i= (i+1)%MAX;
		}
		printf("%d\t",a[r]);
	}
}
void main(){
	int choice;
	printf("\nCircular Queue operations:\n ");
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
