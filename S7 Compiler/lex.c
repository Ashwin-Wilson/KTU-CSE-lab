#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
	char str[30], c;
	int i = 0, num=0, line_count = 0;
	FILE *fp = fopen("input.txt", "w");
	
	printf("Enter c program:\n");
	while((c = getchar()) != EOF){
		putc(c, fp);
	}
	fclose(fp);
	
	fp = fopen("input.txt", "r");
	while((c = getc(fp)) != EOF){
		
		if(isdigit(c)){
			num = c - 48;
			while(isdigit(c = getc(fp))){
				num = num*10+(c-48);
			}
			printf("%d is a number\n", num);
			num = 0;
			ungetc(c, fp);
			
		}else if(isalpha(c)){
			str[i++] = c;
			c = getc(fp);
			while(isalpha(c) || isdigit(c) || c=='_' || c=='$'){
				str[i++] = c;
				c = getc(fp);
			}
			str[i] = '\0';			
			if( strcmp(str, "int") == 0 || strcmp(str, "char") == 0 ||
				strcmp(str, "float") == 0 || strcmp(str, "if") == 0 ||
				strcmp(str, "else") == 0 || strcmp(str, "for") == 0 
			){
				printf("%s is a keyword\n", str);
			}else{
				printf("%s is an identifier\n", str);
			}
			ungetc(c, fp);
			i=0;
			
		}else if(c==' ' || c=='\t'){
			printf("\n");
		}else if(c=='\n'){
			line_count++;
		}else{
			printf("%c is a special character\n", c);
		}
	}
	printf("Number of lines: %d\n", line_count);
	fclose(fp);
	
	return 0;
}
