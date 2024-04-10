#include <string>
#include "Board.h"

/*
 * GamePiece Class Definition
 *
 * A GamePiece object represents a given piece on the board, represented by a Board object.
 * By default, a GamePiece object has no noticable traits, that is:
 * 	its size is equal to -1
 * 	its color is equal to ' '
 *
 * There are two game piece colors we will recognize for this program - Yellow and Red
 * 	Yellow is represented by the char 'y'
 * 	Red is represented by the char 'r'
 * There are three GamePiece sizes: Small, Medium, Large
 * 	Each of these sizes are represented by an integer value as such:
 * 		Small : 0
 * 		Medium : 1
 * 		Large : 2
 */

// Mutators
void GamePiece::setColor(char newColor)
{	
	if(newColor == 'y' || newColor == 'r')
		this->color = newColor;
}
void GamePiece::setSize(int newSize)
{ 
	if(newSize >= 0 && newSize <= 2)
		this->size = newSize;
}
// Accessors
char GamePiece::getColor() { return this->color; }
int GamePiece::getSize() { return this->size; }
// Constructors
// Default Constuctor
GamePiece::GamePiece()
	{
		this->color = ' ';
		this->size = -1;
	}
// Qualified Constructor
GamePiece::GamePiece(char newColor, int newSize)
{
	if(newColor == 'y' || newColor == 'r')
		this->color = newColor;
	if(newSize >= 0 && newSize <= 2)
		this->size = newSize;
}

// Constructor
Board::Board()
{
	GamePiece board[3][3];
}
		
// Checks the board between turns to determine if there is a winner.
// If there is, it returns the char value representing the piece's color, otherwise returns a space char (' ') and is ignored.
char Board::getState()
{
	bool vertMatch;
	/*
	* Run Check to see if any player has won.
	* First: Diagonals
	* Second: Horizontals
	* Last: Verticals
	*/
	
	// !Diagonals!
	/*
	 * x
	 *   x
	 *     x
	 */
	// Using board[0] as our reference point for both matches because I think of this diagonal as going down right in my head.
	// placeholder piece check
	if(board[0][0].getColor() != ' ')
	{
		if(board[0][0].getColor() == board[0][4].getColor() && board[0][0].getColor() == board[0][8].getColor())
			return board[0][0].getColor();
	}
	// If this first Diagonal isn't a match, check this one:
	/*
	 *     x
	 *   x
	 * x
	 */
	// board[6] chosen simply because I imagine this diagonal being a line going up right in my head.

	// Checks for placeholder/empty piece first :)
	if(board[0][6].getColor() != ' ')
	{
		if(board[0][6].getColor() == board[0][2].getColor() && board[0][6].getColor() == board[0][4].getColor())
			return board[0][6].getColor();
	}
	// At this point, if the function hasn't returned anything, its clear that there is no Diagonal match.
	// Now, I will check for horizontal matches. These come earlier because they are easier to think about in my head :)
			
	// !Horizontal Check!

	// There are 9 elements/cells in the board array.
	// It is broken down into 3 cells of length three.
	// The indicies of the leftmost cell of each array within the large array are 0, 3, and 6.
	// If we know that the leftmost cell's color is equivalent to the middle and rightmost cells' colors, then we know that the entire row must be the same color.
	for(int i = 0; i < 9; i += 3)
	{	
		// Check only valid when there is an actual piece on the board, not just an empty placeholder piece. 		
		if(board[0][i].getColor() != ' ')
		{
			if(board[0][i].getColor() == board[0][i + 1].getColor() && board[0][i].getColor() == board[0][i + 2].getColor())
				return board[0][i].getColor();
		}
	}
	// !Vertical Check!
			
	// Same principles applied in the horizontal check also work here.
	// This time, though, we care about the topmost indicies first, which are 0, 1, and 2.
	// The cell directly under element 0 has an index of 3, and the index of the cell under it is 6.
	// For 1, these indicies are 4 and 7.
	// For 2, they are 5 and 8.
	// As I'm sure you've noticed, they are all 3 apart. 
			
	// Loops through each "head" item.
	for(int i = 0; i < 3; ++i)
	{
		// Assumes there is vertical match before we check, only updated if proven false.
		vertMatch = true;
		// Loops through all indicies below the head

		// We only care about color matches as long as the color was determined by a player.
		if(board[0][i].getColor() != ' ')
		{
			for(int j = i; j < i + 7; j += 3)
			{
				// Checks if there is no match.
				if(board[0][j].getColor() != board[0][i].getColor())
					vertMatch = false;
			}
			// If a match's validity isn't disproven (i.e. there IS a vertical match), return the color of the winner.
			if(vertMatch)
				return board[0][i].getColor();
			}
		}

		// If no match has been found, then there is no success.
		// Returns a space.
	return ' ';
}
void Board::addPiece(char color, int size, int cell)
{
	board[0][cell - 1] = GamePiece(color, size); 
}
void Board::getBoard()
{
	std::string currentCell;
	// Prints out the board for each turn
	// Loops for every row
	for(int i = 0; i <= 2; ++i)
	{
		// Loops through every column in a row, i.e. each cell.
		for(int j = 0; j <= 2; ++j)
		{
			// (3 * i) + j provides the current cell on the board we are on.
			switch(board[0][(3 * i) + j].getSize())
			{
				case -1:
					printf("%c%d", ' ', (3 * i) + j + 1);
					break;
				case 0:
					printf("%c%d", board[0][(3 * i) + j].getColor(), (3 * i) + j + 1);
					break;
				case 1:
					printf("%c%d", toupper(board[0][(3 * i) + j].getColor()), (3 * i) + j + 1);
					break;
				case 2:
					printf("%c%c", toupper(board[0][(3 * i) + j].getColor()), toupper(board[0][(3 * i) + j].getColor()));
					break;
			}
			// outputs the pipes between cells correctly :)
			if(j < 2)
			{
				printf("%c", '|');
			}
		}
		// Newline Between Rows
		printf("%c", '\n');
		// outputs bars seperating rows
		if(i < 2)
		{
			printf("%s%c", "--------",'\n');
		}
	}
}
