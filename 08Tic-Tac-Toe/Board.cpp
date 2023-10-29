#include "Board.h"
#include <iostream>
using namespace std;

//To create a new, empty Board.
Board::Board()
{
	for (int i = 0; i < CELL_COUNT; i++)
		board[i] = ' ';
}

//To create a new Board with the same symbols marked on it as another Board.
Board::Board(const Board& original)
{
	for (int i = 0; i < CELL_COUNT; i++)
		board[i] = original.board[i];
}

//To safely deallocate this Board without memory leaks.
Board::~Board()
{
	//
}

//To modify this Board to have the same symbols marked on it as another Board.
Board& Board::operator= (const Board& original)
{
	Board temp;
	temp = original;
	return temp;
}

//To determine if the specified Position is valid for this board.
bool Board::isValidPosition(const unsigned int& position) const
{
	if (position > 8 || position < 0 || getCellSymbol(position) != ' ')
	{
		cout << "Invilid position." << endl;
		return false;
	}

	else
		return true;
}

//To convert the position.
int Board::toPosition(unsigned int& position) const
{
	return position;
}

//To determine the Position refers to.
int Board::getPosition(const unsigned int& position) const
{
	return position;
}

//To change the symbol in the cell at the specified position.
void Board::setCellSymbol(const unsigned int& position, char symbol)
{
	board[position] = symbol;
}

//To determine the symbol in the cell at the specified position.
char Board::getCellSymbol(const unsigned int& position) const
{
	return board[position];
}

//To determine the winner of the game.
int Board::getGameState(unsigned int turn) const
{
	//return win
	for (int i = 0; i < SIZE; i++)
	{
		//same row
		if (board[i * SIZE] == board[i * SIZE + 1] && board[i * SIZE + 1] == board[i * SIZE + 2] && board[i * SIZE] != ' ')
		{
			if (board[i] == 'X')
				return 1;
			else if (board[i] == 'O')
				return 2;
		}
			
		//same col
		else if (board[i] == board[i + SIZE] && board[i + SIZE] == board[i + SIZE * 2] && board[i] != ' ')
		{
			if (board[i] == 'X')
				return 1;
			else if (board[i] == 'O')
				return 2;
		}
	}

	//cross
	if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
	{
		if (board[4] == 'X')
			return 1;
		else if (board[4] == 'O')
			return 2;
	}
	else if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
	{
		if (board[4] == 'X')
			return 1;
		else if (board[4] == 'O')
			return 2;
	}


	if (turn >= 9)    //game tie
		return 3;
	else
		return 4;    //not finish
}

//To print this Boiard to standard output.
void Board::print() const
{
	cout << "+---+---+---+" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "| ";
		for (int j = 0; j < SIZE; j++)
		{
			cout << board[i * SIZE + j] << " | ";
		}
		cout << endl;
		cout << "+---+---+---+" << endl;
	}
}