#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <cctype>
using namespace std;

class MyString
{
public:
	MyString(); //constructor --- create empty string
	MyString(char *cString); //constructor --- create a string whose data is a copy of cString
	MyString(MyString const& s); //override the default copy constructor
	~MyString(); //destructor -- don't forget to free space allocated by the constructor

	void Reverse(); //reverse the string
	void Put(); //output string

	MyString operator = (MyString const& s); //override default assignment operator
	MyString operator + (MyString const& s); //concatenation operator
		
private:
	char *pData; //pointer to simple C-style representation of the string
				 //(i.e., sequence of characters terminated by null)
				 //pData is only a pointer. You must allocate space for
				 //the actual character data
	int length; //length of the string
									
};
#endif // MYSTRING_H