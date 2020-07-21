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

//Merge arr[left..mid] and arr[mid+1..right]
void merge(int arr[], int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	/* create temp arrays */
	int L[MAX / 2 + 1], R[MAX / 2 + 1];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = left; // Initial index of merged subarray 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	
}

void mergeSort(int arr[], int left, int right)
{
	if (left < right) {
		// Get middle index 
		int mid = (left + right) / 2;

		// Sort first and second halves 
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		// Merge 2 halves
		merge(arr, left, mid, right);
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

	mergeSort(arr, 0, n - 1);		//Sort

	cout << "Sorted array: ";		//Display output
	print(arr, n);
	return 0;
}