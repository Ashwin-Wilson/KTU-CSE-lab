%{
	#include <stdio.h>
	int valid = 1;
%}
%token NUMBER
%left '+''-'
%left '*''/''%'
%left '('')'

%%

ArithemeticExpression : E {
	printf("Result: %d\n", $$);
	return 0;
}

E : E'+'E {$$=$1+$3;} |
	E'-'E {$$=$1-$3;} |
	E'*'E {$$=$1*$3;} |
	E'/'E {$$=$1/$3;} |
	E'%'E {$$=$1%$3;} |
	NUMBER {$$=$1}
;

%%

int yyerror(){
	printf("Invalid\n");
	valid = 0;
	return 0;
}

int main(){
	printf("Enter an expression: ");
	yyparse();
	if(valid){
		printf("Valid\n");
	}
	return 0;
}
