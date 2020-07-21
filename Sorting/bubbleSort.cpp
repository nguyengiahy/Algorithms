#include <iostream>
using namespace std;

const int MAX = 1000;
int n;
int arr[MAX];

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int arr[], int n)	//pass array by reference
{
	for (int i = 1; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
	}

	cout << "Sorted array: ";
	print(arr, n);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "Original array: ";
	print(arr, n);
	bubbleSort(arr, n);
	return 0;
}