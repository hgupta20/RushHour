/* --------------------------------------------------------
 * Traffic.cpp
 *     Text-based version of the game RushHour, where the
 *     object is to move the vehicles such that the small
 *     car can exit the right of the board.
 *
 * System: Windows 10,Dev-C++
 * Author: Harsh Devprakash Gupta
 *
 * ToDo: Make a Rush Hour Game.
 * -------------------------------------------------
 */
 

#include <iostream>
#include <cctype>      // for toupper()
using namespace std;

// Global variables and constants
// Variables to store the board pieces
char  p1, p2, p3, p4, p5, p6,
      p7, p8, p9,p10,p11,p12,
     p13,p14,p15,p16,p17,p18,
     p19,p20,p21,p22,p23,p24,
     p25,p26,p27,p28,p29,p30,
     p31,p32,p33,p34,p35,p36;
     
char vehicle; // global variables for Vehicle
char direction; // global variables for Direction
int numOfSquares; // global variables for Number Of Squares


//--------------------------------------------------------------------
// Display ID info
void displayIDInfo()
{

	cout << "Author: Harsh Devprakash Gupta" << endl;
	cout << "System: C++ in Dev C++" << endl;
	cout<< endl;
}//end displayIDInfo()


//--------------------------------------------------------------------
// Display Instructions
void displayInstructions()
{
    cout << "Welcome to the traffic game!                          " << endl
         << "                                                      " << endl
         << "Move the vehicles so that the Red car (RR) can exit   " << endl
         << "the board to the right. Each move should be of the    " << endl
         << "of the form:   CDN   where:                           " << endl
         << "   C  is the vehicle to be moved                      " << endl
         << "   D  is the direction (u=up, d=down, l=left or r=right)" << endl
         << "   N  is the number of squares to move it             " << endl
         << "For example GR2  means move the G vehicle to the right" << endl
         << "2 squares.  Lower-case input such as   gr2  is also   " << endl
         << "accepted.  Enter '-' to reset board, or 'x' to exit.  " << endl;
}//end displayInstructions()



//--------------------------------------------------------------------
// Display the board, using the current values in the global variables.
void displayBoard( )
{
	cout << endl;
	cout << "- - - - - - -" << endl;
	cout << "|" << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << " " << p6 << "|" << endl;
	cout << "|" << p7 << " " << p8 << " " << p9 << " " << p10 << " " << p11 << " " << p12 << "|" << endl;
	cout << "|" << p13 << " " << p14 << " " << p15 << " " << p16 << " " << p17 << " " << p18 << "" << endl;
	cout << "|" << p19 << " " << p20 << " " << p21 << " " << p22 << " " << p23 << " " << p24 << "|" << endl;
	cout << "|" << p25 << " " << p26 << " " << p27 << " " << p28 << " " << p29 << " " << p30 << "|" << endl; 
	cout << "|" << p31 << " " << p32 << " " << p33 << " " << p34 << " " << p35 << " " << p36 << "|" << endl;
	cout << "- - - - - - -" << endl;
    
    // p1, p2, ... p36 variables.
    
    
}//end displayBoard()


//--------------------------------------------------------------------
/*  Board and corresponding global variable values are:
           - - - - - - - -
         1 | G G . . . Y |
         7 | P . . B . Y |
        13 | P R R B . Y >
        19 | P . . B . . |
        25 | O . . . T T |
        31 | O . F F F . |
           - - - - - - - -
 */
