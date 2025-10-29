#include <string.h>
#include <stdio.h>
#define epsilon "\u03B5"

int pt = 0, len, flag = 1;
char str[30];

void E();
void T();
void F();
void TPRIME();
void EPRIME();
void ADVANCE();

int main(){
	printf("E -> TE' \nE' -> +TE'\%s \nT -> FT' \nT' -> *FT'\%s \nF -> (E)/a\n", epsilon, epsilon);
	printf("Enter the string: ");
	scanf("%s", str);
	len = strlen(str);
	E();
	if(flag && (pt == len)){
		printf("\nEntered string is Valid\n");
	}else{
		printf("\nEntered string is Invalid\n");
	}
	return 0;
}

void E(){
	T();
	EPRIME();
}

void T(){
	F();
	TPRIME();
}

void EPRIME(){
	if(str[pt] == '+'){
  		ADVANCE();
		T();
		EPRIME();	
	}
}

void TPRIME(){
	if(str[pt] == '*'){
  		ADVANCE();
		F();
		TPRIME();
	}
}

void ADVANCE(){
	pt++;
}

void F(){
	if(str[pt] == '('){
		ADVANCE();
		E();
		if(str[pt]==')'){
			ADVANCE();
		}else{
			flag = 0;
		}
	}else if(str[pt] == 'a'){
		ADVANCE();
	}else{
		flag = 0;
	}
}
