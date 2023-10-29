///////////////////////////////////////////////
//File: TicTacToe.h
//Sub-functions of this program
//Play the game of tic-tac-toe with two players
//Student name: 
//Student number: 
//Date: November 20, 2017
////////////////////////////////////////////////

#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
	player = 0;
	ifWin = false;

	//set the empty board
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			chessboard[i][j] = 0;
		}
	}
}

//to print the board
void TicTacToe::printBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << chessboard[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//to switch players
void TicTacToe::changePlayer()
{
	if (player == 1)
	{
		player = 2;
	}
	else
	{
		player = 1;
	}
}

//ask user to input the place
void TicTacToe::input()
{
	int i, j;
	cout << "Player" << player << " move: ";
	cin >> i >> j;

	while ((i > 3 || j > 3 || i < 1 || j < 1) || (chessboard[i - 1][j - 1] != 0))
	{
		//check input is valid
		if (i > 3 || j > 3 || i < 1 || j < 1)
		{
			cout << i << " " << j << " is not valid. " << "Please choose another move: ";
			cin >> i >> j;
		}

		//check the input not be used
		else if (chessboard[i - 1][j - 1] != 0)
		{
			cout << i << " " << j << " is used. " << "Please choose another move: ";
			cin >> i >> j;
		}
	}

	chessboard[i - 1][j - 1] = player;
}

//to check if win or not
void TicTacToe::check()
{
	ifWin = false;

	for (int i = 0; i < 3; i++)
	{
		//same row
		if (chessboard[i][0] == chessboard[i][1] && chessboard[i][1] == chessboard[i][2] && chessboard[i][0] != 0)
			ifWin = true;
		//same column
		else if (chessboard[0][i] == chessboard[1][i] && chessboard[1][i] == chessboard[2][i] && chessboard[0][i] != 0)
			ifWin = true;
	}

	//cross
	if (chessboard[0][0] == chessboard[1][1] && chessboard[1][1] == chessboard[2][2] && chessboard[0][0] != 0)
		ifWin = true;
	else if (chessboard[0][2] == chessboard[1][1] && chessboard[1][1] == chessboard[2][0] && chessboard[0][2] != 0)
		ifWin = true;

}

//get the finial result
void TicTacToe::win()
{
	if (ifWin == true)
		cout << "Player" << player << " wins.";
	else
		cout << "The game is a draw.";
}

