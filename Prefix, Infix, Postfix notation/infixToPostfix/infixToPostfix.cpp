#include <iostream>
#include <string>
using namespace std;

//Class node
class Node
{
private:
	char fValue;
	Node* fNext;
	Node()							//Constructor for sentinel
	{
		fValue = char();
		fNext = &NIL;
	}
public:
	static Node NIL;				//Sentinel declaration

	Node(const char& aValue)		//Constructor with a given value
	{
		fValue = aValue;
		fNext = &NIL;
	}

	const char& getValue() const	//Return node's value
	{
		return fValue;
	}

	Node* getNext() const			//Return next node
	{
		return fNext;
	}

	void setNext(Node* aNode)		//Adjust next node
	{
		fNext = aNode;
	}
};
//Sentinel
Node Node::NIL;

//Class stack
class Stack
{
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
	void push(const char& aItem)		//Push a given item into stack
	{
		Node* temp = new Node(aItem);
		temp->setNext(fTop);
		fTop = temp;
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
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
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

//Defining priority of each operation
int priority(char c)
{
	int result = 0;
	switch (c)
	{
	case '(':
		result = 0;
		break;
	case '*':
	case '/':
		result = 2;
		break;
	case '+':
	case '-':
		result = 1;
		break;
	}
	return result;
}

void infixToPostfix(Stack* stack, string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '(')		//If this is '(', just push it to stack
		{
			stack->push(input[i]);
		}
		else if (input[i] == ')')	//If this is ')', pop and print the value until it meets '('. Then pop '('
		{
			while (stack->top()->getValue() != '(')
			{
				cout << stack->pop()->getValue();
			}
			stack->pop();
		}
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')	//If this is operations, compare the priority with top first, 
																							//only push it in stack when it has higher priority than that of top.
		{
			while (!stack->isEmpty() && priority(input[i]) <= priority(stack->top()->getValue()))
			{
				cout << stack->pop()->getValue();
			}
			stack->push(input[i]);
		}
		else		//If this is number, just print it out.
		{
			cout << input[i];
		}
	}

	while (!stack->isEmpty())		//Print all the remaining operations in stack.
	{
		cout << stack->pop()->getValue();
	}
}

int main()
{
	string input;
	getline(cin, input);				//get input
	refine(input);						//refine input
	Stack* stack = new Stack();
	infixToPostfix(stack, input);		//convert from infix notation to postfix notation
	return 0; 
}