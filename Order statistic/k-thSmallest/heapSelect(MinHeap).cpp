//Time complexity: O( n + k.Logn )

#include<iostream>
using namespace std;

const int MAX = 1000;
int arr[MAX] = { 0 };

//Swap 2 elements
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void heapify(int root, int n)
{
	int key = arr[root];
	while (2 * root <= n)	//while haven't reached leaves yet
	{
		int child = 2 * root;
		if (child + 1 <= n && arr[child + 1] < arr[child])		//find the smaller node in 2 children nodes
			child++;
		if (arr[child] >= key)		//if child's value is greater than initial root's value then stop
			break;
		arr[root] = arr[child];		
		root = child;
	}
	arr[root] = key;				//Place root's value in a correct position
}

int main()
{
	int n, k;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cin >> k;

	//Make the array a min heap
	for (int i = n / 2; i >= 1; i--)
		heapify(i, n);

	//Find the k-th smallest node by deleting the min heap root k-1 times
	for (int i = 0; i < k-1; i++)
	{
		swap(arr[1], arr[n - i]);
		heapify(1, n - i - 1);		
	}
	cout << arr[1];		//Get the root node of min heap

	return 0;
}