#include "Player.h"
#include <iostream>
using namespace std;

//To create a new Player with default values.
Player::Player()
{
	m_symbol = ' ';
}

//To create a new Player that places the specified symbol on the game board.
Player::Player(char symbol)
{
	m_symbol = symbol;
}

//To create a new Player as a copy of another.
Player::Player(const Player& original)
{
	m_symbol = original.m_symbol;
}

//To safely destroy a Player without memory leaks.
Player::~Player()
{
	//
}

//To modify this Player to be a copy of another.
Player& Player::operator= (const Player& original)
{
	m_symbol = original.m_symbol;
	return *this;
}

//To determine the symbol placed by this Player.
char Player::getSymbol() const
{
	return m_symbol;
}

//To change the symbol placed by this Player.
void Player::setSymbol(char symbol)
{
	m_symbol = symbol;
}
