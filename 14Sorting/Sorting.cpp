///////////////////////////////////////////////////////////////////////////
//File: Sorting.cpp
//Date: August 12, 2019
//Programmer: 
//Description: This program is going to generated an array with N elements
//			   It is able to sort the array with Insertion Sort, Merge Sort
//			   Quick Sort, Quick Insertion Sort
//			   Diaplay unsorted array, sorted array, running time
///////////////////////////////////////////////////////////////////////////
#include "Sorting.h"

// Function to print the array
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i % 20 == 0 && i != 0)
			cout << endl;
		cout << right << setw(5) << arr[i];
	}
	cout << endl << endl;
}

// Function to sort an array using insertion sort
void insertionSort(int arr[], int size)
{
	int i, key, j;
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;

		// Move element greater than key to one position ahead of current position
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

// Function to sort an array using merge sort
void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		// Sort two different half 
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

// Merge two intervals in sorted order
void merge(int arr[], int left, int mid, int right)
{
	// Create a temp array
	int temp[MAXSIZE];

	// Crawlers for both intervals and for temp
	int i = left, j = mid + 1, k = 0;

	// Traverse both arrays and in each iteration add smaller of both elements in temp 
	while (i <= mid && j <= right) 
	{
		if (arr[i] <= arr[j]) 
		{
			temp[k] = arr[i];
			k += 1; i += 1;
		}
		else 
		{
			temp[k] = arr[j];
			k += 1; j += 1;
		}
	}

	// Add elements left in the first interval 
	while (i <= mid) 
	{
		temp[k] = arr[i];
		k += 1; i += 1;
	}

	// Add elements left in the second interval 
	while (j <= right) 
	{
		temp[k] = arr[j];
		k += 1; j += 1;
	}

	// Copy temp to original interval
	for (i = left; i <= right; i += 1) 
	{
		arr[i] = temp[i - left];
	}
}

// Function to sort an array using quick sort
void quickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int pivot = partition(arr, left, right);
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	}
}

// Get the partition for quick sort
int partition(int arr[], int left, int right)
{
	// Pick the last element as pivot
	int pivot = arr[right];
	int i = left - 1;

	// Replace elements, less to left, greater to right
	for (int j = left; j <= right - 1; j++)
	{
		// If current element is less or equal to pivot, swap
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	// Swap piovt and , return the index of pivot
	swap(arr[i + 1], arr[right]);
	return i + 1;
}

// Function to sort an array using quick insertion sort
void quickInsertionSort(int arr[], int left, int right, int k)
{
	if (left < right && (right - left) > k)
	{
		int pivot = partition(arr, left, right);
		quickInsertionSort(arr, left, pivot - 1, k);
		quickInsertionSort(arr, pivot + 1, right, k);
	}
	else
	{
		int j = 1;
		for (int i = 0; i < right; i++)
		{

			if (arr[i] == NULL && arr[j] != NULL)
			{
				arr[i] = arr[j];
				arr[j] = NULL;
			}
			j++;
		}
		insertionSort(arr, right + 1);
	}
}