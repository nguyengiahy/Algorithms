#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int arr[MAX] = { 0 };

class BST
{
private:
	int fValue;
	BST* fLeft;
	BST* fRight;
	BST()							//Default constructor for sentinel
	{
		fValue = int();
		fLeft = &NIL;
		fRight = &NIL;
	}
public:
	static BST NIL;					//Sentinel
	BST(int aValue)					//Constructor with a value passed in
	{
		fValue = aValue;
		fLeft = &NIL;
		fRight = &NIL;
	}
	int getValue()					//Return node's value
	{
		return fValue;
	}
	void insert(int key)			// Insert function
	{
		// First, find a position where key can be inserted
		BST* parent = &NIL;
		BST* child = this;			// "this" is the tree root.
		while (child != &NIL)
		{
			parent = child;
			if (child->fValue == key)		// If key already exists in the tree, then stop.
				break;
			else if (child->fValue > key)
				child = child->fLeft;
			else
				child = child->fRight;
		}

		if (child == &NIL)					// If key doesn't exist in the tree, we can insert it.
		{
			child = new BST(key);
			if (parent->fValue > key)
				parent->fLeft = child;
			else
				parent->fRight = child;
		}
	}
	void inorder()					// If we get an ascending order when using inorder traversal, it means the BST is built correctly.
	{
		if (this == &NIL)
			return;
		this->fLeft->inorder();
		cout << fValue << " ";
		this->fRight->inorder();
	}
	BST* search(int key)			// Search on BST
	{
		BST* temp = this;					// "this" is the tree root
		while (temp != &NIL)
		{
			if (temp->fValue == key)		// If found, break the loop.
				break;
			else if (temp->fValue > key)
				temp = temp->fLeft;
			else
				temp = temp->fRight;
		}
		return temp;
	}
	void deleteNode(int key)		// Delete function
	{
		// First, we need to find the position of the node to be deleted
		BST* parent = &NIL;
		BST* child = this;
		while (child != &NIL)
		{
			if (child->fValue == key)
				break;
			parent = child;
			if (child->fValue > key)
				child = child->fLeft;
			else
				child = child->fRight;
		}

		if (child == &NIL)		// The node to be deleted doesn't exist in the tree
			return;

		// If the node to be deleted exists in the tree
		if (child->fLeft != &NIL && child->fRight != &NIL)	// Case 1: the deleted node has 2 children
		{
			// Find the biggest element in the left subtree
			BST* tempParent = child;			// parent node of tempChild
			BST* tempChild = child->fLeft;		// tempChild is the biggest element in the left subtree
			while (tempChild->fRight != &NIL)
			{
				tempParent = tempChild;
				tempChild = tempChild->fRight;
			}

			child->fValue = tempChild->fValue;	// copy the value of tempChild 
			if (tempParent->fLeft == tempChild)	// delete the connection
				tempParent->fLeft = &NIL;
			else
				tempParent->fRight = &NIL;
			delete tempChild;					// delete the node
		}

		else if (child->fLeft != &NIL)			// Case 2: the deleted node has left child only
		{
			parent->fLeft = child->fLeft;
			delete child;
		}
		else if (child->fRight != &NIL)			// Case 2: the deleted node has right child only
		{
			parent->fRight = child->fRight;
			delete child;
		}
		else									// Case 3: the deleted node doesn't have any child
		{
			if (parent->fLeft == child)
				parent->fLeft = &NIL;
			else
				parent->fRight = &NIL;
			delete child;
		}
	}
};
BST BST::NIL;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// Build BST
	BST* tree = new BST(arr[0]);
	for (int i = 1; i < n; i++)
		tree->insert(arr[i]);
	cout << "Tree root: " << tree->getValue() << endl;
	tree->inorder();
	cout << endl;

	// Search on BST
	int key;
	cout << "Search value: ";
	cin >> key;
	BST* search = tree->search(key);
	if (search == &BST::NIL)
		cout << -1 << endl;
	else
		cout << search->getValue() << " is found." << endl;

	// Delete on BST
	cout << "Value to be deleted: ";
	cin >> key;
	tree->deleteNode(key);
	cout << "Tree root after modified: " << tree->getValue() << endl;
	tree->inorder();

	return 0;
}