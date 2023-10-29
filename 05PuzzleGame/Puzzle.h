///////////////////////////////////////
//File: Puzzle.h
//Creat an AI to solve puzzle game
//Student name: 
//Student number:
//Date: December 9, 2017
///////////////////////////////////////

#include <iostream>
using namespace std;

const int MAXSTEP = 10000;

struct Matrix
{
	int puzzle[3][3];
	bool operator==(const Matrix& cur);
};

struct Node
{
	int dir;
	Matrix data;
	Node *next;
};

class ListStack
{
public:
	ListStack();
	void push(Matrix element);
	void pop();
protected:
	Node *top;
	Node *tail;
};

class DFS : public ListStack
{
public:
	DFS();
	void userInput();
	void move();
	void check(Matrix temp);
	bool IsRepet(Matrix cur);
	bool IsFind(Matrix cur);
	void print(Matrix cur);
	bool getflag();
protected:
	bool flag;  //if found the goal
	int step;  //print steps
	int size;  //place of savePuzzle
	Matrix goal;  //goal puzzle
	Matrix savePuzzle[MAXSTEP];  //to save puzzles
};
