#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
	FILE *fp = fopen("objcode.txt", "r");
	int stradd, i, j;
	char cStrAdd[6], pname[10], line[100], sname[10];
	printf("Enter the program name : ");
	scanf("%s", pname);
	
	fscanf(fp, "%s", line);
	i=2;
	j=0;
	while(line[i] != '^'){
		sname[j++] = line[i++];
	}
	sname[j] = '\0';
	if(strcmp(sname, pname) != 0){
		printf("Invalid programe name !! \n");
		exit(0);
	}
	do{
		fscanf(fp, "%s", line);	
		if(line[0] == 'T'){
			for(i=2, j=0; i<8, j<6; i++, j++){
				cStrAdd[j] = line[i];
			}
			stradd = atoi(cStrAdd);
			i = 12;
			while(line[i] != '\0'){
				if(line[i] != '^'){
					printf("00%d\t%c%c\n",stradd, line[i], line[i+1]);
					i += 2;
					stradd++;
				}else{
					i++;
				}
			}
		}
			
	}while(!feof(fp));
	fclose(fp);
}
