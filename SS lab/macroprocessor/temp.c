#include<stdio.h>
#include<stdbool.h>
#include<string.h>

void main(){
	bool m=false,s=false,macro;
	int i,j,k,l,p,pcount,ocount,opcount;
	char opcode[10],label[10],oprands[10],doprands[10],dopcode[10],name[10],moprands[10][10],ooprands[10][10],poprands[20],ch;
	FILE* input=fopen("minput.txt","r");
	FILE* output=fopen("moutput.txt","w");
	FILE* namtab=fopen("namtab.txt","w");
	FILE* argtab=fopen("argtab.txt","w");
	FILE* deftab=fopen("deftab.txt","w");
	fscanf(input,"%s\t%s\t%s",label,opcode,oprands);
	while(strcmp(opcode,"END")!=0){
		if (strcmp(opcode,"MACRO")==0){
			fprintf(namtab,"%s\n",label);
			fprintf(deftab,"%s\t%s\n",label,oprands);
			pcount=1;
			j=0,k=0;
			for(i=0;oprands[i]!=NULL;i++){
				if(oprands[i]==','){	
					moprands[j++][k]=NULL;
					k=0;
					pcount++;
					}
				else
					moprands[j][k++]=oprands[i];
				}
			moprands[j][k]=oprands[i];
			m=true;
			}
		else if(m){
			if (strcmp(opcode,"MEND")==0){		
				m=false;
				fprintf(deftab,"%s\t%s\n",opcode,oprands);
				}
			else{
				ocount=1;
				j=0,k=0;
				for(i=0;oprands[i]!=NULL;i++){
					if(oprands[i]==','){
						ooprands[j++][k]=NULL;
						k=0;
						ocount++;
						}
					else
						ooprands[j][k++]=oprands[i];
					}
				ooprands[j][k]=oprands[i];
				k=0;
				for(i=0;i<ocount;i++){
					for(j=0;j<pcount;j++){
						if(strcmp(ooprands[i],moprands[j])==0){
							doprands[k++]='?';
							doprands[k++]=(char)j+49;
							doprands[k++]=',';
							break;
							}
						}
					}
				doprands[k-1]=NULL;	
				fprintf(deftab,"%s\t%s\n",opcode,doprands);
				}
			}
		else if (strcmp(opcode,"START")==0){	
			fprintf(output,"%s\t%s\t%s\n",label,opcode,oprands);
			s=true;
			fprintf(namtab,"END\n");
			fclose(namtab);
			fclose(deftab);
			}
		else if(s){
			fprintf(output,"%s\t%s\t%s\n",label,opcode,oprands);
			namtab=fopen("namtab.txt","r");
			fscanf(namtab,"%s",name);
			macro=true;
			while (strcmp(name,"END")!=0){
				if (strcmp(name,opcode)==0){
					pcount=1;
					for(i=0;oprands[i]!='\0';i++)
						if(oprands[i]==','){
							oprands[i]='\n';
							pcount++;
							}
					fprintf(argtab,"%s",oprands);
					deftab=fopen("deftab.txt","r");
					fscanf(deftab,"%s\t%s",dopcode,doprands);
					while(strcmp(opcode,dopcode)!=0){
						fscanf(deftab,"%s\t%s",dopcode,doprands);
						}
					fscanf(deftab,"%s\t%s",dopcode,doprands);
					while (strcmp(dopcode,"MEND")!=0){
						opcount=1;
						for(i=0;doprands[i]!='\0';i++)
							if(doprands[i]==','){
								opcount++;
								}
						l=0;
						for(i=0;i<opcount;i++){
							p=((int)doprands[i*3+1])-48;
							k=0;
							for(j=1;j<p;j++)
								while(oprands[k++]!='\n');
							while(oprands[k]!='\n' && oprands[k]!='\0')
								poprands[l++]=oprands[k++];
							poprands[l++]=',';
							}
						poprands[l-1]='\0';
						fprintf(output,"**\t%s\t%s\n",dopcode,poprands);
						fscanf(deftab,"%s\t%s",dopcode,doprands);
						}
					fclose(deftab);
					break;
					}
				fscanf(namtab,"%s",name);
				}		
			fclose(namtab);
			}
		fscanf(input,"%s\t%s\t%s",label,opcode,oprands);
		}
	fprintf(output,"%s\t%s\t%s\n",label,opcode,oprands);
	fclose(argtab);
	fclose(input);
	fclose(output);
	namtab=fopen("namtab.txt","r");
	printf("\n\nNAMTAB\n\n");
	ch=fgetc(namtab);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(namtab);
		}
	fclose(namtab);
	deftab=fopen("deftab.txt","r");
	printf("\n\nDEFTAB\n\n");
	ch=fgetc(deftab);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(deftab);
		}
	fclose(deftab);
	argtab=fopen("argtab.txt","r");
	printf("\n\nARGTAB\n\n");
	ch=fgetc(argtab);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(argtab);
		}
	fclose(argtab);
	output=fopen("moutput.txt","r");
	printf("\n\nOUTPUT\n\n\n");
	ch=fgetc(output);
	while(ch!=EOF){
		printf("%c",ch);
		ch=fgetc(output);
		}
	fclose(output);
	}
				

