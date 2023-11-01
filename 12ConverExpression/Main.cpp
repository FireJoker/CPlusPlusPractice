////////////////////////////////////////////////////////////////////////////
//File: Main.cpp
//Date: July 10, 2019
//Programmer: 
//Description: Need an expression input in prefix, infix or postfix notation
////////////////////////////////////////////////////////////////////////////
#include "Conver_Exp.h"

int main() 
{
	Expression *temp;
	temp = new Expression;
	temp->exp = "";
	temp->type = "";

	cout << "Please enter an expression" << endl;
	cout << "Leave at least one space between operators, operands and symbols: " << endl;
	cout << "For example: ( -10 - 10 ) * ( 6 / 2 ) + 60 " << endl;

	getline(cin, temp->exp);

	// Defind notition type
	Type_Def(temp);

	// Output the original expression and its type
	cout << endl << "The expression enter is: " << temp->exp << endl;
	cout << "This expression is in " << temp->type << endl << endl;

	// Error detector
	if (ErrorDetect(temp))
		return 0;

	// Convert to postfix notation
	Type_Conv(temp);

	// Construct expression tree base on postfix notation
	Node* root = Exp_Tree(temp);

	// Output the expression in three different notation
	cout << "In preorder notation is: ";
	Preorder(root);
	cout << endl;
	cout << "In inorder notation is: ";
	Inorder(root);
	cout << endl;
	cout << "In postorder notation is: ";
	Postorder(root);
	cout << endl;

	// Calculate the result of this expression
	cout << "The result of this expression is: " << Cal_Tree(root) << endl;

	return 0;
}