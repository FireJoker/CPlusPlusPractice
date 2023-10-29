




//check 
void Board::check()
{
	ifWin = false;

	for (int i = 0; i < 3; i++)
	{
		//same row
		if (board[i] == board[i+SIZE] && board[i + SIZE] == board[i + 2 * SIZE] && board[i] != ' ')
			ifWin = true;
		//same col
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			ifWin = true;
	}

	//cross
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		ifWin = true;
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
		ifWin = true;

}

void Board::print() const
{
	for (int i = 0; i < 3; i++)
	{
		cout << "+---+---+---+" << endl;
		cout << "| ";
		for (int j = 0; j < 3; j++)
		{
		cout << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " |" << endl;
		}
	}
	cout << "+---+---+---+" << endl;
}

int Board::getGameState() const
{
	if (ifWin == true)
		cout << "Player" << " wins.";
	else
		cout << "The game is a draw.";
}

