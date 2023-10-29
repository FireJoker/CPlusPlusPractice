#include "NodeType.h"

// Creates a node contain data item nodeDataItem and next pointer nextPtr.
//template < class DT >
NodeType::NodeType(const int &Data1, const int &Data2, NodeType *nextPtr)
{
	data1 = Data1;
	data2 = Data2;
	next = nextPtr;
}
