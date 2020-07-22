#include<iostream>
using namespace std;

const int MAX = 1000;
int arr[MAX] = { 0 };

class BST
{
private:
	int fValue;
	BST* fLeft;
	BST* fRight;
	BST()						//Default constructor for sentinel
	{
		fValue = int();
		fLeft = &NIL;
		fRight = &NIL;
	}
public:
	static BST NIL;				//Sentinel
	BST(const int& aValue)		//Constructor with a value passed in
	{
		fValue = aValue;
		fLeft = &NIL;
		fRight = &NIL;
	}
	
	bool isEmpty()				//Check if this is an empty node
	{
		return this == &NIL;
	}
	
	const int& getValue()		//Return node's value
	{
		return fValue;
	}

	// Insert function
	BST* insert(BST* root, int aValue)
	{
		// If root is NIL, insert the first node
		if (root->isEmpty())
			return new BST(aValue);

		if (aValue < root->fValue)
			root->fLeft = insert(root->fLeft, aValue);
		else
			root->fRight = insert(root->fRight, aValue);

		// Return 'root' node, after insertion. 
		return root;
	}

	// Inorder traversal function. Traverse BST inorder will give data in sorted order
	void inorder(BST* root)
	{
		if (root->isEmpty())
			return;
		inorder(root->fLeft);
		cout << root->fValue << " ";
		inorder(root->fRight);
	}

	// Find the smallest node in the right subtree
	BST* getSmallestNode(BST* aNode)
	{
		BST* current = aNode;
		/* loop down to find the leftmost leaf */
		while (!current->isEmpty() && !current->fLeft->isEmpty())
			current = current->fLeft;

		return current;
	}

	// Delete a node has same value with key, and returns a new root
	BST* deleteNode(BST* root, int key)
	{
		// If this tree is empty, we cannot delete anything
		if (root->isEmpty())
			return root;

		// First, we need to find the node to be deleted
		// If the key to be deleted is smaller than the root's key, then it is in the left subtree
		if (key < root->getValue())			
			root->fLeft = deleteNode(root->fLeft, key);
		// If the key to be deleted is greater than the root's key, then it is in the right subtree
		else if (key > root->getValue())
			root->fRight = deleteNode(root->fRight, key);
		// If this node is the node to be deleted
		else
		{
			/*There are 3 cases:
			  - deleted node is leaf: just simply remove the node
			  - deleted node has only 1 child: make connection between grandparent and child, delete the parent node.
			  - deleted node has 2 children: find the smallest node on the right side and replace it to the deleted node.
			 */

			// Node with 1 child or 2 children
			if (root->fLeft->isEmpty())		// No left child
			{
				BST* temp = root->fRight;
				delete root;
				return temp;
			}
			else if (root->fRight->isEmpty())	// No right child
			{
				BST* temp = root->fLeft;
				delete root;
				return temp;
			}

			// Node with 2 children
			// Get the smallest node on the right subtree
			BST* temp = getSmallestNode(root->fRight);
			// Replace it with the root node
			root->fValue = temp->fValue;
			// Delete the replaced node
			root->fRight = deleteNode(root->fRight, temp->fValue);
		}

		return root;
	}
};
//Sentinel 
BST BST::NIL;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// Build a BST
	BST tree = BST::NIL;
	BST* root = &BST::NIL;
	root = tree.insert(root, arr[0]);
	for (int i = 1; i < n; i++)
		tree.insert(root, arr[i]);

	// Display nodes
	tree.inorder(root);
	cout << endl;

	// Delete node
	int x;
	cout << "Value you want to delete: ";
	cin >> x;
	root = tree.deleteNode(root, x);
	cout << "Inorder traversal of the modified tree: " << endl;
	tree.inorder(root);

	return 0;
}