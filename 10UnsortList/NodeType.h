#ifndef NODETYPE_H
#define NODETYPE_H


class UnsortList;

//template < class DT >
class NodeType
{
private:
	// Constructor
	NodeType(const int &Data1, const int &Data2, NodeType *nextPtr);

	// Data members
	int data1;    // Store the name of class
	int data2;    // Store the box number of sold
	NodeType *next;    // Pointer to the next element

	friend class UnsortList;
};

#endif