//--------------------------------------------------------------------
// Resetting the Board, with the user Input.
void ResetTheBoard()
{
    cout << "You have chosen to reset the board." << endl;    
    cout << "Enter 36 characters for the new board:" << endl;
    
	cin >> p1 >> p2 >> p3 >> p4 >> p5 >> p6;
	cin >> p7 >> p8 >> p9 >> p10 >> p11 >> p12;
	cin >> p13 >> p14 >> p15 >> p16 >> p17 >> p18;
	cin >> p19 >> p20 >> p21 >> p22 >> p23 >> p24;
	cin >> p25 >> p26 >> p27 >> p28 >> p29 >> p30;
	cin >> p31 >> p32 >> p33 >> p34 >> p35 >> p36;
	cout << "The board has been reset";
	
}//end ResetTheBoard()
//--------------------------------------------------------------------
// Moving Right or Down, with the user Input.
int moveRightorDown(char &n1, char &n2, char &n3, char &n4, char &n5, char &n6, int carSize, char distance)
{
    char tempVar;   			 					 // temporary Character Variable for swapping
    if (carSize == 2 ){			 					// Comparing with the Car Size- 2
    	if (n1 == vehicle && n3 == '.'){
			tempVar = n3;
			n3 = n1;
			n1 = tempVar; 
			return 0;   	
		}
		else if (n1 != vehicle && n2 == vehicle && n4 == '.'){
			tempVar = n4;
			n4 = n3;
			n2 = tempVar; 
			return 0;    	
		}
		else if (n2 != vehicle  && n3 == vehicle && n5 == '.'){
			tempVar = n5;
			n5 = n3;
			n3 = tempVar;
			return 0;   	
		}
		else if (n3 != vehicle && n4 == vehicle && n6 == '.'){
			tempVar = n6;
			n6 = n4;
			n4 = tempVar;    
			return 0;	
		}
		else {
			return 1;
		}
		
	}
	else if (carSize == 3){ // Comparing with the Car Size- 3
		if (n1 == vehicle && n4 == '.'){
			tempVar = n4;
			n4 = n1;
			n1 = tempVar;
			return 0;    	
		}
		else if (n1 != vehicle && n2 == vehicle && n5 == '.'){
			tempVar = n5;
			n5 = n2;
			n2 = tempVar;
			return 0;    	
		}
		else if (n1!= vehicle && n2 != vehicle && n3 == vehicle && n6 == '.'){
			tempVar = n6;
			n6 = n3;
			n3 = tempVar;
			return 0;    	
		}
		else {
			return 1;
		}
		
			
	}
	
	
	
}//end moveRightorDown()
//--------------------------------------------------------------------
// Moving Left or Up, with the user Input.
int moveLeftorUp(char &n1, char &n2, char &n3, char &n4, char &n5, char &n6, int carSize, char distance)
{
    char tempVar;
    if (carSize == 2 ){ // Comparing with the Car Size- 2
    	if (n6 == vehicle && n4 == '.'){
			tempVar = n6;
			n6 = n4;
			n4 = tempVar;
			return 0;    	
		}
		else if (n6 != vehicle && n5 == vehicle && n3 == '.'){
			tempVar = n5;
			n5 = n3;
			n3 = tempVar;
			return 0;    	
		}
		else if (n5 != vehicle && n4 == vehicle && n2 == '.'){
			tempVar = n4;
			n4 = n2;
			n2 = tempVar;
			return 0;    	
		}
		else if (n4!= vehicle && n3 == vehicle && n1 == '.'){
			tempVar = n3;
			n3 = n1;
			n1 = tempVar;
			return 0;    	
		}
		else{
			return 1;
		}
		
	}
	else if (carSize == 3){ // Comparing with the Car Size- 3
		if (n6 == vehicle && n3 == '.'){
			tempVar = n6;
			n6 = n3;
			n3 = tempVar; 
			return 0;   	
		}
		else if (n6 != vehicle && n5 == vehicle && n2 == '.'){
			tempVar = n5;
			n5 = n2;
			n2 = tempVar;
			return 0;    	
		}
		else if (n6 != vehicle && n5 != vehicle && n4 == vehicle && n1 == '.'){
			tempVar = n4;
			n4 = n1;
			n1 = tempVar;
			return 0;    	
		}
		else{
			return 1;
		}
			
	}
	
	
}//end moveLeftorUp()
//--------------------------------------------------------------------
// Handling Pieces, with the user Input.
void handlePieces(char &n1, char &n2, char &n3, char &n4, char &n5, char &n6, int carSize, char distance, char command, int roworcol)
{
	int flag =0;
	if (roworcol <=6 && command == 'R'){ 			// Comparing with Direction and Row or Column
			if (numOfSquares == 1){
    				flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance); 	   				
				}
			else if (numOfSquares == 2){
    				flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance); 
					flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance);   				
				}
			else if (numOfSquares == 3){
    				flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance);  
					flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance);
					flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance);  				
				}
			else if (numOfSquares >= 4){
    				flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance);
					flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance);
					flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance);
					flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance);    				
				}
				if (flag==1){
					cout << "*** Move was attempted, but couldn't be completed. ***" << endl;
				}
				displayBoard();
			
	}
    else if (roworcol <= 6 && command == 'L'){
			if (numOfSquares == 1){
    				flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance);    				
				}
		else if (numOfSquares == 2){
    				flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance); 
					flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance);   				
				}
		else if (numOfSquares == 3){
    				flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance);  
					flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance);
					flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance);  				
				}
		else if (numOfSquares >= 4){
    				flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance);
					flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance);
					flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance);
					flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance);    				
				}
				if (flag==1){
					cout << "*** Move was attempted, but couldn't be completed. ***" << endl;
				}
				displayBoard();
			
	}
	else if (roworcol >= 6 && command == 'U'){
			if (numOfSquares == 1){
    				flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance);    				
				}
		else if (numOfSquares == 2){
    				flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance); 
					flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance);  				
				}
		else if (numOfSquares == 3){
    				flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance);  
					flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance);
					flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance); 				
				}
		else if (numOfSquares >= 4){
    				flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance);
					flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance);
					flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance);
					flag = moveLeftorUp(n1, n2, n3, n4, n5, n6, carSize, distance);   				
				}
				if (flag==1){
					cout << "*** Move was attempted, but couldn't be completed. ***" << endl;
				}
				displayBoard();
			
	}
	else if (roworcol >=6 && command == 'D'){
			if (numOfSquares == 1){
    				flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance);   				
				}
		else if (numOfSquares == 2){
    				flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance); 
					flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance);   				
				}
		else if (numOfSquares == 3){
    				flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance);  
					flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance);
					flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance);  				
				}
		else if (numOfSquares >= 4){
    				flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance);
					flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance);
					flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance);
					flag = moveRightorDown(n1, n2, n3, n4, n5, n6, carSize, distance);   				
				}
				if (flag==1){
					cout << "*** Move was attempted, but couldn't be completed. ***" << endl;
				}
				displayBoard();
			
	}
	else {
		cout << "*** Move was attempted, but couldn't be completed. ***" << endl;
		displayBoard();		
	}
	
}//end handlePieces()
//--------------------------------------------------------------------
// Car Size, the length of the car.
int carSize(){
			  	int counter=0;
			  	
			  	if (p1==vehicle){
			  		counter = counter +1;
				  }
				if (p2==vehicle){
			  		counter = counter +1;
				  }
				if (p3==vehicle){
			  		counter = counter +1;
				  }
				if (p4==vehicle){
			  		counter = counter +1;
				  }
				if (p5==vehicle){
			  		counter = counter +1;
				  }
				if (p6==vehicle){
			  		counter = counter +1;
				  }
				if (p7==vehicle){
			  		counter = counter +1;
				  }
				if (p8==vehicle){
			  		counter = counter +1;
				  }
				if (p9==vehicle){
			  		counter = counter +1;
				  }
				if (p10==vehicle){
			  		counter = counter +1;
				  }
				if (p11==vehicle){
			  		counter = counter +1;
				  }
				if (p12==vehicle){
			  		counter = counter +1;
				  }
				if (p13==vehicle){
			  		counter = counter +1;
				  }
				if (p14==vehicle){
			  		counter = counter +1;
				  }
				if (p15==vehicle){
			  		counter = counter +1;
				  }
				if (p16==vehicle){
			  		counter = counter +1;
				  }
				if (p17==vehicle){
			  		counter = counter +1;
				  }
				if (p18==vehicle){
			  		counter = counter +1;
				  }
				if (p19==vehicle){
			  		counter = counter +1;
				  }
				if (p20==vehicle){
			  		counter = counter +1;
				  }
				if (p21==vehicle){
			  		counter = counter +1;
				  }
				if (p22==vehicle){
			  		counter = counter +1;
				  }
				if (p23==vehicle){
			  		counter = counter +1;
				  }
				if (p24==vehicle){
			  		counter = counter +1;
				  }
				if (p25==vehicle){
			  		counter = counter +1;
				  }
				if (p26==vehicle){
			  		counter = counter +1;
				  }
				if (p27==vehicle){
			  		counter = counter +1;
				  }
				if (p28==vehicle){
			  		counter = counter +1;
				  }
				if (p29==vehicle){
					counter = counter +1;
				}
			  	if (p30==vehicle){
			  		counter = counter +1;
				  }
				if (p31==vehicle){
			  		counter = counter +1;
				  }
				if (p32==vehicle){
			  		counter = counter +1;
				  }
				if (p33==vehicle){
			  		counter = counter +1;
				  }
				if (p34==vehicle){
			  		counter = counter +1;
				  }
				if (p35==vehicle){
			  		counter = counter +1;
				  }
				if (p36==vehicle){
			  		counter = counter +1;
				  }
				
			return counter;
				
			  
	
	
	
}//end carSize()
//--------------------------------------------------------------------
// Orientation Check, the Orientation of the car.

