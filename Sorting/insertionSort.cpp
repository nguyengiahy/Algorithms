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

void insertionSort(int arr[], int n)	//pass array by reference
{
	for (int i = 1; i < n; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && temp < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
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
	insertionSort(arr, n);
	return 0;
}