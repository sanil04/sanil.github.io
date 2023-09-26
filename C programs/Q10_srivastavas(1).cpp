#include <stdio.h>
#include <stdlib.h>
//I dont get the point of a funciton as you would be passing in the answer-1 so the function would just add one
int main(){
	
	char A[10];
	int i = 0;
	
	printf("Please enter a string under 10 characters\n");
	gets(A);
	
	while(A[i] != '\0')i++;
	
	printf("The number of characters in the string is %i", i);
	
}


