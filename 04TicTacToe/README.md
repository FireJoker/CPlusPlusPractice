# Matrix

Implement a class to play the game of tic-tac-toe with two players.   
The class contains as private data member a 3 by 3 array of integers.  
The constructor should initialize the empty board to zeros.   
When the first player moves, place 1 in the specified square;  
place 2 when the second player moves. Each move must be done in an empty square.  
After each move, determine if the game has been won or if the game is a draw.

A sample run follows.
```
0 0 0
0 0 0
0 0 0
Player1 move: 1 1
1 0 0
0 0 0
0 0 0
Player2 move: 2 2
1 0 0
0 2 0
0 0 0
Player1 move: 3 1
1 0 0
0 2 0
1 0 0
Player2 move: 1 1
1 1 is used. Please choose another move: 3 3
1 0 0
0 2 0
1 0 2
Player1 move: 2 1
1 0 0
1 2 0
1 0 2
Player1 wins!
```