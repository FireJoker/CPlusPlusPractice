#ifndef PLAYER_RANDOM_H
#define PLAYER_RANDOM_H

#include "Player.h"

//A Player that asks the computer for moves.
class PlayerRandom : public Player
{
public:
	PlayerRandom();    //Default Constructor
	PlayerRandom(char symbol);    //Constructor
	PlayerRandom(const PlayerRandom& original);    //Copy Constructor
	virtual ~PlayerRandom();    //Destructor

	PlayerRandom& operator= (const PlayerRandom& original);
	virtual unsigned int getMove() const;
};

#endif

