#include "Board.cpp"
#include <iostream> // cin for user input
// Board.cpp includes <string>

int main()
{
    // If true, it is playerOne's turn, otherwise it is playerTwo's turn.
    // Alternates ad infinitum
    bool playerTurn = true;
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

    // Stores the current player for any given round.
    char currentPlayer;
    int (*currentPieces)[3];
    // Every turn, each user is prompted to either select a char option and an int option, or just a char option ('q' to quit).
    char charChoice = ' ';
    int intChoice;
	
    // Will automatically terminate the game if the user quits the game. Additionally serves to provide a condition which allows us to terminate the game when it is won or tied.
    while(charChoice != 'q')
    {
        myBoard.getBoard();
        printf("\n");
        // Alternates the current player between player one and two.
        if(playerTurn)
        {
            currentPlayer = playerOne;
	    currentPieces = &p1Pieces;
	    playerTurn = false;
	}
    	else
	{
	    currentPlayer = playerTwo;
	    currentPieces = &p2Pieces;
	    playerTurn = true;
	}
	// Example: a. YY 2 remain.
	printf("%s %c %c %s %d %s \n", "a. ", toupper(currentPlayer), toupper(currentPlayer), "  ", (*currentPieces)[0], " remain.");
	// Example: b. Y  2 remain.
	printf("%s %c %s %d %s \n", "b. ", toupper(currentPlayer), "   ", (*currentPieces)[1], " remain.");
	// Example: c. y  2 remain.
	printf("%s %c %s %d %s \n", "c. ", currentPlayer, "   ", (*currentPieces)[2], " remain.");
	// q to exit.
	printf("%s \n", "q to exit.");
        std::cin >> charChoice;
    }

    return 0;
}
