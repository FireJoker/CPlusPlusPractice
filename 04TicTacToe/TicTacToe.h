///////////////////////////////////////////////
//File: TicTacToe.h
//Creat a class called TicTacToe
//Play the game of tic-tac-toe with two players
//Student name: 
//Student number: 
//Date: November 20, 2017
////////////////////////////////////////////////

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
using namespace std;

class TicTacToe
{
public:
	TicTacToe();
	void printBoard();
	void changePlayer();
	void input();
	void check();
	void win();
	bool getResult() { return ifWin; };

private:
	int player;
	bool ifWin;
	int chessboard[3][3];

};

#endif
