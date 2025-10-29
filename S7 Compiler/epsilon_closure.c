#include <stdio.h>
#include <string.h>

char result[20][20], states[20][20], copy[20];

void display(int n){
	printf("epsilon closure of %s => {", copy);
	for(int i=0; i<n; i++){
		printf("\t%s\t", result[i]);
	}
	printf("}\n");
}

void add_state(char state[20], int i){
	strcpy(result[i], state);
}

void main(){
	int n, i;
	char state[20], state1[20], state2[20], input[20];
	
	FILE *fp = fopen("input.dat", "r");
	
	printf("Enter no of states: ");
	scanf("%d", &n);
	printf("Enter the states: \n");
	
	for(int j=0; j<n; j++){
		scanf("%s", states[j]);
	}
	
	for(int j=0; j<n; j++){
		i = 0;
		
		strcpy(state, states[j]);
		strcpy(copy, states[j]);
		add_state(state, i++);
		
		while(!feof(fp)){
			fscanf(fp, "%s%s%s", state1, input, state2);
			if(strcmp(state, state1) == 0){
				if(strcmp(input, "e")==0){
					add_state(state2, i++);
					strcpy(state, state2);
				}
			}
		}
		display(i);
		rewind(fp);
	}
	
	fclose(fp);
}
