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

    // flag which informs the program of the legality of a move
    bool isLegal;

    // Will automatically terminate the game if the user quits the game. Additionally serves to provide a condition which allows us to terminate the game when it is won or tied.
    while(charChoice != 'q')
    {
	// Assumes input is legal for each player until proved otherwise.
	isLegal = true;
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
	printf("%s %c %c %s %d %s \n", "a. ", toupper(currentPlayer), toupper(currentPlayer), " ", (*currentPieces)[0], " remain.");
	// Example: b. Y  2 remain.
	printf("%s %c %s %d %s \n", "b. ", toupper(currentPlayer), "   ", (*currentPieces)[1], " remain.");
	// Example: c. y  2 remain.
	printf("%s %c %s %d %s \n", "c. ", currentPlayer, "   ", (*currentPieces)[2], " remain.");
	// q to exit.
	printf("%s \n", "q to exit.");
        printf("\n");
	
	/* INPUT PROCESSING */
        /*
         * If a move is legal, that is it doesn't satisfy any of the following checks, the 'isLegal' flag isn't flipped.
         * If a move is illegal, the user is prompted to provide a legal input until they supply the program with one.
         * Checks the following conditions:
         *      - charChoice is not one of the following (a,b,c)
         *      - intChoice is less than one or greater than 9
         *      - the player is out of their chosen size
         *      - the current selected size cannot be placed upon what is on the board
         *              - i.e. piece is smaller or just as big as the piece currently on the board.
         */

        // Skip parsing if the user has chosen to quit the program.
        do
        {

	// Initially assumes each input to be legal before proven otherwise so that each input may be individually judged.
	isLegal = true;

	// Prompt User for Input here so that they can be prompted over and over again if needed.

	// Prints: "It is <color>'s turn."
        printf("It is ");
        
        /* NOTE: IF YOU USE CUSTOM COLORS, YOU CAN MODIFY THIS SECTION TO CHANGE THE COLORS OUTPUT!*/
        if(currentPlayer == 'y')
            printf("yellow");
        else if(currentPlayer == 'r')
            printf("red");
        printf("'s turn.\n");

        printf("Choose action and location, for example a2: ");
        
        std::cin >> charChoice;
        // if the user wishes to quit, they do not need to supply an integer input.
        if(charChoice != 'q')
            std::cin >> intChoice;

        // The 'isLegal &&' allows the program to short circuit to the failure prompt as soon as one is detected, as well as allowing us as programmers to assume that none of the conditions above the current one have been violated if it runs. :)
            // Checks if charChoice is a legal character.
            if(isLegal && (charChoice > 'c' || charChoice < 'a'))
                isLegal = false;
            // Checks if intChoice is a legal value.
            if(isLegal && (intChoice < 1 || intChoice > 9))
                isLegal = false;
            // Checks if user has enough pieces to place onto the board.
            if(isLegal)
            {
                switch(charChoice)
                {
                    case 'a':
                        if(*currentPieces[0] == 0)
                        isLegal = false;
                        break;
                    case 'b':
                        if(*currentPieces[1] == 0)
                        isLegal = false;
                        break;
                    case 'c':
                        if(*currentPieces[2] == 0)
                        isLegal = false;
                        break;
                }
            }
	    // Checks if the piece being placed on the board is a legal size
            if(isLegal)
            {
		switch(charChoice)
		{
		case 'a':
			if(myBoard.getCell(intChoice).getSize() == 2)
				isLegal = false;
			break;
		case 'b':
			if(myBoard.getCell(intChoice).getSize() >= 1)
				isLegal = false;
			break;
		case 'c':
			if(myBoard.getCell(intChoice).getSize()  >= 0)
				isLegal = false;
			break;
		}
            }
	// if the user asked to terminate the program, do not force them to input a legal value.
	if(charChoice == 'q')
		isLegal = true;

	if(not(isLegal))
	 printf("Invalid move. Try again. \n");
	

} while(not(isLegal));

        /* WRITING TO BOARD */
	if(charChoice != 'q')
        {
            // Switch statement that changes the given size input based on the user's earlier input.
            // A. Large
            // B. Medium
            // C. Small
            // color size cell            
            switch(charChoice)
            {
		    // Anatomy of a each case:
		    // 1. Add GamePiece object to Board
		    // 2. Decrement amount of pieces of given size.
                case 'a':
                    myBoard.addPiece(currentPlayer, 2, intChoice);
	            (*currentPieces)[0]--;	
                    break;
                case 'b':
                    myBoard.addPiece(currentPlayer, 1, intChoice);
                    (*currentPieces)[1] -= 1;
                    break;
                case 'c':
                    myBoard.addPiece(currentPlayer, 0, intChoice);
                    (*currentPieces)[2] -= 1;
                    break;
            }
        }
    // After the newest piece has been added, the 'state' of the board is checked
    // i.e. we check if we have a winner yet
    if(myBoard.getState() != ' ')
    {
        if(myBoard.getState() == 'y')
        {
            printf("Yellow wins!");
        }
        else if(myBoard.getState() == 'r')
        {
            printf("Red wins!");
        }
        // Terminates the program upon win.
        charChoice = 'q';
    }
    // If there is no winner, we check if there is a tie before looping once more.
    // A tie will, of course, only occur if someone does not win and there are no more moves to be made.
    // That is, there are no possible moves left to make, which will only occur when all the pieces are used up but there is no winner.
    else
    {
        // "If player one has no pieces left..."
       if(p1Pieces[0] == 0 && p1Pieces[1] == 0 && p1Pieces[2] == 0)
       {
           // "... and so does player two..."
           if(p2Pieces[0] == 0 && p2Pieces[1] == 0 && p2Pieces[2] == 0)
           {
               // "... there must be a tie!"
               printf("Tie game.");
               // terminate
               charChoice = 'q';
           }
       }
    }
	}
	return 0;
}
