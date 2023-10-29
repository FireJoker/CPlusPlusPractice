/////////////////////////////////////////////////////
//File: SortAndSearch.cpp
//Using bubble sort to sort an array
//Then use binary search algorithm to search an array
//Student name:
//Student number: 
//Date: October 15, 2017
/////////////////////////////////////////////////////
#include <iostream>

using namespace std;

class Sort {
public:
	void getArray();
	void bubbleSort();
	void printArray();

protected:
	int number[100];
	int size;
};

class Search : public Sort {
public:
	int binarySearch(int);
	void printSearch(int, int);
};

void Sort::getArray()
{
	cout << "Enter the number of naturals: ";
	cin >> size;
	while (size > 100)
	{
		cout << "Size need to be no bigger than 100." << endl;
		cout << "Enter the number of naturals: ";
		cin >> size;
	}
	cout << "Enter the natural numbers to sort: " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> number[i];
	}
}

void Sort::bubbleSort()
{
	int i, j;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (number[j] > number[j + 1])
			{
				temp = number[j];
				number[j] = number[j + 1];
				number[j + 1] = temp;
			}
		}
	}
}

void Sort::printArray()
{
	int i;
	cout << endl;
	cout << "Numbers sorted in ascending order: " << endl;
	for (i = 0; i < size; i++)
	{
		cout << number[i] << " ";
	}
	cout << endl << endl;
}

int Search::binarySearch(int target)
{
	int mid, diff;
	int low = 0;
	int high = size - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		diff = number[mid] - target;
		if (diff == 0)
			return mid;
		else if (diff < 0)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

void Search::printSearch(int target, int index)
{
	if (index != -1)
	{
		cout << "Number " << target << " is found at position " << index + 1 << endl << endl;
	}
	else
	{
		cout << "Number " << target << " does not exist!" << endl << endl;
	}
}

int main()
{
	int target;
	int index;
	char choose;

	Search ob;

	ob.getArray();
	ob.bubbleSort();
	ob.printArray();

	do
	{
		cout << "Enter the number to search: ";
		cin >> target;

		ob.binarySearch(target);
		index = ob.binarySearch(target);
		ob.printSearch(target, index);
		do
		{
			cout << "Do you want to continue [Y/N]: ";
			cin >> choose;
			choose = tolower(choose);
		} while (choose != 'y' && choose != 'n');
		choose = choose;
	} while (choose != 'n');
	cout << "Good bye!" << endl;
	system("pause");

	return 0;
}