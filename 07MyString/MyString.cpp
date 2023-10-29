#include "Mystring.h"

// default constructor
MyString::MyString()
{
	length = 1;
	pData = new char[length];

	if (pData[length - 1] != '\0')	//set the last element to be NULL
	{
		pData[length - 1] = '\0';
	}
}

// constructor with char argument
MyString::MyString(char *cString)
{
	for (int i = 0; cString[i] != '\0'; i++)    //get length
		length++;

	this->pData = new char[length + 1];

	for (int i = 0; i < length; i++)    //create a copy of cString
		pData[i] = cString[i];

	if (pData[length] != '\0')    //set the last element to be NULL
	{
		pData[length] = '\0';
	}
}

//override the default copy constructor
MyString::MyString(MyString const& s)
{
	this->pData = new char[s.length + 1];

	for (int i = 0; s.pData[i] != '\0'; i++)
		pData[i] = s.pData[i];

	if (pData[s.length] != '\0')	//set the last element to be NULL
	{
		pData[s.length] = '\0';
	}
}

// destructor
MyString::~MyString()
{
	if (pData != NULL)    //delete pointers
	{
		pData = NULL;
		delete pData;
	}
}

void MyString::Put()
{
	for (int i = 0; pData[i] != '\0'; i++)    //output string
		cout << pData[i];
}

void MyString::Reverse()
{
	int templ = length;      
	for (int i = 0; i < length; i++)    //swap the first and the last element
	{
		char temp = this->pData[i];
		this->pData[i] = this->pData[length - 1];
		this->pData[length - 1] = temp;
		length--;
	}

	if (this->pData[templ] != '\0')    //set the last element to be NULL
	{
		this->pData[templ] = '\0';
	}
}

MyString MyString::operator = (MyString const& s)
{
	delete[] pData;
	pData = new char[s.length];

	for (int i = 0; i < s.length;i++)
	{
		pData[i] = s.pData[i];    //assign data to the new one
	}

	if (pData[s.length] != '\0')	//set the last element to be NULL
	{
		pData[s.length] = '\0';
	}

	return *this;
}

MyString MyString::operator + (MyString const& s)
{
	int nlength = length + s.length;    //length of new array

	for (int i = length; i < nlength; i++)
	{
		this->pData[i] = s.pData[i - length];
	}

	if (this->pData[nlength] != '\0')	//set the last element to be NULL
	{
		this->pData[nlength] = '\0';
	}

	return *this;
}