%{
	int v = 0;
	int c = 0;
%}

%%

[aeiou AEIOU] {v++;}
[a-z A-Z] {c++;}
\n {
	printf("\nVowels: %d \nConsonants: %d\n", v, c);
	v = 0;
	c = 0;
}
%%

int yywrap(){
	return 1;
}

int main(){
	printf("\nEnter a string: ");
	yylex();
	return 0;
}
