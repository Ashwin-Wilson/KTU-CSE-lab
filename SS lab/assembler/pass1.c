#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){

	int locctr, straddr = 0, prglen;
	char label[10], opcode[10], operand[10];
	FILE *fp1 = fopen("input.txt", "r");
	FILE *fp2 = fopen("optab.txt", "r");
	FILE *fp3 = fopen("intermediate.txt", "w");
	FILE *fp4 = fopen("symtab.txt", "w");
	FILE *fp5 = fopen("length.txt", "w");

	fscanf(fp1, "%s%s%s", label, opcode, operand);	

	if(strcmp(opcode , "START") == 0){
		straddr = atoi(operand);
		locctr = straddr;
		
	}else{
		locctr = 0;
	}

	fprintf(fp3, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
	fscanf(fp1, "%s%s%s", label, opcode, operand);
	
	while(strcmp(opcode , "END") != 0){
		if(strcmp(label, "**") == 0){
		
			fprintf(fp3, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
			fscanf(fp1, "%s%s%s", label, opcode, operand);
			locctr += 3;
			
		}else if(strcmp(opcode, "RESW") == 0){
		
			fprintf(fp4, "%s\t%d\n", label, locctr);
			fprintf(fp3, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
			fscanf(fp1, "%s%s%s", label, opcode, operand);
			locctr += (3*atoi(operand));
			
		}else if(strcmp(opcode, "RESB") == 0){
		
			fprintf(fp4, "%s\t%d\n", label, locctr);
			fprintf(fp3, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
			fscanf(fp1, "%s%s%s", label, opcode, operand);
			locctr += atoi(operand);
			
		}else if(strcmp(opcode, "BYTE") == 0 || strcmp(opcode, "WORD") == 0){
		
			fprintf(fp4, "%s\t%d\n", label, locctr);
			fprintf(fp3, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
			fscanf(fp1, "%s%s%s", label, opcode, operand);
			locctr += (strlen(operand)-3);
			
		}else{
			printf("Invalid opcode!");
			exit(0);
		}
	}
	fprintf(fp3, "%d\t%s\t%s\t%s", locctr, label, opcode, operand);
	fprintf(fp5, "%d", (locctr - straddr));
	
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);

}
