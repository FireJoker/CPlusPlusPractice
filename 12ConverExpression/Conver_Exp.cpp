//////////////////////////////////////////////////////////////////////////////////////
//File: Conver_Exp.cpp
//Date: July 10, 2019
//Programmer: 
//Description: This program is able to defind which expression notation used for input
//			   Detect the possible errors for the input expression
//			   Convert to postfix notation if not the case, and build expression tree
//			   Use different traversal to print the arithmetic expression
//			   Evaluate the expression
//////////////////////////////////////////////////////////////////////////////////////
#include "Conver_Exp.h"

// Check if input is an operator or not
bool IsOperator(char op)
{
	return (op == '+' || op == '-' || op == '*' || op == '/');
}

// Check if input is a symbol operand or not
bool IsOperand(char c)
{
	return (c >= '0' && c <= '9');
}

// Get the weight of operators
int Op_Weight(char op)
{
	switch (op)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	}
	return -1;

}

// Check which operator has higher weight
bool IsHigherWeight(char op1, char op2)
{
	int op1Weight = Op_Weight(op1);
	int op2Weight = Op_Weight(op2);

	if (op1Weight == op2Weight)
	{
		if (Op_Weight(op1))
			return false;
		else
			return true;
	}
	else if (op1Weight > op2Weight)
		return true;
	else
		return false;
}

// Defind the type of the expresion notation
void Type_Def(Expression *exp)
{
	string expression = exp->exp;
	int length = expression.length();
	int count_op = 0;
	int count_dig = 0;
	int count_ch = 0;

	// Reading from left to right and check first two characters
	for (int i = 0; i < length; i++)
	{
		// If character is a delimiter, move on
		if (expression[i] == ' ' || expression[i] == ',')
			continue;
		// Negative number, or more than one digit
		else if (IsOperand(expression[i]) || (expression[i] == '-' && IsOperand(expression[i + 1])))
		{
			while (expression[i] == '-' || IsOperand(expression[i]))
			{
				i++;
			}
			count_dig++;
			count_ch++;
		}
		// If character is a operator, check next character
		else if (IsOperator(expression[i]))
		{
			count_op++;
			count_ch++;
		}

		// Defind the type base on the counting numbers
		if (count_op == 2)
		{
			exp->type = "prefix notation";
			return;
		}
		else if (count_dig == 2)
		{
			exp->type = "postfix notation";
			return;
		}
		else if (count_ch == 2 || expression[i] == '(')
		{
			exp->type = "infix notation";
			return;
		}

	}
}

// Detected errors
bool ErrorDetect(Expression *exp)
{
	string temp = exp->exp;
	int len = temp.length();
	bool error = false;
	int count_bk = 0;
	int count_op = 0;
	int count_dig = 0;

	for (int i = 0; i < len; i++)
	{
		// Counting brackets
		if (temp[i] == '(')
			count_bk++;
		else if (temp[i] == ')')
			count_bk--;
		// If character is a delimiter, move on
		else if (temp[i] == ' ' || temp[i] == ',')
			continue;
		// Counting numbers include negative numbers
		else if (IsOperand(temp[i]) || (temp[i] == '-' && IsOperand(temp[i + 1])))
		{
			while (temp[i] == '-' || IsOperand(temp[i]))
			{
				i++;
			}
			count_dig++;
		}
		// Counting operators
		else if (IsOperator(temp[i]))
		{
			count_op++;
		}
		// If character is undefinded
		else
		{
			cout << "Error: undefinded character" << endl;
			error = true;
		}
	}

	if (count_bk > 0)
	{
		cout << "Error: missing ')'. " << endl;
		error = true;
	}
	else if (count_bk < 0)
	{
		cout << "Error: missing '('. " << endl;
		error = true;
	}
	if (count_dig > count_op + 1)
	{
		cout << "Error: missing operator" << endl;
		error = true;
	}
	else if (count_dig < count_op + 1)
	{		
		cout << "Error: missing operand" << endl;
		error = true;
	}

	cout << endl;
	return error;
}

// Convert the expression into a postfix notation, if it is not the case
void Type_Conv(Expression *exp)
{
	string temp = exp->exp;

	if (exp->type == "infix notation")
	{
		exp->exp = InfixToPostfix(temp);
	}
	else if (exp->type == "prefix notation")
	{
		exp->exp = PrefixToPostfix(temp);
	}
	else
	{
		exp->exp = temp;
	}
}

// Convert prefix to postfix expression 
string PrefixToPostfix(string exp) {

	stack<string> s;

	// Length of expression 
	int length = exp.length();

	// Reading from right to left 
	for (int i = length - 1; i >= 0; i--) 
	{
		// If character is a delimiter, move on. 
		if (exp[i] == ' ' || exp[i] == ',')
			continue;

		// Check if symbol is operator 
		else if (IsOperator(exp[i])) 
		{
			// Pop two operands from stack 
			string op1 = s.top(); s.pop();
			string op2 = s.top(); s.pop();

			// Concat the operands and operator 
			string temp = op1 + op2 + exp[i];

			// Push string temp back to stack 
			s.push(temp + " ");
		}

		// If symbol is an operand
		else
		{
			string temp = "";
			// If more than one digits, and negative number
			while (IsOperand(exp[i]) || IsOperator(exp[i]))
			{
				temp = exp[i] + temp;
				i--;
			}
			// Push the operand to the stack 
			s.push(temp + " ");
		}
	}

	//cout << s.top() << endl;
	
	//Stack contains the postfix expression and return
	return s.top();
}

