#include "Board.h"
#include "PlayerHuman.h"
#include "PlayerRandom.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	Board board;
	Player *player1 = new PlayerHuman;
	Player *player2 = new PlayerHuman;
	Player *computer = new PlayerRandom;

	int playWith;
	int position;
	int state;
	int turn = 1;

	cout << "Welcome to the Tic-Tac-Toe game " << endl;
	cout << "Would you like to play with 1)Human 2)Computer 3)Exit ";
	cin >> playWith;    //choose play with human or computer

	do
	{
		if (playWith == 1)    //play with human
		{
			cout << "Player1 is 'X', Player2 is 'O'." << endl;
			break;
		}
		else if (playWith == 2)    //play with computer
		{
			cout << "Player is 'X', Computer is 'O'." << endl;
			break;
		}
		else if (playWith == 3)    //Exit
		{
			exit(1);
		}
		else    //invild imput
		{
			cout << "Invild imput, please try again. ";
			cin >> playWith;
		}
	} while (true);

	cout << "The board shows below:" << endl;
	cout << "+---+---+---+" << endl;
	cout << "| 1 | 2 | 3 |" << endl;
	cout << "+---+---+---+" << endl;
	cout << "| 4 | 5 | 6 |" << endl;
	cout << "+---+---+---+" << endl;
	cout << "| 7 | 8 | 9 |" << endl;
	cout << "+---+---+---+" << endl;

	if (playWith == 1)
	{
		player1->setSymbol('X');		//set symbol of player1
		player2->setSymbol('O');		//set symbol of player2

		do
		{
			//player1 moves
			if (turn == 1 || turn == 3 || turn == 5 || turn == 7 || turn == 9)
			{
				//check moves
				do
				{
					position = player1->getMove();
				} while (!board.isValidPosition(position - 1));

				board.setCellSymbol(position - 1, player1->getSymbol());    //set symbol in the position
				board.print();

				state = board.getGameState(turn);    //get game states
				if (state == 1)
				{
					cout << "Congratulations! X wins." << endl;
					break;
				}
				else if (state == 2)
				{
					cout << "Congratulations! O wins." << endl;
					break;
				}
				else if (state == 3)
				{
					cout << "The game ended in a tie." << endl;
					break;
				}
				turn++;
			}

			//player2 moves
			else if (turn == 2 || turn == 4 || turn == 6 || turn == 8)
			{
				//check moves
				do
				{
					position = player2->getMove();
				} while (!board.isValidPosition(position - 1));

				board.setCellSymbol(position - 1, player2->getSymbol());    //set symbol in the position
				board.print();

				state = board.getGameState(turn);    //get game states
				if (state == 1)
				{
					cout << "Congratulations! X wins." << endl;
					break;
				}
				else if (state == 2)
				{
					cout << "Congratulations! O wins." << endl;
					break;
				}
				else if (state == 3)
				{
					cout << "The game ended in a tie." << endl;
					break;
				}
				turn++;
			}
		} while (true);
	}

	else if (playWith == 2)
	{
		player1->setSymbol('X');		//set symbol of player1
		computer->setSymbol('O');		//set symbol of computer

		do
		{
			//player1 moves
			if (turn == 1 || turn == 3 || turn == 5 || turn == 7 || turn == 9)
			{
				//check moves
				do
				{
					position = player1->getMove();
				} while (!board.isValidPosition(position - 1));

				board.setCellSymbol(position - 1, player1->getSymbol());    //set symbol in the position
				board.print();

				state = board.getGameState(turn);    //get game states
				if (state == 1)
				{
					cout << "Congratulations! X wins." << endl;
					break;
				}
				else if (state == 2)
				{
					cout << "Congratulations! O wins." << endl;
					break;
				}
				else if (state == 3)
				{
					cout << "The game ended in a tie." << endl;
					break;
				}
				turn++;
			}

			//computer moves
			else if (turn == 2 || turn == 4 || turn == 6 || turn == 8)
			{
				//check moves
				do
				{
					position = computer->getMove();
				} while (!board.isValidPosition(position - 1));

				board.setCellSymbol(position - 1, computer->getSymbol());    //set symbol in the position
				board.print();

				state = board.getGameState(turn);    //get game states
				if (state == 1)
				{
					cout << "Congratulations! X wins." << endl;
					break;
				}
				else if (state == 2)
				{
					cout << "Congratulations! O wins." << endl;
					break;
				}
				else if (state == 3)
				{
					cout << "The game ended in a tie." << endl;
					break;
				}
				turn++;
			}
		} while (true);

	}

	delete player1, player2, computer;
	system("pause");
	return 0;
}