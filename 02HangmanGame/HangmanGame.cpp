/////////////////////////////////////////////////
//File: HangmanGame.cpp
//Write an program taht palys the game of Hangman
//Read the word to be guessed into word
//Student name: 
//Student number: 
//Date: October 15, 2017
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cctype>

using namespace std;

class AccessData
{
public:
	void getWord();
	void randomWord();
	void gameBegins();

	AccessData() {
		listSize = 0;
	}

protected:
	string word[100];
	string wordToGuess;
	char currentWord[100];
	int rnumber;
	int listSize;
	int wordLength;
};

class Guess : public AccessData {
public:
	void askForTries();
	void askToGuess();

	Guess() {
		usedTries = 0;
	}
protected:
	int usedTries;
	int maxTries;
	char currentGuess[26];
};

class Check : public Guess {
public:
	void checkTheEnter();
	void checkTheWord();

protected:
	bool goodGuess;

};

class Solution : public Check {
public:
	void printSolution();
	void ifWin();
	void loopToGuess();

protected:

};

void AccessData::getWord()
{
	//open the file to read, then get all word to the list
	ifstream file;
	file.open("WordList.txt");
	if (!file)
	{
		cout << "Word list file is missing." << endl;
		exit(1);
	}
	listSize = 0;
	while (!file.eof())
	{
		getline(file, word[listSize]);
		//cout << word[listSize] << endl;
		listSize++;
	}
	file.close();
}

void AccessData::randomWord()
{
	//get a random word
	srand((unsigned)time(0));
	rnumber = rand() % listSize;
	wordToGuess = word[rnumber];
	wordLength = wordToGuess.size();
	//hide the current word
	for (int i = 0; i < wordLength; i++)
	{
		currentWord[i] = '*';
	}
	currentWord[wordLength] = '\0';

}

void AccessData::gameBegins()
{
	cout << "Welcome to play this Hangman Game." << endl;
	cout << "The The word to guess is: ";
	cout << currentWord << endl << endl;
}

void Guess::askForTries()
{
	//ask for the max tries
	cout << "Enter the max number of tries: ";
	cin >> maxTries;
	while (maxTries > 26)
	{
		cout << "The max tires should no more than 26." << endl;
		cout << "Enter the max number of tries: ";
		cin >> maxTries;
	}

}

void Guess::askToGuess()
{
	//ask to guess a character
	if (maxTries - usedTries > 1)
		cout << "Guess a letter (you have " << maxTries - usedTries << " tries left): ";
	else
		cout << "Guess a letter (you have 1 try left): ";

	cin >> currentGuess[usedTries];
	currentGuess[usedTries] = tolower(currentGuess[usedTries]);

}

void Check::checkTheEnter()
{
	//check if the char entered is a letter
	while (!isalpha(currentGuess[usedTries]))
	{
		cout << "'" << currentGuess[usedTries] << "' is not a letter. Please try again." << endl;
		askToGuess();
	}

	//check if the char entered already been guessed
	for (int i = 0; i < usedTries; i++)
	{
		if (currentGuess[usedTries] == currentGuess[i])
		{
			cout << "'" << currentGuess[usedTries] << "' has already been guessed. Please try again." << endl;
			askToGuess();
		}
	}

}

void Check::checkTheWord()
{
	goodGuess = false;
	//check the position of the char entered
	for (int i = 0; i < wordLength; i++)
	{
		if (currentGuess[usedTries] == wordToGuess.at(i))
		{
			currentWord[i] = currentGuess[usedTries];
			goodGuess = true;
		}
	}

	usedTries++;
}

void Solution::printSolution()
{
	//to print the current word
	if (goodGuess)
	{
		cout << "Right! Word so far is: ";
		for (int i = 0; i < wordLength; i++)
		{
			cout << currentWord[i];
		}
		cout << endl;
	}
	else
	{
		cout << "Wrong! Try again. Word so far is: ";
		for (int i = 0; i < wordLength; i++)
		{
			cout << currentWord[i];
		}
		cout << endl;
	}
}

void Solution::ifWin()
{
	if (currentWord == wordToGuess)
	{
		cout << "You win!" << endl;
	}
	else
	{
		cout << "You loose!" << endl;
		cout << "The word is: ";
		cout << wordToGuess;
		cout << endl;
	}
}

void Solution::loopToGuess()
{
	while ((maxTries > usedTries) && (currentWord != wordToGuess))
	{
		askToGuess();
		checkTheEnter();
		checkTheWord();
		printSolution();
	}

}


int main()
{
	Solution game;

	game.getWord();
	game.randomWord();
	game.gameBegins();
	game.askForTries();

	game.loopToGuess();

	game.ifWin();

	system("pause");
	return 0;

}
