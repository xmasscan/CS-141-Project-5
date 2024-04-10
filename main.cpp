#include "Board.cpp"
#include <iostream> // cin for user input
// Board.cpp includes <string>

int main()
{
	// Initializes Empty Game Board
	Board myBoard = Board();

	// Defines the colors the players are represented by. Edit to change colors :)
	char playerOne = 'y';
	char playerTwo = 'r';

	// Determines the amount of pieces of each size both players get.
	// Formatted as such: Large, Medium, Small
	// 	( Just like they appear in the menu. )
	int p1Pieces[3] = {2, 2, 2};
	int p2Pieces[3] = {2, 2, 2};

	// Every turn, each user is prompted to either select a char option and an int option, or just a char option ('q' to quit).
	char charChoice = ' ';
	int intChoice;
	
	// Will automatically terminate the game if the user quits the game. Additionally serves to provide a condition which allows us to terminate the game when it is won or tied.
	while(charChoice != 'q')
	{
	}

	myBoard.getBoard();
	return 0;
}
