#include <iostream>
using namespace std;

int n, k;
int arr[100];
bool check[100];

void init()
{
	for (int i = 0; i < n; i++)
	{
		check[i + 1] = false;
	}
}

void print()
{
	for (int i = 0; i < k; i++)
	{
		cout << arr[i];
	}
}

void attempt(int index)
{
	for (int i = 1; i <= n; i++)
	{
		if (!check[i])
		{
			arr[index] = i;
			if (index == k - 1)
			{
				print();
				cout << endl;
			}
			else
			{
				check[i] = true;
				attempt(index + 1);
				check[i] = false;
			}
		}
	}
}

int main()
{
	cin >> n >> k;
	init();
	attempt(0);
	return 0;
}