#include <stdio.h>
#include <stdlib.h>

int empty, full=0, mutex=1, x=0;

void wait(int* s){
	while(*s <= 0 );
	*s -= 1;
}

void signal(int* s){
	*s += 1;
}

void producer(){
	wait(&mutex);
	wait(&empty);
	++x;
	printf("\nProducer produces item: %d",x);
	signal(&full);
	signal(&mutex);
}

void consumer(){
	wait(&mutex);
	wait(&full);
	printf("\n Consumer consumes item: %d",x);
	--x;
	signal(&empty);
	signal(&mutex);
}


void main(){

	int choice;
	
	printf("Enter buffer size: ");
	scanf("%d",&empty);

#pragma omp critical
	
	while(1){
		printf("\n1: producer \n2: consumer \n3: exit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				if((mutex == 1) && (empty != 0)){
					producer();
				}
				else{
					printf("\n Buffer is full!");
				}
				break;
				
			case 2:
				if((mutex == 1) && (full != 0)){
					consumer();
				}
				else{
					printf("\n Buffer is empty!");
				}
				break;
				
			case 3:
				exit(0);
				break;
				
			default:
				printf("\nInvalid choice.");
		}
	}
}
