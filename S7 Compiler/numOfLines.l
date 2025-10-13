%{
#include<stdio.h>
#include<string.h>
int wc=0, lc=0, ch=0, sc=0;
%}
%%
\n lc++;
[ ] sc++;
[^\t\n] ch++;
%%
void main(){
    printf("Enter the program\n");
    yylex();
    printf("\n No of lines = %d",lc);
    printf("\n No of characters = %d", ch);
    printf("\n No of words = %d", lc+sc);
}

int yywrap(){
    return 1;
}