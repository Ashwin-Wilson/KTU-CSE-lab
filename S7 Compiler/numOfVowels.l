%{
int v=0;
int c=0;

%}

%%

[aeiouAEIOU] {v++;}
[a-zA-z] {c++;}
"\n" {printf("number of vowels are:%d\n",v);
 v=0;
 printf("number of consonants are:%d\n",c);
 c=0;
 }
 
%%

int main()
{
printf("Enter the string of vowels and consonants:");
yylex();
return 0;
}
int yywrap()
{
return 1;
}