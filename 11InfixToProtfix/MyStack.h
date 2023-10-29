#ifndef MYSTACK_H
#define MYSTACK_H

const int MAX_ITEMS = 20;

template <typename ItemType>
class MyStack
{
public:
	MyStack();
	~MyStack();

	bool IsFull() const;
	bool IsEmpty() const;
	void Pop();
	void Push(ItemType newItem);
	void Display();
	int GetLength();
	ItemType GetTop();

private:
	int length;
	int top;
	ItemType items[MAX_ITEMS];
};

#endif