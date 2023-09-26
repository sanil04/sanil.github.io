#include <stdio.h>
#include <stdlib.h>

int myStrLen(char *s, int i){
	
	if (s[i] == '\0') return i;
	
	myStrLen(s, i+1);
}


int main (){
	
	
	char A[10];
	
	printf("Please enter a string under 10 characters\n");
	gets(A);
	
	
	printf("The number of characters in the string is %i", myStrLen(A,0));
	
}
