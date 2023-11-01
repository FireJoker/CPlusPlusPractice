///////////////////////////////////////////////////////////
//File: MinMaxHeap.cpp
//Date: August 1, 2019
//Programmer: 
//Description: This program is able to build a min-max heap
//			   the options include insert, findMin, finMax,
//			   deleteMin, deleteMax, display
///////////////////////////////////////////////////////////
#include "MinMaxHeap.h"

// Constructs an empty min-max heap
MinMaxHeap::MinMaxHeap()
{
	size = 0;
	heap[MAXSIZE] = { NULL };
}

// Destructs the min-max heap
MinMaxHeap::~MinMaxHeap()
{
	size = 0;
	heap[MAXSIZE] = { NULL };
}

// Build a minmaxheap
void MinMaxHeap::buildHeap(int tmp[])
{
	for (int i = 0; i < MAXSIZE && tmp[i] != NULL; i++) {
		insertHeap(tmp[i]);
	}
}

// Display the heap looks like a tree
void MinMaxHeap::printHeap()
{
	if (size == 0)
	{
		cout << "The heap is empty" << endl;
		return;
	}

	int i = 1;
	int level = 1;
	while (i <= size)
	{
		cout << "level " << level - 1 << ": ";
		while (i < pow(2, level) && i <= size)
		{
			cout << heap[i] << " ";
			i++;
		}
		cout << endl;
		level++;
	}

}

// Insert a new element to the heap
void MinMaxHeap::insertHeap(int data)
{
	// heap[size] now is a hole, insert data
	size++;
	heap[size] = data;

	// Check the depth and decide the sort method
	int depth = get_depth(size);
	if (depth % 2 == 0)
		min_shift_up(size);
	else if (depth % 2 == 1)
		max_shift_up(size);
}

// Get depth of the hole
int MinMaxHeap::get_depth(int hole)
{
	int depth = 1;
	while ((pow(2, depth) - 1) < hole) {
		depth++;
	}
	return depth - 1;
}

// Shift up when new insert in minimum level
void MinMaxHeap::min_shift_up(int index)
{
	// If have no parent, return
	if (index / 2 == 0)
		return;
	// If have parent but not gparent, compare
	else if (index / 4 == 0)
	{
		int p = index / 2;
		// Swap if greater
		if (heap[p] < heap[index])
			swap(heap[p], heap[index]);
		return;
	}
	// If have parent and gparent, compare
	else
	{
		int gp = index / 4;
		// Swap if less than gparent, then check gparent
		if (heap[gp] > heap[index])
		{
			swap(heap[index], heap[gp]);
			min_shift_up(gp);
		}
		else
		{
			// Swap if greater than parent 
			int p = index / 2;
			if (heap[p] > heap[index])
				return;
			else
			{
				swap(heap[p], heap[index]);
				max_shift_up(p);
			}
		}
	}
}

// Shift up when new insert in maximum level
void MinMaxHeap::max_shift_up(int index)
{
	// If have no parent, return
	if (index / 2 == 0)
		return;
	// If have parent but not gparent, compare
	else if (index / 4 == 0)
	{
		int p = index / 2;
		// Swap if less than parent
		if (heap[p] > heap[index])
			swap(heap[p], heap[index]);
		return;
	}
	// If have parent and gparent, compare
	else
	{
		int gp = index / 4;
		// Swap if greater than gparent, then check gparent
		if (heap[gp] < heap[index])
		{
			swap(heap[index], heap[gp]);
			max_shift_up(gp);
		}
		else
		{
			// Swap if less than parent 
			int p = index / 2;
			if (heap[p] < heap[index])
				return;
			else
			{
				swap(heap[p], heap[index]);
				min_shift_up(p);
			}
		}
	}
}

// If the heap is non-empty, returns the minimum elememt
int MinMaxHeap::findMin()
{
	if (size == 0) {
		cout << "Error: The heap is empty" << endl;
		return -1;
	}
	else { return heap[1]; }
}

