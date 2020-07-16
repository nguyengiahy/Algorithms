#include <iostream>
using namespace std;

int n;
int x[100];		//Store the result
int sum[100];	//Store the current sum at a given index

void print(int index)
{
	for (int i = 0; i <= index; i++)
		cout << x[i];
	cout << endl;
}

void attempt(int index)
{
	int start, end;
	index == 0 ? start = 1 : start = x[index - 1];
	index == 0 ? end = n : end = n - sum[index - 1];
	for (int i = start; i <= end; i++)
	{
		x[index] = i;
		sum[index] = sum[index - 1] + x[index];
		if (sum[index] == n)
		{
			print(index);
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