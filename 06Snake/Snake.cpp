#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

class Snake
{
public:
	Snake();
	void draw();
	void input();
	void logic();
	enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
	bool getGameover() { return gameover; };

protected:
	bool gameover;
	int width;
	int height;
	int sx;
	int sy;
	int fx;
	int fy;
	eDirection dir;
	int tailx[100];
	int taily[100];
	int tailn;
	int prex;
	int prey;
	int prex2;
	int prey2;
	int score;
};

//set up
Snake::Snake()
{
	srand(time(0));
	gameover = false;
	width = 20;
	height = 20;
	sx = int(width / 2);
	sy = int(height / 2);
	fx = (rand() % width)+1;
	fy = (rand() % height)+1;
	tailn = 0;
	score = 0;
}

//draw the map
void Snake::draw()
{
	system("cls");
	for (int i = 0; i < height + 2; i++)
	{
		for (int j = 0; j < width + 2; j++)
		{
			if (i == 0 || i == height + 1)
				cout << '#';    //print wall
			else if (j == 0 || j == width + 1)
				cout << '#';    //print wall
			else if (i == fy && j == fx)
				cout << '*';    //print fruit
			else if (i == sy && j == sx)
			{
				cout << '0';    //print snake
			}
			else 
			{
				bool print = false;
				for (int k = 0; k < tailn; k++)
				{
					if (tailx[k] == j && taily[k] == i)
					{
						cout << 'o';
						print = true;
					}
				}
				if (!print)
					cout << ' ';
			}
		}
		cout << endl;
	}
	cout << "Score: " << score << endl;
}

//get direction
void Snake::input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w': dir = UP; break;
		case 's': dir = DOWN; break;
		case 'a': dir = LEFT; break;
		case 'd': dir = RIGHT; break;
		case 'x': gameover = true; break;
		}
	}
}

void Snake::logic()
{
	prex = tailx[0];
	prey = taily[0];
	tailx[0] = sx;
	taily[0] = sy;
	for (int i = 1; i < tailn; i++)
	{
		prex2 = tailx[i];
		prey2 = taily[i];
		tailx[i] = prex;
		taily[i] = prey;
		prex = prex2;
		prey = prey2;
	}

	//move
	switch (dir)
	{
	case UP: sy--; break;    //up
	case DOWN: sy++; break;    //down
	case LEFT: sx--; break;    //left
	case RIGHT: sx++; break;    //right
	}

	//hit the wall
	if (sx > width || sx < 0 || sy > height || sy < 0)
		gameover = true;

	//hit itself
	for (int i = 0; i < tailn; i++)
		if (tailx[i] == sx && taily[i] == sy)
			gameover = true;

	//eat fruit
	if (sx == fx && sy == fy)
	{
		score += 10;
		fx = (rand() % width)+1;
		fy = (rand() % height)+1;
		tailn++;
	}
}

int main()
{
	Snake obj;
	
	while (!obj.getGameover())
	{
		obj.draw();
		obj.input();
		obj.logic();
		Sleep(10);
	}

	return 0;
}