#include <iostream>
#include <string>
using namespace std;

//Class Node for both stack item and tree item
class Node {
private:
	string fValue;
	Node* fNext;
	Node* fLeft;
	Node* fRight;
	Node()							//Constructor for sentinel
	{
		fValue = string();
		fNext = &NIL;
		fLeft = &NIL;
		fRight = &NIL;
	}
public:
	static Node NIL;

	Node(const string& aValue)		//Constructor with a given value
	{
		fValue = aValue;
		fNext = &NIL;
		fLeft = &NIL;
		fRight = &NIL;
	}
	const string& getValue() const	//Return node's value
	{
		return fValue;
	}
	Node* getNext() const			//Return next node
	{
		return fNext;
	}
	Node* getLeft() const			//Return left node
	{
		return fLeft;
	}
	Node* getRight() const			//Return right node
	{
		return fRight;
	}
	void setNext(Node* aNode)		//Adjust next node
	{
		fNext = aNode;
	}
	void setLeft(Node* aNode)		//Adjust left node
	{
		fLeft = aNode;
	}
	void setRight(Node* aNode)		//Adjust right node
	{
		fRight = aNode;
	}
};
//Sentinel
Node Node::NIL;


//Class stack
class Stack {
private:
	Node* fTop;
public:
	Stack()								//Constructor
	{
		fTop = &Node::NIL;
	}
	bool isEmpty() const				//Check if stack is empty
	{
		return fTop == &Node::NIL;
	}
	void push(Node* aNode)				//Push a given node into stack
	{
		//Node* temp = new Node(aItem);
		aNode->setNext(fTop);
		fTop = aNode;
	}
	Node* pop()							//Pop the top item from the stack
	{
		Node* temp = fTop;
		fTop = fTop->getNext();
		return temp;
	}
	Node* top()							//Return the top node
	{
		return fTop;
	}
};

//Check if charactor c is an operator
bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

//Adding spaces between input elements to make it easier for later processes
void refine(string& s)
{
	s += ' ';		//add an extra space at the end
	for (int i = 0; i < s.length() - 1; i++)
	{
		if (isOperator(s[i]) || isOperator(s[i + 1]))	//if this is an operator, or the next character is an operator
		{
			s.insert(i + 1, " ");					//add space into the position
			i++;
		}
	}

	for (int i = 0; i < s.length() - 1; i++)	//Deleting excess spaces
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			s.erase(s.begin() + i);
		}
	}
}

void reconstructTree(Stack* stack, string input)
{
	string temp = "";
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] != ' ')		//if this is not a space, we add it up to the temporary string
			temp += input[i];
		else						//if this is space, we process the temporary string
		{
			if (temp == "+" || temp == "-" || temp == "*" || temp == "/")	//if the temporary string is an operation
			{
				//Pop 2 nodes first
				Node* right = stack->pop();
				Node* left = stack->pop();
				//Create a node to store current item
				Node* current = new Node(temp);

				//Set left and right node for current node
				current->setLeft(left);
				current->setRight(right);

				//Push the current node to stack
				stack->push(current);
			}
			else	//if the temporary string is number
			{
				Node* current = new Node(temp);		//create node to store this number
				stack->push(current);				//push the node to stack
			}
			temp = "";
		}
	}

	Node* root = stack->pop();
	cout << "Root of the tree is: " << root->getValue() << endl;
	cout << "Left child is: " << root->getLeft()->getValue() << endl;
	cout << "Right child is: " << root->getRight()->getValue() << endl;
}

int main()
{
	string input;
	getline(cin, input);			//get input
	refine(input);					//refine input
	cout << input << endl;
	Stack* stack = new Stack();
	reconstructTree(stack, input);		//reconstruct binary tree from given PRN
	return 0;
}