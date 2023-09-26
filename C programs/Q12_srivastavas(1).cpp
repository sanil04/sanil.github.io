#include <stdio.h>
#include <stdlib.h>

int palindrome(char *s, int lo, int hi){
	
	if(hi>=lo){
		
		if(s[hi]!=s[lo]) return 0;
		
		return palindrome(s, lo+1, hi-1);
	}
	
	return 1;
	
}

int myStrLen(char *s, int i){
	
	if (s[i] == '\0') return i;
	
	myStrLen(s, i+1);
}


int main(){
	
	char A[10];
	int lo = 0;
	int hi = 0;
	
	printf("Please enter a string under 10 characters\n");
	gets(A);
	
	hi = (myStrLen(A,0))-1;

	
	
	if(palindrome(A,lo,hi)){
		printf("%s is a palendrome\n",A);
	}
	else{
		printf("%s isn't a palendrome\n",A);
	}
	
}
