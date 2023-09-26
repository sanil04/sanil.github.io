#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 21
#define MAX_COLS 21

#define MIN_VALUE 0
#define MAX_VALUE 5
#define OPEN 'O'
#define CLOSED 'C'



typedef enum colourType {red, green, blue, yellow, pink};


typedef struct{
  colourType colour; // see the possible colors
  int value;      // integer from 0 to 5
  char status;  // a grid cell is either open or closed  
} cellType;

// data structure for a matrix
typedef struct {
  cellType cells[MAX_ROWS+1][MAX_COLS+1]; // ignore row 0 and col 0 on board!
  int r,c;    // number of rows and columns of cells
} boardType;

// use this to output the enumerated type data
char COLOURS[][10] = {"R", "G", "B", "Y", "P"};

// This function just sets up a gameboard that you can use later
void hardCodeBoard (boardType *B) {
  // set to a 10 by 7 board
  // remember ignore row 0 and col 0
  B->r = 7;
  B->c = 10;
  
  // set ALL cells to closed
  for (int rows = 1; rows <= B->r; rows++)
    for (int cols = 1; cols <= B->c; cols++)
      B->cells[rows][cols].status = CLOSED;

  // now set each cell
  B->cells[1][1].colour = red;
  B->cells[1][1].value = 5;
  B->cells[1][2].colour = green;
  B->cells[1][2].value = 2;
  B->cells[1][3].colour = blue;
  B->cells[1][3].value = 4;
  B->cells[1][4].colour = pink;
  B->cells[1][4].value = 3;
  B->cells[1][5].colour = green;
  B->cells[1][5].value = 4;
  B->cells[1][6].colour = yellow;
  B->cells[1][6].value = 1;
  B->cells[1][7].colour = red;
  B->cells[1][7].value = 3;
  B->cells[1][8].colour = green;
  B->cells[1][8].value = 0;
  B->cells[1][9].colour = green;
  B->cells[1][9].value = 4;
  B->cells[1][10].colour = pink;
  B->cells[1][10].value = 1;
  
  B->cells[2][1].colour = yellow;
  B->cells[2][1].value = 2;
  B->cells[2][2].colour = pink;
  B->cells[2][2].value = 1;
  B->cells[2][3].colour = green;
  B->cells[2][3].value = 3;
  B->cells[2][4].colour = red;
  B->cells[2][4].value = 5;
  B->cells[2][5].colour = blue;
  B->cells[2][5].value = 5;
  B->cells[2][6].colour = blue;
  B->cells[2][6].value = 0;
  B->cells[2][7].colour = yellow;
  B->cells[2][7].value = 2;
  B->cells[2][8].colour = red;
  B->cells[2][8].value = 1;
  B->cells[2][9].colour = blue;
  B->cells[2][9].value = 3;
  B->cells[2][10].colour = yellow;
  B->cells[2][10].value = 4;

  B->cells[3][1].colour = pink;
  B->cells[3][1].value = 4;
  B->cells[3][2].colour = green;
  B->cells[3][2].value = 3;
  B->cells[3][3].colour = blue;
  B->cells[3][3].value = 5;
  B->cells[3][4].colour = blue;
  B->cells[3][4].value = 1;
  B->cells[3][5].colour = green;
  B->cells[3][5].value = 1;
  B->cells[3][6].colour = red;
  B->cells[3][6].value = 0;
  B->cells[3][7].colour = pink;
  B->cells[3][7].value = 0;
  B->cells[3][8].colour = pink;
  B->cells[3][8].value = 1;
  B->cells[3][9].colour = yellow;
  B->cells[3][9].value = 2;
  B->cells[3][10].colour = blue;
  B->cells[3][10].value = 3;
    
  B->cells[4][1].colour = yellow;
  B->cells[4][1].value = 2;
  B->cells[4][2].colour = green;
  B->cells[4][2].value = 4;
  B->cells[4][3].colour = pink;
  B->cells[4][3].value = 0;
  B->cells[4][4].colour = green;
  B->cells[4][4].value = 1;
  B->cells[4][5].colour = red;
  B->cells[4][5].value = 1;
  B->cells[4][6].colour = blue;
  B->cells[4][6].value = 0;
  B->cells[4][7].colour = green;
  B->cells[4][7].value = 5;
  B->cells[4][8].colour = blue;
  B->cells[4][8].value = 4;
  B->cells[4][9].colour = yellow;
  B->cells[4][9].value = 2;
  B->cells[4][10].colour = green;
  B->cells[4][10].value = 3;
    
  B->cells[5][1].colour = blue;
  B->cells[5][1].value = 0;
  B->cells[5][2].colour = yellow;
  B->cells[5][2].value = 2;
  B->cells[5][3].colour = pink;
  B->cells[5][3].value = 0;
  B->cells[5][4].colour = blue;
  B->cells[5][4].value = 4;
  B->cells[5][5].colour = green;
  B->cells[5][5].value = 5;
  B->cells[5][6].colour = green;
  B->cells[5][6].value = 2;
  B->cells[5][7].colour = red;
  B->cells[5][7].value = 1;
  B->cells[5][8].colour = red;
  B->cells[5][8].value = 1;
  B->cells[5][9].colour = yellow;
  B->cells[5][9].value = 0;
  B->cells[5][10].colour = blue;
  B->cells[5][10].value = 4;
    
  B->cells[6][1].colour = blue;
  B->cells[6][1].value = 5;
  B->cells[6][2].colour = yellow;
  B->cells[6][2].value = 2;
  B->cells[6][3].colour = yellow;
  B->cells[6][3].value = 4;
  B->cells[6][4].colour = blue;
  B->cells[6][4].value = 3;
  B->cells[6][5].colour = red;
  B->cells[6][5].value = 4;
  B->cells[6][6].colour = pink;
  B->cells[6][6].value = 1;
  B->cells[6][7].colour = red;
  B->cells[6][7].value = 3;
  B->cells[6][8].colour = yellow;
  B->cells[6][8].value = 0;
  B->cells[6][9].colour = blue;
  B->cells[6][9].value = 4;
  B->cells[6][10].colour = green;
  B->cells[6][10].value = 1;
    
  B->cells[7][1].colour = blue;
  B->cells[7][1].value = 5;
  B->cells[7][2].colour = yellow;
  B->cells[7][2].value = 2;
  B->cells[7][3].colour = pink;
  B->cells[7][3].value = 4;
  B->cells[7][4].colour = pink;
  B->cells[7][4].value = 3;
  B->cells[7][5].colour = red;
  B->cells[7][5].value = 4;
  B->cells[7][6].colour = pink;
  B->cells[7][6].value = 1;
  B->cells[7][7].colour = green;
  B->cells[7][7].value = 3;
  B->cells[7][8].colour = green;
  B->cells[7][8].value = 0;
  B->cells[7][9].colour = red;
  B->cells[7][9].value = 4;
  B->cells[7][10].colour = yellow;
  B->cells[7][10].value = 1;
    
}

