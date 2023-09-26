#include <stdio.h>
#include <stdlib.h>

int countMults(int *a, int lo, int hi, int mult){
	
	if(lo<=hi){
		
		if((a[lo] % mult)!= 0) return countMults(a,lo+1,hi,mult);
		
		else return countMults(a,lo+1,hi,mult)+1;
	}
	
	return +0;
}


int main(){
	
	int lo = 0;
	int hi = 0;
	int mult = 0;
	int a[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	
	printf("Please enter low\n");
	scanf("%i",&lo);
	
	printf("Please enter high\n");
	scanf("%i",&hi);
	
	printf("Please enter mult\n");
	scanf("%i",&mult);
	
	printf("There are %i multiples \n",countMults(a,lo,hi,mult));
	
	
	
}