// Convert infix to postfix expression
string InfixToPostfix(string exp)
{
	stack<char> s;
	string temp = "";

	// Length of expression 
	int length = exp.length();

	// Reading from left to right 
	for (int i = 0; i < length; i++) 
	{
		// If character is a delimiter, move on. 
		if (exp[i] == ' ' || exp[i] == ',') 
			continue;

		// If character is an operand
		else if (IsOperand(exp[i]) || (exp[i] == '-' && IsOperand(exp[i + 1])))
		{
			// Negative number, or more than one digit
			while (IsOperand(exp[i]) || exp[i] == '-')
			{
				temp += exp[i];
				i++;
			}
			temp += " ";
		}
		// If left bracket, push into stack
		else if (exp[i] == '(')
		{
			s.push(exp[i]);
		}
		// If right bracket, pop until meet left bracket
		else if (exp[i] == ')')
		{
			while (!s.empty() && s.top() != '(') 
			{
				temp = temp + s.top() + " ";
				s.pop();
			}
			// Pop "("
			s.pop();
		}
		// If character is operator, pop two elements from stack, perform operation and push the result back. 
		else if (IsOperator(exp[i]))
		{
			while (!s.empty() && s.top() != '(' && IsHigherWeight(s.top(), exp[i]))
			{
				temp = temp + s.top() + " ";
				s.pop();
			}
			s.push(exp[i]);
		}
	}

	// Pop all characters left in stack
	while (!s.empty())
	{
		temp = temp + s.top() + " ";
		s.pop();
	}

	//cout << temp;
	//String contains the postfix expression and return
	return temp;
}

// Construct expression tree base on postfix notation
Node* Exp_Tree(Expression *exp)
{
	stack<Node*> st;
	Node *t, *t1, *t2;
	string expression = exp->exp;
	int length = exp->exp.length();

	for (int i = 0; i < length; i++)
	{
		int digit = 0;
		int neg = 1;
		// If character is a delimiter, move on. 
		if (expression[i] == ' ' || expression[i] == ',')
			continue;

		// If digit, push into stack
		else if (IsOperand(expression[i]) || (expression[i] == '-' && IsOperand(expression[i + 1])))
		{
			// Negative number
			if (expression[i] == '-')
			{
				neg = -1;
				i++;
			}
			// More than one digits
			while(IsOperand(expression[i]))
			{
				digit = 10 * digit + expression[i] - '0';
				i++;
			}
			// Creat a new node and push into stack
			t = new Node;
			t->left = NULL;
			t->right = NULL;
			t->op = NULL;
			t->num = digit * neg;
			st.push(t);
		}
		// If operator, pop two nodes from stack, then make it as a tree
		else
		{
			// Creat a new node
			t = new Node;
			t->left = NULL;
			t->right = NULL;
			t->op = exp->exp[i];
			t->num = NULL;

			// Pop and store top two nodes
			t1 = st.top();
			st.pop();
			t2 = st.top();
			st.pop();

			// Make a tree
			t->right = t1;
			t->left = t2;

			// Push back to stack
			st.push(t);
		}
	}

	// Get the expression tree;
	t = st.top();
	st.pop();

	return t;
}

// Output by three different formate
// Use preorder traversal to print preorder notation
void Preorder(Node *root)
{
	if (root != NULL)
	{
		if (root->num != NULL)
			cout << root->num << " ";
		else if (root->op != NULL)
			cout << root->op << " ";
		Preorder(root->left);
		Preorder(root->right);
	}
}

// Use inorder traversal to print inorder notation
void Inorder(Node *root)
{
	if (root != NULL)
	{
		if (root->left != NULL && root->right != NULL)
			cout << "( ";
		Inorder(root->left);
		if (root->num != NULL)
			cout << root->num << " ";
		else if (root->op != NULL)
			cout << root->op << " ";
		Inorder(root->right);
		if (root->left != NULL && root->right != NULL)
			cout << ") ";
	}
}

// Use postorder traversal to print postorder notation
void Postorder(Node *root)
{
	if (root != NULL)
	{
		Postorder(root->left);
		Postorder(root->right);
		if (root->num != NULL)
			cout << root->num << " ";
		else if (root->op != NULL)
			cout << root->op << " ";
	}

}

// Calculate the result of expression tree
int Cal_Tree(Node *root)
{
	if (root != NULL)
	{
		if (root->num != NULL)
		{
			return root->num;
		}
		else if (root->op != NULL)
		{
			switch (root->op)
			{
			case'+':
				return Cal_Tree(root->left) + Cal_Tree(root->right);
			case'-':
				return Cal_Tree(root->left) - Cal_Tree(root->right);
			case'*':
				return Cal_Tree(root->left) * Cal_Tree(root->right);
			case'/':
				return Cal_Tree(root->left) / Cal_Tree(root->right);
			default:
				break;
			}
		}
	}
}