int orientationCheck(){
				int orientation = 0;
				
			  	
			  	if (p1==vehicle && p2==vehicle){
			  		orientation = 1;
				  }
				else if (p2==vehicle && p3==vehicle){
			  		orientation = 1;
				  }
				else if (p3==vehicle && p4==vehicle){
			  		orientation = 1;
				  }
				else if (p4==vehicle && p5==vehicle){
			  		orientation = 1;
				  }
				else if (p5==vehicle && p6==vehicle){
			  		orientation = 1;
				  }
				else if (p7==vehicle && p8==vehicle){
			  		orientation = 2;
				  }
				  else if (p8==vehicle && p9==vehicle){
			  		orientation = 2;
				  }
				else if (p9==vehicle && p10==vehicle){
			  		orientation = 2;
				  }
				else if (p10==vehicle && p11==vehicle){
			  		orientation = 2;
				  }
				else if (p11==vehicle && p12==vehicle){
			  		orientation = 2;
				  }
				else if (p13==vehicle && p14==vehicle){
			  		orientation = 3;
				  }
				  else if (p14==vehicle && p15==vehicle){
			  		orientation = 3;
				  }
				else if (p15==vehicle && p16==vehicle){
			  		orientation = 3;
				  }
				else if (p16==vehicle && p17==vehicle){
			  		orientation = 3;
				  }
				else if (p17==vehicle && p18==vehicle){
			  		orientation = 3;
				  }
				else if (p19==vehicle && p20==vehicle){
			  		orientation = 4;
				  }
				  else if (p20==vehicle && p21==vehicle){
			  		orientation = 4;
				  }
				else if (p21==vehicle && p22==vehicle){
			  		orientation = 4;
				  }
				else if (p22==vehicle && p23==vehicle){
			  		orientation = 4;
				  }
				else if (p23==vehicle && p24==vehicle){
			  		orientation = 4;
				  }
				else if (p25==vehicle && p26==vehicle){
			  		orientation = 5;
				  }
				  else if (p26==vehicle && p27==vehicle){
			  		orientation = 5;
				  }
				else if (p27==vehicle && p28==vehicle){
			  		orientation = 5;
				  }
				else if (p28==vehicle && p29==vehicle){
			  		orientation = 5;
				  }
				else if (p29==vehicle && p30==vehicle){
			  		orientation = 5;
				  }
				else if (p31==vehicle && p32==vehicle){
			  		orientation = 6;
				  }
				  else if (p32==vehicle && p33==vehicle){
			  		orientation = 6;
				  }
				else if (p33==vehicle && p34==vehicle){
			  		orientation = 6;
				  }
				else if (p34==vehicle && p35==vehicle){
			  		orientation = 6;
				  }
				else if (p35==vehicle && p36==vehicle){
			  		orientation = 6;
				  }
//------------------------------------------------------------------  
				else if (p1==vehicle && p7==vehicle){
			  		orientation = 7;
				  }
				else if (p7==vehicle && p13==vehicle){
			  		orientation = 7;
				  }
				else if (p13==vehicle && p19==vehicle){
			  		orientation = 7;
				  }
				else if (p19==vehicle && p25==vehicle){
			  		orientation = 7;
				  }
				else if (p25==vehicle && p31==vehicle){
			  		orientation = 7;
				  }
				else if (p2==vehicle && p8==vehicle){
			  		orientation = 8;
				  }
				  else if (p8==vehicle && p14==vehicle){
			  		orientation = 8;
				  }
				else if (p14==vehicle && p20==vehicle){
			  		orientation = 8;
				  }
				else if (p20==vehicle && p26==vehicle){
			  		orientation = 8;
				  }
				else if (p26==vehicle && p32==vehicle){
			  		orientation = 8;
				  }
				else if (p3=vehicle && p9==vehicle){
			  		orientation = 9;
				  }
				  else if (p9==vehicle && p15==vehicle){
			  		orientation = 9;
				  }
				else if (p15==vehicle && p21==vehicle){
			  		orientation = 9;
				  }
				else if (p21==vehicle && p27==vehicle){
			  		orientation = 9;
				  }
				else if (p27==vehicle && p33==vehicle){
			  		orientation = 9;
				  }
				else if (p4==vehicle && p10==vehicle){
			  		orientation = 10;
				  }
				  else if (p10==vehicle && p16==vehicle){
			  		orientation = 10;
				  }
				else if (p16==vehicle && p22==vehicle){
			  		orientation = 10;
				  }
				else if (p22==vehicle && p28==vehicle){
			  		orientation = 10;
				  }
				else if (p28==vehicle && p34==vehicle){
			  		orientation = 10;
				  }
				else if (p5==vehicle && p11==vehicle){
			  		orientation = 11;
				  }
				  else if (p11==vehicle && p17==vehicle){
			  		orientation = 11;
				  }
				else if (p17==vehicle && p23==vehicle){
			  		orientation = 11;
				  }
				else if (p23==vehicle && p29==vehicle){
			  		orientation = 11;
				  }
				else if (p29==vehicle && p35==vehicle){
			  		orientation = 11;
				  }
				else if (p6==vehicle && p12==vehicle){
			  		orientation = 12;
				  }
				  else if (p12==vehicle && p18==vehicle){
			  		orientation = 12;
				  }
				else if (p18==vehicle && p24==vehicle){
			  		orientation = 12;
				  }
				else if (p24==vehicle && p30==vehicle){
			  		orientation = 12;
				  }
				else if (p30==vehicle && p36==vehicle){
			  		orientation = 12;
			  		
				  }
			return orientation;
				
			  
	
	
	
}//end orientationCheck()
//--------------------------------------------------------------------

