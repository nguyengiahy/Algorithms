#include<iostream>
using namespace std;

int main()
{
	int n;
	int res[101][101];	// res[m][v] is the number of ways to split v to sum of integers that are <= m.
	cin >> n;

	for (int i = 1; i <= n; i++)
		res[0][i] = 0;	

	res[0][0] = 1;		// 0 = 0 is considered as 1 way.
	for (int m = 1; m <= n; m++)
		for (int v = 0; v <= n; v++)
		{
			if (m > v)
				res[m][v] = res[m - 1][v];
			else
				res[m][v] = res[m - 1][v] + res[m][v - m];
		}
	cout << res[n][n];

	return 0;
}