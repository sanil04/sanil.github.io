#include <stdio.h>
#include <stdlib.h>

/*
	Write a function that finds the greatest common divisor of two
	positive integers. The calling function must pass two positive 
	integers. The gcd of 8 and 12 is 4.
	
	You are NOT allowed to use Euclid's algorithm! Don't worry about
	it if you do not know this algorithm.
*/
int findGCD (int a, int b){
	// currently this function will execute but it will return 
	// garbage to the calling function 
	int i = 0;
	int torf = 0;
	
	if (a>b) i = a;
	else i = b;
	
	while (torf == 0){
	
	
		if(a % i == 0  && b % i == 0 ){
			torf == 1; 
			return i;
		} 
		else i--;
	}

}

int main (){
	int n1, n2;
	int gcd;
	
	while(1){
		printf ("Enter a positive integer: ");
		scanf("%i", &n1);
		printf ("Enter a second positive integer: ");
		scanf("%i", &n2);
		
		gcd = findGCD(n1, n2);
		printf ("gcd(%i,%i) = %i\n\n",n1, n2,gcd);
		system ("pause");
		system ("cls");
		// pause the program and clear the output screen
	}
	return 0;
	
}
