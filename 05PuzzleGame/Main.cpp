///////////////////////////////////////
//File: Main.cpp
//Creat an AI to solve puzzle game
//Student name: 
//Student number:
//Date: December 9, 2017
///////////////////////////////////////

#include "Puzzle.h"
#include <ctime>

int main()
{
  DFS game;

  game.userInput();

  clock_t begin = clock();

  while (!game.getflag())
    {
      game.move();
    }

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << "Time taken: " << elapsed_secs << "s" << endl;

  return 0;
}
