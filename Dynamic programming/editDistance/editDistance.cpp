// Also known as string conversion problem
#include <iostream>
#include <string>
using namespace std;

string st1, st2;
int L[100][100];

void input()
{
	cin >> st1 >> st2;
}

int min(int a, int b, int c)
{
	int res = a;
	if (b < res)
		res = b;
	if (c < res)
		res = c;
	return res;
}

void solve()
{
	// L[i][j] is the minimum operations required to convert st1[1..i] to st2[1..j]
	int n = st1.length();
	int m = st2.length();
	// Initialise
	for (int i = 0; i <= n; i++)
		L[i][0] = i;
	for (int j = 0; j <= m; j++)
		L[0][j] = j;

	// Dynamic programming 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (st1[i - 1] == st2[j - 1])	
				L[i][j] = L[i - 1][j - 1];
			else
				L[i][j] = min(L[i - 1][j], L[i][j - 1], L[i - 1][j - 1]) + 1;
		}
	}
}

void trace()
{
	int i = st1.length();
	int j = st2.length();
	while (i > 0 && j > 0)
	{
		if (st1[i - 1] == st2[j - 1])
		{
			i--;
			j--;
		}
		else if (L[i][j] == L[i - 1][j] + 1)
		{
			cout << "Delete(" << i << ")" << endl;
			i--;
		}
		else if (L[i][j] == L[i][j - 1] + 1)
		{
			cout << "Insert(" << i << ", " << st2[j - 1] << ")" << endl;
			j--;
		}
		else
		{
			cout << "Replace(" << i << ", " << st2[j - 1] << ")" << endl;
			i--; j--;
		}
	}
}

void output()
{
	// Minimum number of operations to convert string 1 to string 2
	cout << L[st1.length()][st2.length()] << endl;

	// Trace for operation
	trace();
}

int main()
{
	input();
	solve();
	output();
	return 0;
}