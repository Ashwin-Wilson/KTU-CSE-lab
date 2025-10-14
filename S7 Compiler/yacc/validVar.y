%{
	#include <stdio.h>
	int valid = 1;
%}
%token letter digit

%%

start : letter s
s : letter s | digit s | ;

%%

int yyerror(){
	printf("Invalid\n");
	valid = 0;
	return 0;
}

int main(){
	printf("Enter a string: ");
	yyparse();
	if(valid){
		printf("Valid\n");
	}
	return 0;
}
