# Tic-Tac-Toe game
In this assignment, you will create a simple Tic-Tac-Toe game that can be played in different modes: human-vs-human, human-vs-computer, or computer-vs-computer.

## Game Rules
Tic-Tac-Toe, also known as X's and O's, Noughts and Crosses, is played on a 3x3 grid, referred to as the board. Players take turns placing their symbols, X and O, on an empty cell. The first player to form a straight line of three symbols (horizontally, vertically, or diagonally) wins. If the board is full and no player has a winning line, the game is a tie.


## Board Class
Implement a Board class to represent the 3x3 grid.

### Functions:
Determine the symbol in a cell.  
Place a symbol in a cell.  
Determine the winner, if any.  
Print the board to the standard output.  
The board should be displayed as follows:
```
+---+---+---+
| X |   |   |
+---+---+---+
|   | O | X |
+---+---+---+
|   |   |   |
+---+---+---+
```

## Player Class
Create an abstract Player class to handle player moves.

### Properties:
Symbol (X or O).  

### Abstract function:  
virtual makeMove(Board& board): Determine the player's next move (to be overridden by subclasses).  

### PlayerHuman Class  
Implement PlayerHuman as a subclass of Player.  
When choosing a move, display the current board and ask the user for the row and column to place a symbol.  
Validate user input for validity and empty cells. Ask again if the input is invalid.  

### PlayerRandom Class
Implement PlayerRandom as a subclass of Player.  
When choosing a move, return a random position on the grid that is not occupied.  

## Game Program
Write a program to play Tic-Tac-Toe.  
Prompt the user to select human or computer players for each team.  
Use dynamic memory allocation to create instances of appropriate Player subclasses and store them as pointers.  
Alternate between players, asking for moves until a player wins or the game is a tie.  
After the game ends, display the winner and the final board configuration.  
Exit the program after the game concludes.