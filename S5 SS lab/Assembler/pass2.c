#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	
	int  tlen=0, straddr;
	char locctr[10], label[10], opcode[10], operand[10], mnemonic[10], code[10], prglen[10], symbol[10], saddr[10], line[100], temp[100];
	
	
	FILE *fp1 = fopen("intermediate.txt", "r");
	FILE *fp2 = fopen("symtab.txt", "r");
	FILE *fp3 = fopen("optab.txt", "r");
	FILE *fp4 = fopen("objcode.txt", "w+");
	FILE *fp5 = fopen("length.txt", "r");
	FILE *fp6 = fopen("listfile.txt", "w");
	
	fscanf(fp5, "%s", prglen);
	
//	while(!feof(fp1)){
//		fscanf(fp1, "%s%s%s%s", locctr, label, opcode, operand);
//		if(strcmp(label, "**") == 0 || strcmp(opcode, "BYTE") == 0 || strcmp(opcode, "WORD") == 0){
//			tlen ++;
//		}
//	}
//	rewind(fp1);
//	tlen *= 3;
	
	fscanf(fp1, "%s%s%s%s", locctr, label, opcode, operand);
	fprintf(fp6, "%s%s%s%s", locctr, label, opcode, operand);
	
	if(strcmp(opcode, "START") == 0){
		fprintf(fp4, "S^%s^00%s^0000%s\n", label, operand, prglen);
		straddr = atoi(locctr);
	}
	
	fscanf(fp1, "%s%s%s%s", locctr, label, opcode, operand);
	fprintf(fp4, "T^00%s^##", locctr);
//	fprintf(fp4, "T^00%s^%X", locctr, tlen);
	
	while(strcmp(opcode, "END") != 0 ){
		 while(!feof(fp3)){
		 	fscanf(fp3, "%s%s", mnemonic, code);
		 	if(strcmp(mnemonic, opcode) == 0){
				fprintf(fp4, "^%s", code);
		 		break;
		 	}
		 }
		 rewind(fp3);
		  
		 while(!feof(fp2)){
		 	fscanf(fp2, "%s%s", symbol, saddr);
		 	if(strcmp(symbol, operand) == 0){
		 		fprintf(fp4, "%s", saddr);
		 		break;
		 	}
		 	
		 }
		 rewind(fp2);
		 
		 if(strcmp(opcode, "WORD") == 0){
			fprintf(fp4, "^%06X", atoi(operand));		 		
		 }
		 else if(strcmp(opcode, "BYTE") == 0){
		 	int i = 2;
			fprintf(fp4, "^");
			while(operand[i+1] != '\0'){
				fprintf(fp4, "%X", operand[i++]);
			}
		 }
		 fscanf(fp1, "%s%s%s%s", locctr, label, opcode, operand);	
	}
	
	fprintf(fp4, "\nE^%06d\n", straddr);
	
	rewind(fp4);
	fscanf(fp4, "%s", line);
	fscanf(fp4, "%s", line);
	int i = 12;
	while(line[i] != '\0'){
		if(line[i] != '^'){
			tlen++;
			i += 2;;
		}else{
			i++;
		}
	}
	
	printf("%d", tlen);
	line[10] = (tlen % 10) + '0';
	tlen /= 10;
	line[9] = (tlen % 10) + '0';
	rewind(fp4);
	fscanf(fp4, "%s", temp);
	fprintf(fp4, "\n%s", line);
		
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);
	fclose(fp6);
}
