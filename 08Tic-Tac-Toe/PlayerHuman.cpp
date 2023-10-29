#include"PlayerHuman.h"
#include <iostream>
using namespace std;

//To create a new PlayerHuman with default values.
PlayerHuman::PlayerHuman()
{
	setSymbol(' ');
}

//To create a new PlayerHuman that places the specified symbol on the game board.
PlayerHuman::PlayerHuman(char symbol)
{
	setSymbol(symbol);
}

//To create a new PlayerHuman as a copy of another.
PlayerHuman::PlayerHuman(const PlayerHuman& original)
{
	setSymbol(original.getSymbol());
}

//To safely destroy a PlayerHuman without memory leaks.
PlayerHuman::~PlayerHuman()
{
	//
}

//To modify this PlayerHuman to be a copy of another.
PlayerHuman& PlayerHuman::operator= (const PlayerHuman& original)
{
	setSymbol(original.getSymbol());
	return *this;
}

//To determine the next move for this Player on the specified board.
unsigned int PlayerHuman::getMove() const
{
	int pos;
	cout << "Please choose a position to place the symbol: ";
	cin >> pos;
	
	return pos;
}