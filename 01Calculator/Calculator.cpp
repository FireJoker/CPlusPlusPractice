//////////////////////////////////////////////
//File: Calculator.cpp
//Write a program to model a simple calculator
//Student name: 
//Student number: 
//Date: October 1st, 2017
//////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <math.h>	
using namespace std;

void scan_data(char&, float&);
void do_next_op(char, float, float&);

int main()
{
	float accumulator, operand;
	char operation;
	accumulator = 0;

	cout << fixed << showpoint << setprecision(1);

	scan_data(operation, operand);
	do
	{
		do_next_op(operation, operand, accumulator);
		cout << "Result so far is " << accumulator << endl;
		scan_data(operation, operand);
	} while (operation != 'q' && operation != 'Q');
	cout << "Final result is " << accumulator << endl;
}

void scan_data(char& operation, float& operand)
{
	cout << "Enter a common operation, and a number (e.g. +2.0):";
	cin >> operation;
	cin >> operand;
}

void do_next_op(char operation, float operand, float& accumulator)
{
	switch (operation)
	{
	case '+':
		accumulator += operand;
		break;
	case '-':
		accumulator -= operand;
		break;
	case '*':
		accumulator *= operand;
		break;
	case '/':
		if (operand == 0)
		{
			cout << "Error: division by zero" << endl;
			accumulator = accumulator;
		}
		else
			accumulator /= operand;
		break;
	case '^':
		accumulator = pow(accumulator, operand);
		break;
	case '%':
		accumulator = int(accumulator) % int(operand);
		break;

	default:
		cout << "Error: invalid operand" << endl;
		break;
	}
}
