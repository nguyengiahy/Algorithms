//Time complexity: O( k + (n-k)Logk )

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
	while (2 * root <= n)
	{
		int child = 2 * root;
		if (child + 1 <= n && arr[child + 1] > arr[child])
			child++;
		if (arr[child] <= key)
			break;
		arr[root] = arr[child];
		root = child;
	}
	arr[root] = key;
}

int main()
{
	int n, k;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cin >> k;

	//Build a max heap of the first k elements
	for (int i = k / 2; i >= 1; i--)
		heapify(i, n);


	//From arr[k+1..n], if a[i] < root of max heap then make it root and call heapify.
	for (int i = k + 1; i <= n; i++)
	{
		if (arr[i] < arr[1])
		{
			swap(arr[1], arr[i]);
			heapify(1, k);
		}
	}

	cout << arr[1];		//Get the result

	return 0;
}