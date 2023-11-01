///////////////////////////////////////////////////////////
//File: MinMaxHeap.h
//Date: August 1, 2019
//Programmer: 
//Description: This program is able to build a min-max heap
//			   the options include insert, findMin, finMax,
//			   deleteMin, deleteMax, display
///////////////////////////////////////////////////////////
#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int MAXSIZE = 256;

class MinMaxHeap {
public:
	MinMaxHeap();
	~MinMaxHeap();
	void buildHeap(int tmp[]);	// Builds a minmaxheap
	void insertHeap(int data);	// Inserts a new element
	void printHeap();			// Display the heap

	int findMin();		// Return the minimum element
	int findMax();		// Return the maximum element
	int deleteMin();	// Delete the minimum element
	int deleteMax();	// Delete the maximum element

	int get_depth(int hole);		// Get depth of the hole
	void min_shift_up(int index);	// Shift up when new insert in minimum level
	void max_shift_up(int index);	// Shift up when new insert in maximum level
	void min_shift_down(int index);	// Shift dowm when delete the minimum element
	void max_shift_down(int index);	// Shift down when delete the maximum element

private:
	int size;
	int heap[MAXSIZE];
};


#endif