///////////////////////////////////////////////////////////////////////////
//File: Sorting.h
//Date: August 12, 2019
//Programmer: 
//Description: This program is going to generated an array with N elements
//			   It is able to sort the array with Insertion Sort, Merge Sort
//			   Quick Sort, Quick Insertion Sort
//			   Diaplay unsorted array, sorted array, running time
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <utility>
using namespace std;
const int MAXSIZE = 10000;
const int MAXRANGE = 1000;

void printArray(int arr[], int size);

void insertionSort(int arr[], int size);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void quickInsertionSort(int arr[], int left, int right, int k);

