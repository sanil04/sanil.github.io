#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 1000


/*
	This function takes an array A containing n integers
	and deletes all integer less than x. It returns the
	new number of elements in the array.
*/
int deleteLessThan (int *A, int n, int x){
	
	int i = 0;
	int z = 0;
	int t = 0;
	
	while (z<n){ //n=7
		
		i = t;
		
		printf("%i \n", i);
		printf("%i \n", A[i]);
	
		if (A[i]<x){//x=-10
		
			
			while (i<n){//n=7
	 		A[i] = A[i+1];
	 		i++;
	 		}
		}
		
		i++;
		z++;
		t++;
	}
	
	
	
	
	
		
		
	
	
	
}

int outputArray (int *A, int n){
	for (int i = 0; i < n; i++){
		printf ("A[%i] = %i\n", i,A[i]);
	}
}

int main (){
	int myArray[MAX_NUMS] = {-3, -9, -18, -4, -1, -32, -78};
	int numElements = 7;
	int delNum = -10;
	
	printf ("Here is your array before deletion ...\n");
	outputArray(myArray, numElements);
	
	numElements = deleteLessThan (myArray, numElements, delNum);
	
	printf ("\n\n");
	printf ("Here is the array after deleting all elements ");
	printf ("that are less than %i ...\n", delNum);
	outputArray(myArray, numElements);
}
