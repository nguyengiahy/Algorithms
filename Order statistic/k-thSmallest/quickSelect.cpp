/*Time complexity:	worst case: O(n^2)
					average: O(n)		*/

#include<iostream>
#include<random>
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

int quickSelect(int left, int right, int k)
{
	int i = left;
	int j = right;
	random_device rd;				// obtain a random number from hardware
	mt19937 gen(rd());				// seed the generator
	uniform_int_distribution<> distr(left, right); // define the range for random
	int pivot = distr(gen);			// get pivot as a random value in between left and right

	while (i <= j)
	{
		while (arr[i] < arr[pivot]) i++;
		while (arr[j] > arr[pivot]) j--;
		if (i <= j)
		{
			if (i < j)
				swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	if (k - 1 <= j)
		quickSelect(left, j, k);
	else if (k - 1 >= i)
		quickSelect(i, right, k);
	else
		return arr[pivot];
}

int main()
{
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> k;

	cout << quickSelect(0, n - 1, k);
	
	return 0;
}