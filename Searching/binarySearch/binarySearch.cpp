#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000;
int arr[MAX] = { 0 };

// A recursive binary search function. It returns 
// location of x in given array arr[left..right] is present, 
// otherwise -1
int binarySearch(int left, int right, int key)
{
	// If element is not found, return -1
	if (left > right)
	{
		return -1;
	}
	else
	{
		int mid = (left + right) / 2;
		// If the element is present at the middle
		if (arr[mid] == key)
			return mid;

		// If element is smaller than mid, then call recursion for left subarray
		else if (key < arr[mid])
			return binarySearch(left, mid - 1, key);

		// If element is greater than mid, then call recursion for right subarray
		else
			return binarySearch(mid + 1, right, key);
	}
}

int main()
{
	int n, key;
	// Read input
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> key;

	// Sort is required before performing binary search
	sort(arr, arr + n);	
	cout << "Sorted array:" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	// Call binary search to find index of key in the array
	int index = binarySearch(0, n - 1, key);

	cout << index;

	return 0;
}