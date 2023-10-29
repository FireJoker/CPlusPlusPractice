# Hangman Game

The player guessing the word may, at any time, attempt to guess the whole word.  
The guesser can also win by guessing all the letters that appear in the word, thereby completing the word.


A sample run follows:
```
Enter the max number of tries: 10
Guess a letter (you have 10 tries left): a
Right! Word so far: a***a
Guess a letter (you have 9 tries left): x
Wrong! Try again. Word so far is: a***a
Guess a letter (you have 8 tries left): l
Right! Word so far: al**a
Guess a letter (you have 7 tries left): a
'a' has already been used. Try again.
Guess a letter (you have 7 tries left): u
Wrong! Try again. Word so far is: al**a
Guess a letter (you have 6 tries left): p
Right! Word so far: alp*a
Guess a letter (you have 5 tries left): h
You win!

```