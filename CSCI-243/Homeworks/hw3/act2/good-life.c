/// bad-life.c
///
/// This is derived from faulty code downloaded by copy-paste in 2015, and 
/// modified to use curses for screen display.
///
/// This code needs serious work in these areas:
/// <ol>
/// <li>  syntax: there are a number of warnings that cause errors.
/// </li>
/// <li>  semantics: the game algorithm implementation is incorrect.
/// </li>
/// <li>  design: the implementation needs function and value refactoring.
/// </li>
/// <li>  style: formatting is poor; the mix of TAB and spaces indentation
/// needs correction, and spacing between tokens is inconsistent.
/// The course style puts the '{' at the end of the function header, not
/// on a line of its own, and function headers belong at the left margin.
/// </li>
/// <li>  documentation is almost non-existent.
/// </li>
/// <li>  proper, public C documentation uses /// or /** ... */ format comments.
/// </li>
/// </ol>
///

#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>
//
// curses programs need to link with the -lcurses flag 
// For manual pages, run 'man curses' and
// also see https://github.com/tony/NCURSES-Programming-HOWTO-examples/
//


void header(void){
	printf("\n\t..Welcome to the Game of life..\n");
}	

//FIX2 & FIX 3 int x. int y.
void survivalRule(char life[][20]){
	int row, col;
	int neighbors = 0;
	for(row = 1; row<19; row++){
		for(col = 1; col<19; col++){	
			// fix1 ' ' is used for single char
			if( life[row][col]== '*'){
				if(life[row - 1][col - 1] == '*')
					++neighbors;
			   	if(life[row - 1][col] == '*')
				  	++neighbors;
			   	if(life[row - 1][col + 1] == '*')
				  	++neighbors;
			   	if(life[row][col - 1] == '*')
				  	++neighbors;
			   	if(life[row][col + 1] == '*')
					++neighbors;
			   	if(life[row + 1][col - 1] == '*')
				  	++neighbors;
			   	if(life[row + 1][col] == '*')
				  	++neighbors;
			   	if(life[row + 1][col + 1] == '*')
				  	++neighbors;
			   	if(neighbors == 2 || neighbors == 3){
					//FIX1 
				  	life[row][col] = '*';
			   	}
			}
		}
	}
	return;
}

//FIX 6 & 7. int x. int y
void birthRule(char life[][20]){
	int row, col;
	int neighbors = 0;
	for(row = 1; row<19; row++){
		for(col = 1; col<19; col++){
			if( life[row][col]== '*'){
			   	if(life[row - 1][col - 1] == '*')
				  	neighbors++;
			   	if(life[row - 1][col] == '*')
				  	neighbors++;
			   	if(life[row - 1][col + 1] == '*')
				  	neighbors++;
			   	if(life[row][col - 1] == '*')
				  	neighbors++;
			   	if(life[row][col + 1] == '*')
				  	neighbors++;
			   	if(life[row + 1][col - 1] == '*')
				  	neighbors++;
			   	if(life[row + 1][col] == '*')
				  	neighbors++;
				//FIX 4 == 
			   	if(life[row + 1][col + 1] == '*')
				  	neighbors++;
			   	if(neighbors == 3){	
					//FIX 5 =
			   		life[row][col] = '*';
			   	}
			}
		}
	}
	return;
}

//FIX 10 & 11 int x. int y.
void deathRule(char life[][20]){
	int row, col;
	int neighbors = 0;
	for(row = 1; row<19; row++){
		for(col = 1; col<19; col++){
			if( life[row][col] == '*'){
			   	if(life[row - 1][col - 1] == '*')
				  	neighbors++;
			   	if(life[row - 1][col] == '*')
				  	neighbors++;
			   	if(life[row - 1][col + 1] == '*')
				  	neighbors++;
			   	if(life[row][col - 1] == '*')
				  	neighbors++;
			   	if(life[row][col + 1] == '*')
				  	neighbors++;
			   	if(life[row + 1][col - 1] == '*')
				  	neighbors++;
			   	if(life[row + 1][col] == '*')
				  	neighbors++;
				//FIX 8 ==
			   	if(life[row + 1][col + 1] == '*')
				  	neighbors++;
			   	if(neighbors < 2 || neighbors > 4){	
					//FIX 9 =
				  	life[row][col] = ' ';
			   	}
			}
		}
	}
	return;
}

   	
int main(void){	  
	//FIX 16 unused gen variable.
	int orgs;
	//FIX 15 undused variable b, a
	int i, row, col;
	int count = 0;
	int numrows; 
	int numcols;
	//FIX 13 unused variable
	//FIX 12 unused variable
	char life[20][20];
   	header();
	printf("\nPlease enter the initial number of organisms: ");
	scanf("%i", &orgs);
	// start curses environment and find boundaries of window
	initscr();                            // Start curses mode 
	getmaxyx( stdscr, numrows, numcols);  // this is a MACRO; no & needed
	mvprintw( numrows - 1, numcols / 4, "screen is %d wide by %d high\n",numcols, numrows);
        refresh();
	srand( 31 );
	for(i = 0; i<orgs; i++){
		row = rand();
		row %= 20;
		col = rand();
		col %= 20;
		//fix3 
		life[row][col] = '*';
	}
	for(row = 0; row<20; row++){
		for(col = 0; col<20; col++){
			if(life[row][col] != '*')
				//fix3 
				life[row][col] = ' ';
			}
		}
	while ( 1 ) {
		move( 0, 0);
		for(row = 0; row<20; row++){
			for(col = 0; col<20; col++){
				//fix2 %c instead of %s 
				printw("%c", life[row][col]);
			}
			printw( "\n");
		 }
		move( 20, 0);	
		refresh();
		printw("generation: %d\n", count);
		count++;
		birthRule(life);
		survivalRule(life);
		deathRule(life);
	}
	endwin(); // End curses mode at the end of the program
	return 0;
}

