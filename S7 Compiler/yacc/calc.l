%{
#include<stdio.h>
#include"y.tab.h"
extern int yyval;
%}
%%
[0-9]+ {j
yylval=atoi(yytext);
return NUMBER;
}
[\t];
[\n] return 0;
. return yytext[0];
%%
int yywrap()
{
return 1;
}