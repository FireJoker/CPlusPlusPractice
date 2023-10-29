#ifndef PLAYER_HUMAN_H
#define PLAYER_HUMAN_H

#include "Player.h"

//A Player that asks the user for moves.
class PlayerHuman : public Player
{
public:
	PlayerHuman();    //Default Constructor
	PlayerHuman(char symbol);    //Constructor
	PlayerHuman(const PlayerHuman& original);    //Copy Constructor
	virtual ~PlayerHuman();    //Destructor

	PlayerHuman& operator= (const PlayerHuman& original);
	virtual unsigned int getMove() const;
};

#endif

