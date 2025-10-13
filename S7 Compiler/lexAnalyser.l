keywords "if"|"for"|"else"|"int"|"char"|"double"|"float"
const[0-9]*
identifier[a-zA-Z0-9]*
math_op[+|-|*|/]
comp_op[=|>|<]
sp_ch[,|;|(|)|{|}]

%%

{keywords} printf("\n%s\t is a keyword",yytext);
{const} printf("\n%s\t is a constant",yytext);
{identifier} printf("\n%s\t is an identifier",yytext);
{math_op} printf("\n%s\t is a arithemetic operator",yytext);
{comp_op} printf("\n%s\t is a comparision operator", yytext);
{sp_ch} printf("\n%s\t is a special character", yytext);

%%

int yywrap(){
	return 1;
}

int main(int argc, char **argv){
	yyin = fopen(argv[1], "r");
	yylex();
	fclose(yyin);
	return 0;
}	
