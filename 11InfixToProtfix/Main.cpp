#include "MyStack.h"
#include <iostream>
#include <string>
using namespace std;

//Declaration of the functions
string InfixToPostfix(string exp);
bool IsOperator(char C);
bool IsOperand(char C);
int getOpWeight(char C);
bool IsHigherWeight(char op1, char op2);

int main()
{
	//greating
	cout << "Welcome to use this program" << endl;
	cout << "which can convert an infix expression to a postfix expression" << endl << endl;

	//string expression = "A * (B + C) / D"    //test

	string expression;    //expression
	cout << "Please enter the infix expression: " << endl;
	getline(cin, expression);
	string postfix = InfixToPostfix(expression);

	cout << "Infix is: " << expression << endl;
	cout << "Postfix is: " << postfix << endl;

//	system("pause");
	return 0;
}

//Function to convert an infix expression to a postfix expression
string InfixToPostfix(string exp)
{
	MyStack<char> s;
	string postfix = "";

	for (int i = 0; i < exp.length(); i++)
	{
		//If character is ' ', continue
		if (exp[i] == ' ')
			continue;

		//If character is operand, add to string
		else if (IsOperand(exp[i]))
		{
			postfix += exp[i];
		}

		//If is the '(', push onto s
		else if (exp[i] == '(')
		{
			s.Push(exp[i]);
		}

		//If is the ')', pop until '('
		else if (exp[i] == ')')
		{
			while (!s.IsEmpty() && s.GetTop() != '(')
			{
				postfix += s.GetTop();
				s.Pop();
			}
			s.Pop();    //Pop '('
		}

		//If character is operator, push onto s
		else if (IsOperator(exp[i]))
		{	
			while (!s.IsEmpty() && s.GetTop() != '(' && IsHigherWeight(s.GetTop(), exp[i]))
			{
				postfix += s.GetTop();
				s.Pop();
			}
			s.Push(exp[i]);
		}
	}

	while (!s.IsEmpty())
	{
		postfix += s.GetTop();
		s.Pop();
	}

	return postfix;
}

//Check input is an operator or not
bool IsOperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '^')
		return true;
	else
		return false;
}

//Check input is an operand or not
bool IsOperand(char C)
{
	if ((C >= '0' && C <= '9') || (C >= 'a' && C <= 'z') || (C >= 'A' && C <= 'Z'))
		return true;
	else
		return false;
}

//Get the weight of operators
int getOpWeight(char C)
{
	switch (C)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

//Check which operator has higher weight
bool IsHigherWeight(char op1, char op2)
{
	int op1Weight = getOpWeight(op1);
	int op2Weight = getOpWeight(op2);

	if (op1Weight == op2Weight)
	{
		if (getOpWeight(op1))
			return false;
		else
			return true;
	}
	else if (op1Weight > op2Weight)
		return true;
	else
		return false;
}