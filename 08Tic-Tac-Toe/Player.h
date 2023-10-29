#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

//An abstract superclass for the classes that decide which move to make in a Tic Tac Toe game.
class Player
{
public:
	Player();    //Default Constructor
	Player(char symbol);    //Constructor
	Player(const Player& original);    //Copy Constructor
	virtual ~Player();    //Destructor

	Player& operator= (const Player& original);
	char getSymbol() const;
	void setSymbol(char symbol);
	virtual unsigned int getMove() const = 0;

private:
	char m_symbol;
};

#endif