// If the heap is non-empty, returns the maximum elememt
int MinMaxHeap::findMax()
{
	if (size == 0) {
		cout << "Error: The heap is empty" << endl;
		return -1;
	}
	else if (size == 1) { return heap[1]; }
	else if (size == 2) { return heap[2]; }
	else if (heap[2] > heap[3]) { return heap[2]; }
	else if (heap[3] > heap[2]) { return heap[3]; }
	else { return 0; }
}

// If the heap is non-empty, delete and return the minimum elememt
int MinMaxHeap::deleteMin()
{
	int max;
	if (size == 0) { 
		cout << "Error: The heap is empty" << endl;
		return -1;
	}
	else {
		max = heap[1];
		heap[1] = heap[size--];
	}
	min_shift_down(1);

	return max;
}

// Shift dowm when delete the minimum element
void MinMaxHeap::min_shift_down(int index) 
{
	// If have no child, return
	if (index * 2 > size)
		return;
	// If have child but not gchild, find minimum child
	else if (index * 4 > size)
	{
		// Compare left child (2i) and right child (2i+1) 
		int c = index * 2;
		if (c + 1 <= size && heap[c] > heap[c + 1])
			c++;
		// Swap if greater than minimum child
		if (heap[index] > heap[c])
			swap(heap[index], heap[c]);
		return;
	}
	// If have child and gchild, find minimum child or gchild
	else
	{		
		// Find the minimum child
		int c = index * 2;
		if (c + 1 <= size && heap[c] > heap[c + 1])
			c++;
		// Swap if greater than smaller child, then check
		if (heap[index] > heap[c])
		{
			swap(heap[index], heap[c]);
			max_shift_down(c);
		}

		// Find the minimum gchild
		int gc = index * 4;
		int sgc = index * 4;
		for (int i = gc; i < gc + 4 && i <= size; i++)
		{
			if (heap[i] < heap[sgc])
				sgc = i;
		}
		// Swap if greater than smallest gchild,
		if (heap[sgc] < heap[index])
		{
			swap(heap[sgc], heap[index]);
			min_shift_down(sgc);
		}
	}
}

// If the heap is non-empty, delete and return the maximum elememt 
int MinMaxHeap::deleteMax()
{
	int max;
	if (size == 0) {
		cout << "Error: The heap is empty" << endl;
		return -1;
	}
	else if (size == 1) {
		max = heap[1];
		heap[1] = heap[size--];
	}
	else if (size == 2) {
		max = heap[2];
		heap[2] = heap[size--];
	}
	else if (heap[2] >= heap[3]) {
		max = heap[2];
		heap[2] = heap[size--];
		if (size > 3)
			max_shift_down(2);
	}
	else if (heap[3] > heap[2]) {
		max = heap[3];
		heap[3] = heap[size--];
		if (size > 3)
			max_shift_down(3);
	}
	else { throw"Error: Cannot fint the maxmum element in the heap"; }

	return max;
}

// Shift dowm when delete the maximum element
void MinMaxHeap::max_shift_down(int index)
{
	// If have no child, return
	if (index * 2 > size)
		return;
	// If have child but not gchild, find maximum child
	else if (index * 4 > size)
	{
		// Compare left child (2i) and right child (2i+1)
		int c = index * 2;
		if (c + 1 <= size && heap[c] < heap[c + 1])
			c++;
		// Swap if less than maximun child
		if (heap[index] < heap[c])
			swap(heap[index], heap[c]);
		return;
	}
	// If have child and gchild, find maximum child or gchild
	else
	{
		// Find the maximum child
		int c = index * 2;
		if (c + 1 <= size && heap[c] < heap[c + 1])
			c++;
		// Swap if less than maximum child, then check
		if (heap[index] < heap[c])
		{
			swap(heap[index], heap[c]);
			min_shift_down(c);
		}

		// Find the maximum gchild
		int gc = index * 4;
		int bgc = index * 4;
		for (int i = gc; i < gc + 4 && i <= size; i++)
		{
			if (heap[i] > heap[bgc])
				bgc = i;
		}
		// Swap if less than maximum gchild,
		if (heap[bgc] > heap[index])
		{
			swap(heap[bgc], heap[index]);
			max_shift_down(bgc);
		}
	}
}