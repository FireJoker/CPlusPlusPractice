///////////////////////////////////////////////////////////////////////////
//File: Main.cpp
//Date: August 12, 2019
//Programmer: 
//Description: This program is going to generated an array with N elements
//			   It is able to sort the array with Insertion Sort, Merge Sort
//			   Quick Sort, Quick Insertion Sort
//			   Diaplay unsorted array, sorted array, running time
///////////////////////////////////////////////////////////////////////////
#include "Sorting.h"
#include <ctime>
using namespace std; 

int main()
{
	clock_t  start, stop, total, temp = 100;
	// Ask user to input two numbers
	int N, K;
	cout << "This function will using differnt sorting algorithms to sort a set of rand number" << endl;
	cout << "Please input the size of the rand number and maximum is " << MAXSIZE << "): ";
	cin >> N;

	while (N > MAXSIZE)
	{
		cout << "Please input the size less than " <<MAXSIZE << ": ";
		cin >> N;
	}

	cout << "Please enter the key number for quick insortion sort: ";
	cin >> K;

	// Generate a random array an backup in size N, between 1 to 100
	int arr[MAXSIZE], backup[MAXSIZE];
	srand((unsigned)time(0));
	for (int i = 0; i < N; i++)
	{
		arr[i] = (rand() % MAXRANGE) + 1;
		backup[i] = arr[i];
	}

	// Print the random array
	cout << endl << "The random array between 1 and " << MAXRANGE <<" in size " << N << endl;
	printArray(arr, N);

	// Using insertionSort algorithm, and measure the running time
	start = clock();
	insertionSort(arr, N);
	stop = clock();
	cout << "Running for Insertion Sort is " << (double)(stop - start) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
	cout << "The sorted array by Insertion Sort shows below: " << endl;
	printArray(arr, N);

	// Reset the array to random array
	for (int i = 0; i < N; i++)
		arr[i] = backup[i];

	// Using mergeSort algorithm, and measure the running time
	start = clock();
	mergeSort(arr, 0, N - 1);
	stop = clock();
	cout << "Running for Merge Sort is " << (double)(stop - start) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
	cout << "The sorted array by Merge Sort shows below: " << endl;
	printArray(arr, N);

	// Reset the array to random array
	for (int i = 0; i < N; i++)
		arr[i] = backup[i];

	// Using quickSort algorithm, and measure the running time
	start = clock();
	quickSort(arr, 0, N - 1);
	stop = clock();
	cout << "Running for Quick Sort is " << (double)(stop - start) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
	cout << "The sorted array by Quick Sort shows below: " << endl;
	printArray(arr, N);

	// Reset the array to random array
	for (int i = 0; i < N; i++)
		arr[i] = backup[i];

	// Using quickInsertionSort algorithm, and measure the running time
	start = clock();
	quickInsertionSort(arr, 0, N - 1, K);
	stop = clock();
	cout << "Running for Quick Insortion Sort is " << (double)(stop - start) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
	cout << "The sorted array by Quick Insortion Sort shows below: " << endl;
	printArray(arr, N);


	int newk;
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
			arr[i] = backup[i];
		start = clock();
		quickInsertionSort(arr, 0, N - 1, k);
		stop = clock();
		total = (double)(stop - start) * 1000 / CLOCKS_PER_SEC;
		if (total < temp)
			temp = total;
		if (total > temp)
		{
			cout << "The pair is (" << N << ", " << k << ")" << endl;
			return 0 ;
		}
	}

	return 0;
}