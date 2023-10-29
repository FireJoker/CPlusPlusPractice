#include"PlayerRandom.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//To create a new PlayerRandom with default values.
PlayerRandom::PlayerRandom()
{
	setSymbol(' ');
}

//To create a new PlayerRandom that places the specified symbol on the game board.
PlayerRandom::PlayerRandom(char symbol)
{
	setSymbol(symbol);
}

//To create a new PlayerRandom as a copy of another.
PlayerRandom::PlayerRandom(const PlayerRandom& original)
{
	setSymbol(original.getSymbol());
}

//To safely destroy a PlayerRandom without memory leaks.
PlayerRandom::~PlayerRandom()
{
	//
}

//To modify this PlayerRandom to be a copy of another.
PlayerRandom& PlayerRandom::operator= (const PlayerRandom& original)
{
	setSymbol(original.getSymbol());
	return *this;
}

//To determine the next move for this Player on the specified board.
unsigned int PlayerRandom::getMove() const
{
	int pos;

	srand(unsigned int (time(NULL)));
	pos = rand() % 9;

	return pos;
}