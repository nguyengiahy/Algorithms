#include <iostream>
using namespace std;

int n, k;
int arr[100];

void print()
{
	for (int i = 0; i < k; i++)
	{
		cout << arr[i];
	}
}

void attempt(int index)
{
	int start;
	index == 0 ? start = 1 : start = arr[index - 1] + 1;

	for (int i = start; i <= n - k + index + 1; i++)
	{
		arr[index] = i;
		if (index == k - 1)
		{
			print();
			cout << endl;
		}
		else
		{
			attempt(index + 1);
		}
	}
}

int main()
{
	cin >> n >> k;
	attempt(0);
	return 0;
}