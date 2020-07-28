// Time complexity: O(N.M) with N is the number of items, M is the maximum capacity of the knapsack
#include <iostream>
using namespace std;

int n, m;
int W[100], V[100];
int L[100][100];

void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> W[i] >> V[i];
}

int max(int a, int b)
{
	if (a >= b) return a;
	return b;
}

void solve()
{
	// L[i][j] is the maximum value we can get when choosing item 1,2, ..,i and the maximum capacity is j.
	for (int i = 0; i <= m; i++)
		L[0][i] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (W[i] > j)
				L[i][j] = L[i - 1][j];
			else
				L[i][j] = max(L[i - 1][j], L[i - 1][j - W[i]] + V[i]);
		}
	}
}

void output()
{
	cout << L[n][m] << endl;	// Maximum value we can get
	
	// Trace the items
	int i = n, j = m;
	while (i > 0)
	{
		if (L[i][j] == L[i - 1][j])		// Item i is not in the knapsack
			i--;
		else							// Item i is in the knapsack
		{
			cout << i << " ";
			j -= W[i];
			i--;
		}
	}
}

int main()
{
	input();
	solve();
	output();
	return 0;
}