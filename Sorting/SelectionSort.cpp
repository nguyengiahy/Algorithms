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

void selectionSort(int arr[], int n)	//pass array by reference
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
				swap(arr[j], arr[i]);
		}
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
	selectionSort(arr, n);
	return 0;
}