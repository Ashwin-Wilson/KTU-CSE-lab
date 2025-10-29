%{
	#include "y.tab.h"
%}

%%

[a-zA-Z]+ return ID;
[0-9]+ return NUMBER;
. return yytext[0];
\n return 0;

%%

int yywrap(){
	return 1;
}
