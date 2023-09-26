#include <stdio.h>
#include <stdlib.h>


int point(char *s){
	
	if(*s=='\0') return +0;
	
	if(*s >= 'a' && *s <= 'z') return (point(s+1))+10;
	else if(*s >= 'A' && *s <= 'Z') return (point(s+1))+20;
	else if(*s >= '0' && *s <= '9') return (point(s+1))+50;
	else if(*s == '*') return (point(s+1))+100;
	else (point(s+1));
}

int main(){
	
	char A[10];
	
	printf("Please enter a string under 10 characters\n");
	gets(A);

	
	printf("The value of the given string is %i points\n",point(A));
	
}
