#ifndef UNCORTEDLIST_H
#define UNCORTEDLIST_H
#include"NodeType.h"

const int MAX_ITEMS = 10;

class UnsortList
{
public:
	UnsortList();
	void PrintList();
	bool IsEmpty() const;
	int getLength() const;
	void InsertItem(int data1, int data2);
	void DeleteItem(int data1, int data2);

private:
	int length;
	NodeType* head;
	NodeType* tail;
};

#endif