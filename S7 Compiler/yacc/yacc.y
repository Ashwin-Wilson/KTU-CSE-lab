%{
#include "y.tab.h"
%}
%token ID NUMBER
%left '+''-'
%left '*''/'
%%
stmt:expr;
expr:expr'+'expr|expr'-'expr|expr'*'expr|expr'/'expr|'('expr')'|ID|NUMBER;
%%
int main()
{
printf("\n Enter an expression :\n");
yyparse();
printf("\n Valid Expression \n");
exit(0);
}
int yyerror()
{
printf("\n Invalid expressuion \n");
exit(0);
}