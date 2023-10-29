#include "MyStack.h"
#include <iostream>
using namespace std;

//Class constructor
template <typename ItemType>
MyStack<ItemType>::MyStack()
{
	top = -1;
}

//Class destructor
template <typename ItemType>
MyStack<ItemType>::~MyStack()
{
	//
}

//Check the stack is empty or not
template <typename ItemType>
bool MyStack<ItemType>::IsEmpty() const
{
	return (top == -1);
}

//Check the stack is full or not
template <typename ItemType>
bool MyStack<ItemType>::IsFull() const
{
	return (top == MAX_ITEMS - 1);
}

//Push iten onto the stack
template <typename ItemType>
void MyStack<ItemType>::Push(ItemType newItem)
{
	if (IsFull())
	{
		cout << "Full stack." << endl;
		return;
	}
	else
	{
		top++;
		items[top] = newItem;
	}
}

//Pop the top item of stack
template <typename ItemType>
void MyStack<ItemType>::Pop()
{
	if (IsEmpty())
	{
		cout << "Empty stack." << endl;
		return;
	}
	else
		top--;
}

//Display the stack
template <typename ItemType>
void MyStack<ItemType>::Display()
{
	if (top == -1)
	{
		cout << "Stack is empty" << endl;
		return;
	}
	else
	{
		cout << "The stack is:" << endl;
		for (int i = 0; i <= top; i++)
		{
			cout << items[i] << endl;
		}
	}
}

//Return the length of stack
template <typename ItemType>
int MyStack<ItemType>::GetLength()
{
	return length;
}

//Return the top item
template <typename ItemType>
ItemType MyStack<ItemType>::GetTop()
{
	if (IsEmpty())
	{
		cout << "Empty stack." << endl;
		return 0;
	}

	return items[top];
}

template class MyStack<char>;
template class MyStack<int>;