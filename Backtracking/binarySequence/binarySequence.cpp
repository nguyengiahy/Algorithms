#include<iostream>
using namespace std;

int n;
int arr[100];

void print()
{
	for (int i = 0; i < n; i++)
		cout << arr[i];
}

void attempt(int index)
{
	for (int i = 0; i < 2; i++)
	{
		arr[index] = i;
		if (index == n-1)
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
	cin >> n;
	attempt(0);
	return 0;
}