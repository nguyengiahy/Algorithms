#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include<iostream>

using namespace std;

template<class T>
class BT
{
private:
	T fKey;
	BT<T> *fLeft;
	BT<T> *fRight;

	// Sentinel constructor:
	BT() :fKey(T())
	{
		fLeft = &NIL;
		fRight = &NIL;
	}
public:
	static BT<T> NIL;

	BT(const T& aKey) :fKey(T())
	{
		fLeft = &NIL;
		fRight = &NIL;
	}

	// Destructor
	virtual ~BT()
	{
		if (fLeft != &NIL)
			delete fLeft;
		if (fRight != &NIL)
			delete fRight;
	}
	bool isEmpty() const
	{
		return this == &NIL;
	}
	// insert into tree
      void insert(T X)
      {
            BT<T> *root = this;
            BT<T> *p = &NIL;
            BT<T> *q;
            while (p != &NIL)
            {
                  q =p;
                  if (X == fKey)
                  {
                        break;
                        // it means p is a NIL
                  }
                  else
                  {
                        if (X < fKey)
                        {
                              p = fLeft;
                        }
                        else
                        {
                              p = fRight;
                        }
                        
                  }
            }
            if (p == &NIL)
            {
                  BT<T>* newNode = new BT<T>(X);
                  if (root == &NIL)
                  {
                        this = newNode;
                  } 
                  else
                  {
                        if (X < q->fKey)
                        {
                              q->fLeft = newNode;
                        }
                        else
                        {
                              q->fRight = newNode;
                        }
                        
                  }
                  
            }

      }

};

template<class T> 
BT<T> BT<T>::NIL;

int main()
{
	int n;
	cout << "Please enter the number of node in the tree: " << endl;
	cin >> n;

	typedef BT<int> BTree;
	int A1(4);
	BTree* A = new BTree(A1);

	
	return 0;
}