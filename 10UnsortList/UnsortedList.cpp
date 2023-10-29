#include "UnsortedList.h"
#include <iostream>
#include <iomanip>
#include <new>
using namespace std;

//template <class DT>
UnsortList::UnsortList()
{
	length = 0;
	head = NULL;
	tail = NULL;
}

//template <class DT>
bool UnsortList::IsEmpty() const
{
	return(length == 0);
}

//template <class DT>
int UnsortList::getLength() const
{
	return length;
}

// Insort element into linklist
//template <class DT>
void UnsortList::InsertItem(int data1, int data2)
{
	// Inserts item as the head
	if (IsEmpty())
	{
		// Reset the head
		head = new NodeType(data1, data2, NULL);
		tail = head;
	}
	// Inserts item as the tail
	else
	{
		// Creat a new node
		NodeType* temp = new NodeType(data1, data2, NULL);
		tail->next = temp;
		tail = temp;
	}

	length++;
}

// Delete the element
//template <class DT>
void UnsortList::DeleteItem(int data1, int data2)
{
	if (!IsEmpty())    //Empty linklist
	{
		NodeType *temp = head;
		if (head->data1 == data1 && head->data2 == data2)    // Is the first node
		{
			head = head->next;
			delete temp;
			length--;
		}
		else
		{
			while (temp->next != NULL && temp->next->data1 != data1 && temp->next->data2 != data2)
			{
				temp = temp->next;
			}
			if (temp->next != NULL)    // Found the element
			{
				NodeType  *target = temp->next;
				temp->next = temp->next->next;
				delete target;
				length--;
			}
			else    // The element is not in the list
			{
				cout << "The element is not in the list" << endl;
			}
		}
	}
	else
		cout << "It is an empty linklist" << endl;
}

// Print the list
//template <class DT>
void UnsortList::PrintList()
{
	int max = 0;
	int classID[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	cout << "Id. Number" << setw(10) << "Boxes Sold" << endl;

	NodeType  *temp = head;
	while (temp != NULL)
	{
		cout << temp->data1 << setw(10) << temp->data2 << endl;    // list every elements
		if(temp->data1 <= 10)
			classID[(temp->data1) - 1] += temp->data2;    // add every class sold
		if (max < classID[(temp->data1) - 1])
			max = classID[(temp->data1) - 1];    // get the max sold
		temp = temp->next;
	}

	cout << endl << "The total number of boxes sold by class 1 is: " << classID[0] << endl;
	cout << "The total number of boxes sold by class 2 is: " << classID[1] << endl;
	cout << "The total number of boxes sold by class 3 is: " << classID[2] << endl;
	cout << "The total number of boxes sold by class 4 is: " << classID[3] << endl;
	cout << "The total number of boxes sold by class 5 is: " << classID[4] << endl;
	cout << "The total number of boxes sold by class 6 is: " << classID[5] << endl;
	cout << "The total number of boxes sold by class 7 is: " << classID[6] << endl;
	cout << "The total number of boxes sold by class 8 is: " << classID[7] << endl;
	cout << "The total number of boxes sold by class 9 is: " << classID[8] << endl;
	cout << "The total number of boxes sold by class 10 is: " << classID[9] << endl << endl;
	for (int i = 0; i < 10; i++)
	{
		if (classID[i] == max && max != 0)
			cout << "Class " << i + 1 << "wins" << endl;
	}

}