#include "Board.cpp"

int main()
{
	Board myBoard = Board();
	myBoard.addPiece('r', 2, 3);
	myBoard.getBoard();
	return 0;
}
