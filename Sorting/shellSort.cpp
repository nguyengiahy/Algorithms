#include <iostream>
using namespace std;

const int MAX = 1000;
int n;
int arr[MAX];

//Print out the array's elements
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
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

void shellSort(int arr[], int n)	
{
	int h = 1;	//h is distance between each item in a subset
	while (h <= n / 3)		//formula to find the best h to start with
		h = h * 3 + 1;

	while (h > 0)
	{
		//Swap 2 elements that are seperated by h-length
		for (int i = h; i < n; i++)
		{
			int temp = arr[i];
			int j = i;
			while (arr[j - h] > temp && j >= h )
			{
				arr[j] = arr[j - h];
				j -= h;
			}
			arr[j] = temp;
		}
		//Find the next h
		h = (h - 1) / 3;
	}

	//Print result
	cout << "Sorted array: ";
	print(arr, n);
}

int main()
{
	cin >> n;		//Get input
	for (int i = 0; i < n; i++)		
	{
		cin >> arr[i];
	}
	cout << "Original array: ";		//Display input
	print(arr, n);
	shellSort(arr, n);		//Sort
	return 0;
}