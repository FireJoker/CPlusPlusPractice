#ifndef BOARD_H
#define BOARD_H

//The number of rows and columns in this Board.
static const int SIZE = 3;

//The number cells in this Board.
static const int CELL_COUNT = SIZE * SIZE;


//A class to represent the game board in a Tic Tac Toe game and print it.
//Query and set the symbols in the cells of a Board.
//Determine the current game state: which player, if any, has won.
class Board
{
public:
	Board();    //Default Constructor
	Board(const Board& original);    //Copy Constructor
	~Board();    //Destructor

	Board& operator= (const Board& original);
	
	bool isValidPosition(const unsigned int& position) const;
	int toPosition(unsigned int& position) const;
	int getPosition (const unsigned int& position) const;

	void setCellSymbol(const unsigned int& position, char symbol);
	char getCellSymbol(const unsigned int& position) const;

	int getGameState(unsigned int turn) const;
	void print() const;

private:
	char board[CELL_COUNT];

};

#endif