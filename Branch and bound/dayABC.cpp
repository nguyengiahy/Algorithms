#include <iostream>
using namespace std;

int n, bestConfig;
int x[100], countC[100], res[100];

//This check if a string has len length, ended at x[i] is identical to a previous substring of the same length
bool same(int i, int len)
{
	for (int k = 0; k < len; k++)
	{
		if (x[i - k] != x[i - len - k])
			return false;
	}
	return true;
}

//This check if x[i] break the rule of no 2 adjacent substrings are identical
bool check(int i)
{
	for (int k = 1; k <= i / 2; k++)
	{
		if (same(i, k))		//if 2 substrings are identical, then false
			return false;
	}
	return true;
}

void getResult()
{
	for (int i = 1; i <= n; i++)
	{
		res[i] = x[i];
	}
	bestConfig = countC[n];
}

void attempt(int i)
{
	//Assume A,B,C is 1,2,3.
	for (int j = 1; j <= 3; j++)
	{
		x[i] = j;
		if (check(i))		//If x[i] does not break the rule
		{
			if (j == 3)
				countC[i] = countC[i - 1] + 1;
			else
				countC[i] = countC[i - 1];
			if ((countC[i] + (n - i) / 4) < bestConfig)
			{
				if (i == n && countC[i] < bestConfig)
					getResult();
				else
					attempt(i + 1);
			}
		}
	}
}

void print()
{
	for (int i = 1; i <= n; i++)
	{
		if (res[i] == 1)
			cout << 'A';
		else if (res[i] == 2)
			cout << 'B';
		else
			cout << 'C';
	}
	cout << endl << "Number of C: " << bestConfig;
}

int main()
{
	cin >> n;
	bestConfig = n;
	attempt(1);
	print();
	return 0;
}