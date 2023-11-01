//////////////////////////////////////////////////////////
//File: Main.cpp
//Date: 
//Programmer: 
//Description: Need a list of natural number to build heap
//////////////////////////////////////////////////////////
#include "MinMaxHeap.h"

int main()
{
	MinMaxHeap MMH;
	int tmp[MAXSIZE] = { NULL };

	cout << "Please enter the list of natural numbers" << endl;
	cout << "Separate by -space- to build a min-max heap" << endl;

	// Get the default heap element, will stop when input is '0'
	int count = 0;
	do {
		cin >> tmp[count];
		count++;
	} while (getchar() != '\n');

	// Build the default heap
	MMH.buildHeap(tmp);

	// Ask user for the options
	int tmp_insert;
	char option;
	while (1)
	{
		cout << endl << "Please choose an option: " << endl;
		cout << "1) insert	2) display	3) find minimum	4) find maximum" << endl;
		cout << "5) delete minimum	6) delete maximum	7) quit" << endl;
		cin >> option;

		switch (option)
		{
		case '1':
			cout << endl << "Please enter a natural number insert to the heap: ";
			cin >> tmp_insert;
			MMH.insertHeap(tmp_insert);
			break;
		case '2':
			MMH.printHeap();
			break;
		case '3':
			cout << endl << "The minimun element in this heap is " << MMH.findMin() << endl;
			break;
		case '4':
			cout << endl << "The maximum element in this heap is " << MMH.findMax() << endl;
			break;
		case '5':
			cout << endl << "Delete the minimun element " << MMH.deleteMin() << " in this heap" << endl;
			break;
		case '6':
			cout << endl << "Delete the maximun element " << MMH.deleteMax() << " in this heap" << endl;
			break;
		case '7':
			return 0;
		default:
			cout << endl << "Invalid option. ";
			break;
		}
	}
	return 0;
}