int main()
{

	int tempOrientation; // For storing the Row or Column
	int carLength;       // For storing the Car Length
	int numOfMoves=0;    // For storing the Num Of Moves
	char tempVar;        // Variable for Handling an error
	
    
    displayIDInfo();        // Display ID info
    displayInstructions();  // Display game instructions
    
    
    
    // Set the board values
     p1='G'; p2='G'; p3='.'; p4='.'; p5='.'; p6='Y';
     p7='P'; p8='.'; p9='.';p10='B';p11='.';p12='Y';
    p13='P';p14='R';p15='R';p16='B';p17='.';p18='Y';
    p19='P';p20='.';p21='.';p22='B';p23='.';p24='.';
    p25='O';p26='.';p27='.';p28='.';p29='T';p30='T';
    p31='O';p32='.';p33='F';p34='F';p35='F';p36='.';
    
    // Display the initial board
    displayBoard();   // Invoking function for Displaying the Board with Initial Values
    
    
    
    // Loop Syntax for 'n' number of moves
    while (vehicle !='X'){  
    	
    	numOfMoves = numOfMoves +1; // Variable for keeping track of Number of Moves
    	cout << numOfMoves << ". "<<"Your Move -> ";
    	cin >> vehicle; // Taking User Input for Vehicle
    	vehicle = toupper(vehicle); // Changing input to UpperCase
    	
    	if (vehicle == 'X'){ // Condition for Exit
   			break;
    	}
    	
    	if (vehicle == '-'){ // Condition for Reset
    		numOfMoves=0;
    		ResetTheBoard(); // Invoking function for Resetting the Board
   			displayBoard();  // Invoking function for Displaying the Board
   			continue;
    	}
    	
    	
		cin >> direction; // Taking User Input for Direction
    	cin >> numOfSquares; // Taking User Input for Num Of Squares
        	     
    	direction = toupper(direction); // Changing input to UpperCase
		tempVar = p3; // Handling an Error    	   	
    	
		carLength = carSize(); // Invoking function for Car Length
    	tempOrientation = orientationCheck(); // Invoking function for Orientation of the Car.
    	
    	
    	
    	if (p18!= 'R'){
    	
    		if (tempOrientation <=6){ // Condition for Rows
    			if (tempOrientation == 1){ // Condition for Row 1
   					handlePieces(p1, p2, p3, p4, p5, p6, carLength, numOfSquares, direction, tempOrientation);	
				}
				else if (tempOrientation == 2){ // Condition for Row 2
					handlePieces(p7, p8, p9, p10, p11, p12, carLength, numOfSquares, direction, tempOrientation);
				}
				else if (tempOrientation == 3){ // Condition for Row 3
					handlePieces(p13, p14, p15, p16, p17, p18, carLength, numOfSquares, direction, tempOrientation);    			
				}
				else if (tempOrientation == 4){ // Condition for Row 4
					handlePieces(p19, p20, p21, p22, p23, p24, carLength, numOfSquares, direction, tempOrientation);
    			
				}
				else if (tempOrientation == 5){ // Condition for Row 5
					handlePieces(p25, p26, p27, p28, p29, p30, carLength, numOfSquares, direction, tempOrientation);
    			
				}
				else if (tempOrientation == 6){ // Condition for Row 6
					handlePieces(p31, p32, p33, p34, p35, p36, carLength, numOfSquares, direction, tempOrientation);
    			
				}
					
					
			}
			else if (tempOrientation >6){ // Condition for Columns
				p3 = tempVar; // Handling an Error
		
				if (tempOrientation == 7){ // Condition for Column 1
    				handlePieces(p1, p7, p13, p19, p25, p31, carLength, numOfSquares, direction, tempOrientation);	
				}
				else if (tempOrientation == 8){ // Condition for Column 2
					handlePieces(p2, p8, p14, p20, p26, p32, carLength, numOfSquares, direction, tempOrientation);
    				
				}
				else if (tempOrientation == 9){ // Condition for Column 3
					handlePieces(p3, p9, p15, p21, p27, p33, carLength, numOfSquares, direction, tempOrientation); 
					   			
				}
				else if (tempOrientation == 10){ // Condition for Column 4
					handlePieces(p4, p10, p16, p22, p28, p34, carLength, numOfSquares, direction, tempOrientation);
    			
				}
				else if (tempOrientation == 11){ // Condition for Column 5
					handlePieces(p5, p11, p17, p23, p29, p35, carLength, numOfSquares, direction, tempOrientation);
    			
				}
				else if (tempOrientation == 12){ // Condition for Column 6
					handlePieces(p6, p12, p18, p24, p30, p36, carLength, numOfSquares, direction, tempOrientation);
    					
				}
				
			}
    
    	
   		}
   		if (p18 == 'R'){ // Condition for Winning
    		cout << "*** Congratulations, you did it! ***" << endl;
   			break;
   			    		
    	}
   		
   		

   	}
   	
   
    cout << endl;
    cout << "Thank you for playing.  Exiting..." << endl;
    
    return 0;
}//end main()



