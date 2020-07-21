#include <iostream>
#include <random>
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

void quickSort(int left, int right)
{
	if (left >= right)			// If this list contains <= 1 element, do nothing
		return;
	random_device rd;			// obtain a random number from hardware
	mt19937 gen(rd());			// seed the generator
	uniform_int_distribution<> distr(left, right); // define the range for random
	int i = left; int j = right;
	int pivot = arr[distr(gen)];// get pivot as a random value in between left and right

	while (i <= j)
	{
		while (arr[i] <= pivot) i++;		// find element on the left side which is greater than pivot
		while (arr[j] >= pivot) j--;		// find element on the right side which is smaller than pivot
		if (i <= j)
		{
			if (i < j)
				swap(arr[i], arr[j]);		// swap 2 elements
			i++; j--;
		}
	}

	quickSort(left, j);
	quickSort(i, right);
}

int main()
{
	cin >> n;						//Get input
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "Original array: ";		//Display input
	print(arr, n);

	quickSort(0, n-1);				//Sort

	cout << "Sorted array: ";		//Display output
	print(arr, n);					
	return 0;
}