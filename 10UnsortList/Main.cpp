#include <iostream>
#include "UnsortedList.h"

using namespace std;

int main()
{
	int choice = 0;
	int data1, data2;
	UnsortList obj;

	// Greating
	cout << "Welcome to use this program" << endl;
	cout << "Pleasa choose an operation and follow the steps" << endl;

	while (choice != 4)
	{
		cout << endl;
		cout << "1) Insert an item to the list" << endl;
		cout << "2) Delete an item from the list" << endl;
		cout << "3) Show the current result" << endl;
		cout << "4) Exit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Please input the class id number and the boxes sold: ";
			cin >> data1 >> data2;
			obj.InsertItem(data1, data2);
			break;

		case 2:
			cout << "Please input the data you want to delete: ";
			cin >> data1 >> data2;
			obj.DeleteItem(data1, data2);
			break;

		case 3:
			obj.PrintList();
			break;

		default:
			cout << endl << "Invalid choice. Please try again." << endl;
			break;
		}
	}

	return 0;
}