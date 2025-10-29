%{
	int valid = 1;
%}
%token ID NUMBER
%left '+''-'
%left '*''/''%'

%%

stmt : E;
E : E'+'E |
	E'-'E |
	E'*'E |
	E'/'E |
	E'%'E |
	'('E')'|
	ID |
	NUMBER
;

%%

int yyerror(){
	printf("Invalid Arithementic Expression\n");
	valid = 0;
	return 0;
}

int main(){
	printf("Enter an Arithemetic Expression: ");
	yyparse();
	if(valid){
		printf("Valid Arithementic Expression\n");
	}
	return 0;
}
