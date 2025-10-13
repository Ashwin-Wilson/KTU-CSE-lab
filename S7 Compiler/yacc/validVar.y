%{
#include<stdio.h>
int valid=1;
%}
%token digit letter
%%
start : letter s
s : letter s
| digit s
|
;
%%
int yyerror()
{
printf("\n It is not a valid variable\n");
valid=0;
return 0;
}
int main()
{
printf("\nEnter a variable name\n");
yyparse();
if(valid)
{
printf("\n It is a valid variable\n");
}
}
