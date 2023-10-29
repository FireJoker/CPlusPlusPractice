///////////////////////////////////////
//File: Puzzle.cpp
//Creat an AI to solve puzzle game
//Student name: 
//Student number:
//Date: December 9, 2017
///////////////////////////////////////

#include "Puzzle.h"

bool Matrix::operator==(const Matrix& cur)
{
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
		{
			if (puzzle[i][j] != cur.puzzle[i][j])
			{
				return false;
			}
		}
	return true;
}

ListStack::ListStack()
{
	top = NULL;
	tail = NULL;
}

//creat a node
void ListStack::push(Matrix element)
{
	if (top == NULL)
	{
		top = new Node;
		top->data = element;
		top->dir = 0;
		top->next = NULL;
		tail = top;
	}
	else
	{
		Node *temp = new Node;
		temp->data = element;
		temp->dir = 0;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
}

//delete last node
void ListStack::pop()
{
	Node *del = new Node;
	del = top;
	if (del->next == NULL)
	{
		delete del;
		top = NULL;
		tail = NULL;
		cout << "Cannot Solved" << endl;
	}
	while (del->next != tail)
	{
		del = del->next;
	}
	delete del->next;
	del->next = NULL;
	tail = del;
}

DFS::DFS()
{
	goal.puzzle[0][0] = 1;
	goal.puzzle[0][1] = 2;
	goal.puzzle[0][2] = 3;
	goal.puzzle[1][0] = 8;
	goal.puzzle[1][1] = 0;
	goal.puzzle[1][2] = 4;
	goal.puzzle[2][0] = 7;
	goal.puzzle[2][1] = 6;
	goal.puzzle[2][2] = 5;

	flag = false;
	size = 0;
	step = 0;
}

//ask to input root puzzle
void DFS::userInput()
{
	Matrix root;
	cout << "Please insert some values from 0 to 8 (include 0 as an empty space)" << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> root.puzzle[i][j];

	check(root);
}

//make movement
void DFS::move()
{
	Node *cur = new Node;
	cur = tail;

	//locat "0"
	if (cur->data.puzzle[0][0] == 0)
	{
		//follow L->U->R->D
		if (cur->dir == 0)
		{
			//move Right
			Matrix temp;
			temp = cur->data;

			temp.puzzle[0][0] = temp.puzzle[0][1];
			temp.puzzle[0][1] = 0;

			check(temp);

			cur->dir++;
		}
		else if (cur->dir == 1)
		{
			//move Down
			Matrix temp;
			temp = cur->data;

			temp.puzzle[0][0] = temp.puzzle[1][0];
			temp.puzzle[1][0] = 0;

			check(temp);

			cur->dir++;
		}
		else
		{
			pop();
		}
	}

	if (cur->data.puzzle[0][1] == 0)
	{
		//follow L->U->R->D
		if (cur->dir == 0)
		{
			//moveL()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[0][1] = temp.puzzle[0][0];
			temp.puzzle[0][0] = 0;

			check(temp);

			cur->dir++;
		}
		else if (cur->dir == 1)
		{
			//moveR()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[0][1] = temp.puzzle[0][2];
			temp.puzzle[0][2] = 0;

			check(temp);

			cur->dir++;
		}
		else if (cur->dir == 2)
		{
			//moveD()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[0][1] = temp.puzzle[1][1];
			temp.puzzle[1][1] = 0;

			check(temp);

			cur->dir++;
		}
		else
		{
			pop();
		}
	}

	if (cur->data.puzzle[0][2] == 0)
	{
		//follow L->U->R->D
		if (cur->dir == 0)
		{
			//moveL()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[0][2] = temp.puzzle[0][1];
			temp.puzzle[0][1] = 0;

			check(temp);
			cur->dir++;
		}
		else if (cur->dir == 1)
		{
			//moveD()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[0][2] = temp.puzzle[1][2];
			temp.puzzle[1][2] = 0;

			check(temp);
			cur->dir++;
		}
		else
		{
			pop();
		}
	}

	if (cur->data.puzzle[1][0] == 0)
	{
		//follow L->U->R->D
		if (cur->dir == 0)
		{
			//moveU()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[1][0] = temp.puzzle[0][0];
			temp.puzzle[0][0] = 0;

			check(temp);
			cur->dir++;
		}
		else if (cur->dir == 1)
		{
			//moveR()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[1][0] = temp.puzzle[1][1];
			temp.puzzle[1][1] = 0;

			check(temp);
			cur->dir++;
		}
		else if (cur->dir == 2)
		{
			//moveD()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[1][0] = temp.puzzle[2][0];
			temp.puzzle[2][0] = 0;

			check(temp);
			cur->dir++;
		}
		else
		{
			pop();
		}
	}

	if (cur->data.puzzle[1][1] == 0)
	{
		//follow L->U->R->D
		if (cur->dir == 0)
		{
			//moveL()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[1][1] = temp.puzzle[1][0];
			temp.puzzle[1][0] = 0;

			check(temp);
			cur->dir++;
		}
		else if (cur->dir == 1)
		{
			//moveU()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[1][1] = temp.puzzle[0][1];
			temp.puzzle[0][1] = 0;

			check(temp);
			cur->dir++;
		}
		else if (cur->dir == 2)
		{
			//moveR()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[1][1] = temp.puzzle[1][2];
			temp.puzzle[1][2] = 0;

			check(temp);
			cur->dir++;
		}
		else if (cur->dir == 3)
		{
			//moveD()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[1][1] = temp.puzzle[2][1];
			temp.puzzle[2][1] = 0;

			check(temp);
			cur->dir++;
		}
		else
		{
			pop();
		}
	}

	if (cur->data.puzzle[1][2] == 0)
	{
		//follow L->U->R->D
		if (cur->dir == 0)
		{
			//moveL()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[1][2] = temp.puzzle[1][1];
			temp.puzzle[1][1] = 0;

			check(temp);
			cur->dir++;
		}
		else if (cur->dir == 1)
		{
			//moveU()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[1][2] = temp.puzzle[0][2];
			temp.puzzle[0][2] = 0;

			check(temp);
			cur->dir++;
		}
		else if (cur->dir == 2)
		{
			//moveD()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[1][2] = temp.puzzle[2][2];
			temp.puzzle[2][2] = 0;

			check(temp);
			cur->dir++;
		}
		else
		{
			pop();
		}
	}

	if (cur->data.puzzle[2][0] == 0)
	{
		//follow L->U->R->D
		if (cur->dir == 0)
		{
			//moveU()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[2][0] = temp.puzzle[1][0];
			temp.puzzle[1][0] = 0;

			check(temp);
			cur->dir++;
		}
		else if (cur->dir == 1)
		{
			//moveR()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[2][0] = temp.puzzle[2][1];
			temp.puzzle[2][1] = 0;

			check(temp);
			cur->dir++;
		}
		else
		{
			pop();
		}
	}

	if (cur->data.puzzle[2][1] == 0)
	{
		//follow L->U->R->D
		if (cur->dir == 0)
		{
			//moveL()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[2][1] = temp.puzzle[2][0];
			temp.puzzle[2][0] = 0;

			check(temp);
			cur->dir++;
		}
		else if (cur->dir == 1)
		{
			//moveU()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[2][1] = temp.puzzle[1][1];
			temp.puzzle[1][1] = 0;

			check(temp);
			cur->dir++;
		}
		else if (cur->dir == 2)
		{
			//moveR()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[2][1] = temp.puzzle[2][2];
			temp.puzzle[2][2] = 0;

			check(temp);
			cur->dir++;
		}
		else
		{
			pop();
		}
	}

	if (cur->data.puzzle[2][2] == 0)
	{
		//follow L->U->R->D
		if (cur->dir == 0)
		{
			//moveL()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[2][2] = temp.puzzle[2][1];
			temp.puzzle[2][1] = 0;

			check(temp);
			cur->dir++;
		}
		else if (cur->dir == 1)
		{
			//moveU()
			Matrix temp;
			temp = cur->data;

			temp.puzzle[2][2] = temp.puzzle[1][2];
			temp.puzzle[1][2] = 0;

			check(temp);
			cur->dir++;
		}
		else
		{
			pop();
		}
	}
}

//include Isrepet, Isfind, print
void DFS::check(Matrix temp)
{
	if (IsFind(temp))
	{
		print(temp);
		return;
	}

	else if (IsRepet(temp))
	{
		return;
	}
	else
	{
		push(temp);
		print(temp);
		savePuzzle[size] = temp;
		size++;
	}
}

//if is repet in the saving list
bool DFS::IsRepet(Matrix cur)
{
	bool repet = false;
	for (int s = 0;s < size;s++)
	{
		if (cur == savePuzzle[s])
		{
			repet = true;
		}
	}
	return repet;
}

//if is found the goal
bool DFS::IsFind(Matrix cur)
{
	flag = false;
	if (cur == goal)
	{
		flag = true;
	}

	return flag;
}

void DFS::print(Matrix cur)
{
	if (step == 0)
	{
		cout << endl << "Initial state:" << endl;
		step++;
	}
	else if (step == MAXSTEP - 1)
	    cout << "Final step:" << endl;
	else
		cout << "Step " << step++ << ":" << endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << cur.puzzle[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//return flag
bool DFS::getflag()
{
	if (size < MAXSTEP && flag == false)
		flag = false;
	else
		flag = true;
	return flag;
}
