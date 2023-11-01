//////////////////////////////////////////////////////////////////////////////////////
//File: Conver_Exp.h
//Date: July 10, 2019
//Programmer: 
//Description: This program is able to defind which expression notation used for input
//			   Detect the possible errors for the input expression
//			   Convert to postfix notation if not the case, and build expression tree
//			   Use different traversal to print the arithmetic expression
//			   Evaluate the expression
//////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Expression
{
	string exp;
	string type;
};

struct Node
{
	char op;
	int num;
	Node *left;
	Node *right;
};

bool IsOperator(char c);
bool IsOperand(char c);
int Op_Weight(char op);
bool IsHigherWeight(char op1, char op2);

bool ErrorDetect(Expression *exp);
void Type_Def(Expression *exp);

void Type_Conv(Expression *exp);
string InfixToPostfix(string exp);
string PrefixToPostfix(string exp);

Node* Exp_Tree(Expression *exp);

void Preorder(Node *root);
void Inorder(Node *root);
void Postorder(Node *root);

int Cal_Tree(Node *root);