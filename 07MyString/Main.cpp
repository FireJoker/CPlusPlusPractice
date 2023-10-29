#include "Mystring.h"

int main()
{
	char op;
	char cString[50];

	//greating
	cout << "Welcome to use MyString program" << endl;
	cout << "This progeram can use to add, change or reverse string" << endl << endl;

	//ask user input the first string
	cout << "Please input the string you want to operate: ";
	cin >> cString;
	MyString s1(cString);

	//choose the operation
	do
	{
		cout << "Please choose the option: A)dd  E)qual R)everse: ";
		cin >> op;
		op = toupper(op);
	} while (op != 'A' && op != 'E' && op != 'R');

	if (op == 'A')
	{
		//ask user input the second array
		cout << "Please input the string you want to add: ";
		cin >> cString;
		MyString s2(cString);
		s1 + s2;
	}
	else if (op == 'E')
	{
		//ask user input the second array
		cout << "Please enter the string you want to change as: ";
		cin >> cString;
		MyString s2(cString);
		s1 = s2;
	}
	else if (op == 'R')
	{
		s1.Reverse();
	}

	cout << "The output string is: ";
	s1.Put();
	cout << endl;

//	system("pause");
	return 0;
}