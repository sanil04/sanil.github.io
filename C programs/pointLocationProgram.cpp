#include <stdio.h>
#include <stdlib.h>

#define MAX_POINTS 26
/*
	A point (x,y) in the Cartesian coordinate can be located
	in quadrant 1, quadrant 2, quadrant 3, quadrant 4, on the
	x-axis, on the y-axis or at the origin.
	
	
	In this program you will get up to a max of 26 points
	from the user. Ask the user for the number of points they
	wish to enter. The first point entered will be A , next will
	be B and so on.
	
	Next you will produce the following output:
	
Here are your 3 points ...
	Point    Coordinates     Location
	    A        (-13,0)       x-axis
	    B	     (5, 56)           Q1
	    C       (78, -9)           Q4

Here your 3 points sorted by location...
	Point    Coordinates     Location
	    B	     (5, 56)           Q1
	    C       (78, -9)           Q4
	    A        (-13,0)       x-axis
	    
	    
	You are not allowed to use STRUCTURES in this program.
	
	Note that sprintf (s, "%s is %i years old", "Joe", 58);
	will store "Joe is 58 years old" in s.
	
	printf ("%20s", "Fish") will output Fish right-aligned in 20 spaces.
	
		    
*/

// keep in mind the sort order is Q1, Q2, Q3, Q4, 
// x-axis, y-axis, origin

void input(int *X,int *Y,int max, int *c){
	
	for(int i=0; i<max; i++){
		
		c[i]=i+65;
		printf("Please enter coordinate %c X\n",c[i]);
		scanf("%i", &X[i]);
		
		printf("Please enter coordinate %c Y\n",c[i]);
		scanf("%i", &Y[i]);
		
	}
	printf("\n");
	
}

void location(int *X,int *Y,int max,int *L){
	
	for(int i=0; i<max; i++){
		
		if (X[i]>0 && Y[i]>0) L[i] = 1;
		
		if (X[i]<0 && Y[i]>0) L[i] = 2;
		
		if (X[i]<0 && Y[i]<0) L[i] = 3;
		
		if (X[i]>0 && Y[i]<0) L[i] = 4;
		
		if (X[i]!=0 && Y[i]==0) L[i] = 5;
		
		if (X[i]==0 && Y[i]!=0) L[i] = 6;
		
		if (X[i]==0 && Y[i]==0) L[i] = 7;
		
	}
	
}

void output(int *X,int *Y,int max,int *L, int *C){
	
		
		printf ("%10s %10s %10s\n", "Point", "Coordinates", "Location");
	
	
	
	
		for(int i=0; i<max; i++){
			
			if (L[i] == 1){
			
			printf("%10c %6s%i, %i) %10s\n", C[i],"(", X[i], Y[i], "Q1");
			
			}
			
			if (L[i] == 2){
			
			printf("%10c %6s%i, %i) %10s\n", C[i],"(", X[i], Y[i], "Q2");
			
			}
			
			if (L[i] == 3){
			
			printf("%10c %6s%i, %i) %10s\n", C[i],"(", X[i], Y[i], "Q3");
			
			}	
			
			if (L[i] == 4){
			
			printf("%10c %6s%i, %i) %10s\n", C[i],"(", X[i], Y[i], "Q4");
			
			}
		
			if (L[i] == 5){
			
			printf("%10c %6s%i, %i) %10s\n", C[i],"(", X[i], Y[i], "X-axis");
			
			}
			
			if (L[i] == 6){
			
			printf("%10c %6s%i, %i) %10s\n", C[i],"(", X[i], Y[i], "Y-axis");
			
			}
			
			if (L[i] == 7){
			
			printf("%10c %6s%i, %i) %10s\n", C[i],"(", X[i], Y[i], "Origin");
			
			}
			
				
		}
		
		printf("\n");
		
		
	}




void sort (int *X,int *Y,int max,int *L, int *C){
	
	
	
	int z = 0;
	
	int temp;
	
	while (z<max){
		
		int i = max-1;
	
	
		for(i;i>=0;i--){
		
			if(L[i]<L[i-1]){
				temp = L[i];
				L[i] = L[i-1];
				L[i-1] = temp;
				
				temp = X[i];
				X[i] = X[i-1];
				X[i-1] = temp;
				
				temp = Y[i];
				Y[i] = Y[i-1];
				Y[i-1] = temp;
				
				temp = C[i];
				C[i] = C[i-1];
				C[i-1] = temp;
				
			
			}
		}
		z++;
	
	}
		


}





int main(){

	int numpoint;
	
	printf("How many points do you wish to enter?\n");
	scanf("%i", &numpoint);
	
	int X[numpoint];
	int Y[numpoint];
	int L[numpoint];
	int C[numpoint];
	
	input(X,Y,numpoint,C);
	
	location(X,Y,numpoint,L);
	
	output(X,Y,numpoint,L,C);
	
	sort(X,Y,numpoint,L,C);
	
	output(X,Y,numpoint,L,C);
	
	return 0;
}
