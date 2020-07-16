#include <iostream>
#include <string>
using namespace std;

//Class Node
class Node {
private:
	int fValue;
	Node* fNext;
	Node()							//Constructor for sentinel
	{
		fValue = int();
		fNext = &NIL;
	}
public:
	static Node NIL;

	Node(const int& aValue)		//Constructor with a given value
	{
		fValue = aValue;
		fNext = &NIL;
	}
	const int& getValue() const	//Return node's value
	{
		return fValue;
	}
	Node* getNext() const		//Return next node
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
	void push(const int& aItem)		//Push a given item into stack
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
		if (isOperator(s[i]) || isOperator(s[i+1]))	//if this is an operator, or the next character is an operator
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

//Convert a string into an integer
int convertToInt(string a)
{
	int result = 0;
	for (int i = 0; i < a.length(); i++)
	{
		int temp = (int)a[i] - 48;
		result = result * 10 + temp;
	}
	return result;
}

//Calculate the value from a given PRN
void calculatePRN(Stack* stack, string input)
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
				//Pop 2 values from the stack, apply the operation on them then push the result back to the stack.
				int x = stack->pop()->getValue();
				int y = stack->pop()->getValue();
				int result = 0;
				if (temp == "+")
					result = y + x;
				else if (temp == "-")
					result = y - x;
				else if (temp == "*")
					result = y * x;
				else 
					result = y / x;
				stack->push(result);
			}
			else			//if the temporary string is a number, push it to the stack
			{
				int number = convertToInt(temp);
				stack->push(number);
			}
			temp = "";
		}
	}
	cout << stack->pop()->getValue();		//the final result
}

int main()
{
	string input;
	getline(cin, input);			//get input
	refine(input);					//refine input
	Stack* stack = new Stack();
	calculatePRN(stack, input);		//calculate the result from the input
	return 0;
}