#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char trec[100];
void main(){
	char  ch[] = "100000";
//	strcat(trec, "T^");
//	strcat(trec, ch);
	sprintf(trec, "T^%s", ch);
	printf("%s", trec);
	int i=0;
	
	while (i<5){
		sprintf(trec + strlen(trec), "^nothing^%s", ch);
		printf("\n%s", trec);
		i++;
	}
	printf("\n%s", trec);
	
}
