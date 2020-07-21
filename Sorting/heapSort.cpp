#include <iostream>
#include <random>
using namespace std;

const int MAX = 1000;
int n;
int arr[MAX];

//Print out the array's elements
void print(int arr[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//Swap 2 elements
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//Heapify a tree with root r
void heapify(int r, int n)
{
	int key = arr[r];										//Store root's value
	while (2 * r <= n)										//When i is not leave nodes
	{
		int child = 2 * r;									//Get the left child node
		if (child + 1 <= n && arr[child + 1] > arr[child])	//If right child exists and right child > left child
			child++;
		if (arr[child] <= key)								//If child node < root node then stop
			break;
		arr[r] = arr[child];								
		r = child;
	}
	arr[r] = key;											//Place root's value in a correct position
}

void heapSort()
{
	//Heapify the original array from bottom-up
	for (int i = n/2; i >= 1; i--)
		heapify(i, n);

	//Heap sort
	for (int i = n; i >= 2; i--)
	{
		swap(arr[i], arr[1]);
		heapify(1, i - 1);
	}
}

int main()
{
	cin >> n;						//Get input
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	cout << "Original array: ";		//Display input
	print(arr, n);

	heapSort();						//Sort

	cout << "Sorted array: ";		//Display output
	print(arr, n);
	return 0;
}