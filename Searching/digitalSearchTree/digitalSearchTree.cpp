#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int arr[MAX] = { 0 };
int bitNum = 0;

int getBit(int key, int bit)
{
	int mask = 1 << bit;
	int masked_n = key & mask;
	int thebit = masked_n >> bit;

	return thebit;
}

class DST
{
private:
	int fValue;
	DST* fLeft;
	DST* fRight;
	DST()
	{
		fValue = int();
		fLeft = &NIL;
		fRight = &NIL;
	}
public:
	static DST NIL;
	DST(int aValue)
	{
		fValue = aValue;
		fLeft = &NIL;
		fRight = &NIL;
	}
	int getValue()
	{
		return fValue;
	}
	void insert(int key)
	{
		// First, find a position where key can be inserted
		DST* parent = &NIL;
		DST* child = this;		// "this" is the tree root.
		int bit = bitNum;		// bitNum is the maximum number of bits
		while (child != &NIL)
		{
			parent = child;
			if (child->fValue == key)		// If key already exists in the tree, then stop.
				break;
			else
			{
				if (getBit(key, bit) == 0)
					child = child->fLeft;
				else
					child = child->fRight;
				bit--;
			}
		}

		if (child == &NIL)		// If key doesn't exist in the tree, we can insert it.
		{
			child = new DST(key);
			if (getBit(key, bit + 1) == 0)
				parent->fLeft = child;
			else
				parent->fRight = child;
		}
	}
	DST* search(int key)		// Search on DST
	{
		DST* temp = this;		// "this" is the tree root.
		int bit = bitNum;
		while (temp != &NIL)
		{
			if (temp->fValue == key)		// If found, break the loop.
				break;
			else
			{
				if (getBit(key, bit) == 0)
					temp = temp->fLeft;
				else
					temp = temp->fRight;
				bit--;
			}
		}
		return temp;
	}
	void deleteNode(int key)		// Delete function
	{
		// First, find position of the node to be deleted
		DST* parent = &NIL;
		DST* child = this;		// "this" is the tree root.
		int bit = bitNum;		// bitNum is the maximum number of bits
		while (child != &NIL)
		{
			
			if (child->fValue == key)		// If key already exists in the tree, then stop.
				break;
			else
			{
				parent = child;
				if (getBit(key, bit) == 0)
					child = child->fLeft;
				else
					child = child->fRight;
				bit--;
			}
		}

		if (child == &NIL)		// The node to be deleted doesn't exist in the tree
			return;

		// If the node to be deleted exists in the tree
		DST* node = child;
		while (child->fLeft != &NIL || child->fRight != &NIL)
		{
			parent = child;
			if (child->fLeft != &NIL)
				child = child->fLeft;
			else
				child = child->fRight;
		}
		node->fValue = child->fValue;		// copy the value of tempChild 
		if (parent->fLeft == child)			// delete the connection
			parent->fLeft = &NIL;
		else
			parent->fRight = &NIL;
		delete child;						// delete the node
	}
	void inorder()
	{
		if (this == &NIL)
			return;
		this->fLeft->inorder();
		cout << fValue << " ";
		this->fRight->inorder();
	}
};
DST DST::NIL;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if ((int)log2(arr[i]) > bitNum)		// find the biggest number of bits of an input
			bitNum = (int)log2(arr[i]);
	}

	// Build DST
	DST* tree = new DST(arr[0]);
	for (int i = 1; i < n; i++)
		tree->insert(arr[i]);
	tree->inorder();
	cout << endl;

	// Search on DST
	int key;
	cout << "Search value: ";
	cin >> key;
	DST* search = tree->search(key);
	if (search == &DST::NIL)
		cout << -1 << endl;
	else
		cout << search->getValue() << " is found." << endl;

	// Delete on BST
	cout << "Value to be deleted: ";
	cin >> key;
	tree->deleteNode(key);
	tree->inorder();

	return 0;
}