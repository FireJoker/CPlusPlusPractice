///////////////////////////////////////////////
//File: TicTacToe.h
//Main function of this program
//Play the game of tic-tac-toe with two players
//Student name: 
//Student number:
//Date: November 20, 2017
////////////////////////////////////////////////

#include "TicTacToe.h"

int main()
{
	int i = 1;
	TicTacToe obj;

	obj.printBoard();

	while (!(obj.getResult()) && (i <= 9))
	{
		obj.changePlayer();
		obj.input();
		obj.printBoard();
		obj.check();
		i++;
	}
	obj.win();
	return 0;
}
