#include <stdio.h>
#include <stdlib.h>


int myStrLen(char *s){
	
	
	if(*s=='\0') return +0;
	
	return (myStrLen(s+1))+1;
}


int main(){
	
	
	char A[10];
	
	printf("Please enter a string under 10 characters\n");
	gets(A);
	
	printf("The number of characters in the string is %i", myStrLen(A));
}
