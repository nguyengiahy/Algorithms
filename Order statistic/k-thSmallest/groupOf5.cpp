//Time complexity: O(n) in worst case

#include<iostream>
using namespace std;

const int MAX = 1000;
int arr[MAX] = { 0 };

void insertionSort(int left, int right)
{
	for (int i = 2; i <= right; i++)
	{
		int j = i - 1;
		int key = arr[i];
		while (j >= 1 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

//Select function: return the k-th smallest element in an array ranges from left to right
int select(int left, int right, int k)
{
	//If number of elements < 50 then sort the array with insertion sort and return arr[k]
	if (right - left + 1 < 50)
	{
		insertionSort(left, right);
		return arr[k];
	}

	//If number of elements > 50
	//First, find median of groups of 5
	//Second, push those medians to the top of array
	int j = left - 1;
	int i = left;
	while (i + 4 <= right)
	{
		insertionSort(i, i + 4);		//sort a group of 5 elements
		j++;							
		swap(arr[i + 2], arr[j]);		//arr[i+2] is the median of a group of 5 elements (i..i+4), hence swap it to the front
		i += 5;							//move to next group of 5
	}

	//Now we have all median of groups of 5 at the front. We need to find the pivot, which is median of those medians.
	int pivot = select(left, j, (j - left + 1) / 2);

	//Now start counting number of elements that is smaller than pivot, number of elements that is equal to the pivot
	int countLess = 0, countEqual = 0;
	for (int i = left; i <= right; i++)
		if (arr[i] < pivot)
			countLess++;
		else if (arr[i] == pivot)
			countEqual++;

	if (countLess < k && k <= countLess + countEqual)	//if pivot is the element we are looking for
		return pivot;
	if (k <= countLess)		//if the element we are looking for is on the left side of the pivot
	{
		//Move all elements smaller than pivot to the front
		j = left - 1;
		for (int i=left;i<=right;i++)
			if (arr[i] < pivot)
			{
				j++;
				swap(arr[j], arr[i]);
			}

		//Now all smaller elements are at the front, we need to call select again
		return select(left, j, k);
	}
	else					//if the element we are looking for is on the right side of the pivot
	{
		//Move all elements greater than pivot to the front
		j = left - 1;
		for (int i = left; i <= right; i++)
			if (arr[i] > pivot)
			{
				j++;
				swap(arr[j], arr[i]);
			}

		//Now all greater elements are at the front, we need to call select again
		return select(left, j, k - countLess - countEqual);
	}
}

int main()
{
	int n, k;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cin >> k;

	cout << select(1,n,k);

	return 0;
}