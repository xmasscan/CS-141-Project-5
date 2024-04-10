#ifndef BOARD_PIECE_H
#define BOARD_PIECE_H
class GamePiece
{
	private:
		char color;
		int size;
	public:
		void setColor(char newColor);
		void setSize(int newSize);
		char getColor();
		int getSize();
		
		GamePiece();
		GamePiece(char newColor, int newSize);
};
class Board
{
	private:
		GamePiece board[3][3];
	public:
		char getState();
		void addPiece(char newColor, int size, int cell);
		void getBoard();
		Board();
};

#endif
