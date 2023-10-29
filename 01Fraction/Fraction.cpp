//////////////////////////////////////////////////////////////////////
//File name; Fraction.cpp
//Write a function that reads a problem involving two common fractions
//Student name: 
//Student number: 
//Date: October 1st, 2017
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void addFrac(int, int, int, int, int&, int&);
void subtractFrac(int, int, int, int, int&, int&);
void multiplyFrac(int, int, int, int, int&, int&);
void divideFrac(int, int, int, int, int&, int&);
void readFracProblem(int&, int&, int&, int&, char&);
void getFrac(int&, int&);

int main()
{
	int num1, denom1;
	int num2, denom2;
	int num3, denom3;
	char opSign;
	char choose;
	string op;

	do
	{
		readFracProblem(num1, denom1, num2, denom2, opSign);

		if (denom1 == 0 || denom2 == 0)
			cout << "Cannot solve this problem!" << endl;
		else
		{
			switch (opSign)
			{
			case '+':
				addFrac(num1, denom1, num2, denom2, num3, denom3);
				op = "addition";
				cout << "The result of the " << op << " is " << num3 << "/" << denom3 << endl;
				break;
			case '-':
				subtractFrac(num1, denom1, num2, denom2, num3, denom3);
				op = "substraction";
				cout << "The result of the " << op << " is " << num3 << "/" << denom3 << endl;
				break;
			case '*':
				multiplyFrac(num1, denom1, num2, denom2, num3, denom3);
				op = "multiplication";
				cout << "The result of the " << op << " is " << num3 << "/" << denom3 << endl;
				break;
			case '/':
				divideFrac(num1, denom1, num2, denom2, num3, denom3);
				op = "division";
				cout << "The result of the " << op << " is " << num3 << "/" << denom3 << endl;
				break;

			default:
				cout << "Error: invalid operation!" << endl;
				break;
			}
		}

		do
		{
			cout << "Continue: Y)es/N)o?";
			cin >> choose;
		} while (choose != 'Y' && choose != 'y' && choose != 'N' && choose != 'n');
		choose = choose;
	} while (choose != 'N' && choose != 'n');
	return 0;
}

void readFracProblem(int& num1, int& denom1, int& num2, int& denom2, char& opSign)
{
	cout << "Enter a common fraction problem (e.g. 3/4 + 5/6): ";
	getFrac(num1, denom1);
	cin >> opSign;
	getFrac(num2, denom2);
}

void getFrac(int& num, int& denom)
{
	char slash;
	cin >> num >> slash >> denom;
}

//Four common fraction opSignerations
//Add & Subtract & Multiply & Divide
void addFrac(int num1, int denom1, int num2, int denom2, int& num3, int& denom3)
{
	num3 = num1*denom2 + num2*denom1;
	denom3 = denom1*denom2;
}

void subtractFrac(int num1, int denom1, int num2, int denom2, int& num3, int& denom3)
{
	num3 = num1*denom2 - num2*denom1;
	denom3 = denom1*denom2;
}

void multiplyFrac(int num1, int denom1, int num2, int denom2, int& num3, int& denom3)
{
	num3 = num1*num2;
	denom3 = denom1*denom2;
}

void divideFrac(int num1, int denom1, int num2, int denom2, int& num3, int& denom3)
{
	num3 = num1*denom2;
	denom3 = denom1*num2;
}