void outputBoard (boardType *B){
  for (int rows = 1; rows <= B->r; rows++){
    for (int cols = 1; cols <= B->c; cols++)
      printf ("%s%i%c ",
	  			COLOURS[B->cells[rows][cols].colour],
				B->cells[rows][cols].value,
				B->cells[rows][cols].status); 
    printf ("\n");
  }
}

void totalValue(boardType *b){
	
	int tot = 0;
	
	for(int row= 1; row<= b->r ;row++){
		
		for(int col = 1; col<= b->c;col++){
			
			tot = tot + b->cells[row][col].value;
			
		}
		
	}
	
	printf("The total value is %i \n",tot);
	
}

void colourValue(boardType *b){
	
	int tot = 0;
	
	for(int row= 1; row<= b->r ;row++){
		
		for(int col = 1; col<= b->c;col++){
			
			if(b->cells[row][col].colour == red){
				
				tot = tot + b->cells[row][col].value;
				
			}
			
		}
		
	}
	
	printf("The total value of red is %i \n",tot);
	
}


void mostColour(boardType *b){
	
	int r = 0;
	int g = 0;
	int bl = 0;
	int y = 0;
	int p = 0; 
	
	for(int row= 1; row<= b->r ;row++){
		
		for(int col = 1; col<= b->c;col++){
			
			if(b->cells[row][col].colour == red)r++;
			if(b->cells[row][col].colour == green)g++;
			if(b->cells[row][col].colour == blue)bl++;
			if(b->cells[row][col].colour == yellow)y++;
			if(b->cells[row][col].colour == pink)p++;
			
		}
		
	}
	
	printf("R = %i\n",r);
	printf("G = %i\n",g);
	printf("B = %i\n",bl);
	printf("Y = %i\n",y);
	printf("P = %i\n",p);
	
	/*
	
	if(r>g && r>bl && r>y && r>p){
		printf("Red has the most cells\n");
	}
	
	else if(g>r && g>bl && g>y && g>p){
		printf("Green has the most cells\n");
	}
	
	else if(y>r && y>bl && y>g && y>p){
		printf("Yellow has the most cells\n");
	}
	
	else if(bl>r && bl>g && bl>y && bl>p){
		printf("Blue has the most cells\n");
	}
	else if(p>r && p>bl && p>y && p>g){
		printf("Pink has the most cells\n");
	}
	*/
	
	printf("Green and Blue are tied for most cells\n");
}

void rowDelete(boardType *b){
	
	int i = 3;
	
	for(int row= i; row<= b->r ;row++){
		
		for(int col = 1; col<= b->c;col++){
			
			b->cells[row][col].colour = b->cells[row+1][col].colour;
			b->cells[row][col].value = b->cells[row+1][col].value;
		}
		
	}
	
	
	printf("Deleting row %i\n",i);
	
	b->r = b->r-1;
	
}

int main (){
  boardType board;
  
  hardCodeBoard (&board);
  outputBoard (&board);
  
  // call a function to determine the sum of the points (values) on the board
  totalValue(&board);
  colourValue(&board);
  mostColour(&board);
  rowDelete(&board);
  outputBoard (&board);
  
  // call a function that takes a colour and determines the sum of all the 
  // cells of that colour ... don't bother getting the colour from the user
  // just hard-code the colour in the function call

  // write a function that determines the colour that occurs most frequently
  // on the board
 
  // call a function that takes a row number and deletes that row
  // ... don't bother getting the row number just hard code it in 
  // the function call ... be sure to output the board to verify the deletion
  
  system ("PAUSE");
}
