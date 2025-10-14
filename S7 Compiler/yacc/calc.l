%{
	#include <stdlib.h>
	#include "y.tab.h"
	extern int yylval;
%}

%%

[0-9]+ {
	yylval = atoi(yytext);
	return NUMBER;
}
. return yytext[0];
\n return 0;

%%

int yywrap(){
	return 0;
}
