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

//Find the maximum number in array to define number of digits we need to sort
int findMax(int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void radixSort(int exp, int n)
{
	int count[10] = { 0 };					//array to count occurrences
	int result[MAX];						//result array

	for (int i = 0; i < n; i++)
	{
		int digit = (arr[i] / exp) % 10;	//get the digit value
		count[digit]++;
	}

	for (int i = 1; i < 10; i++)
		count[i] = count[i - 1] + count[i];

	//Sorted
	for (int i = n-1; i >= 0; i--)
	{
		int digit = (arr[i] / exp) % 10;
		result[count[digit] - 1] = arr[i];
		count[digit]--;
	}

	//Copy result array to original array
	for (int i = 0; i < n; i++)
	{
		arr[i] = result[i];
	}
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

	int max = findMax(n);			//Find the maximum number in array to define number of digits we need to sort
	//Sort each digit, passing exp which is 10^i where i is the digit position
	for (int exp = 1; max / exp > 0; exp *= 10)	
	{
		radixSort(exp, n);			
	}

	cout << "Sorted array: ";		//Display output
	print(arr, n);
	return 0;
}