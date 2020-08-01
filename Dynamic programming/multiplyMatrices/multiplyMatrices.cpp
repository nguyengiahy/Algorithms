#include<iostream>
using namespace std;

int n;
int m[101], F[100][100];

void input()
{
	cin >> n;
	/*for (int i = 0; i <= n; i++)
		cin >> m[i];*/
	for (int i = 1; i <= n + 1; i++)
		cin >> m[i];
}

int min(int a, int b)
{
	if (a < b) return a;
	else return b;
}

void solve()
{
	/*for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)
				F[i][i] = 0;
			else
				F[i][j] = 9999;
	for (int i = 0; i < n - 1; i++)
		F[i][i + 1] = m[i] * m[i + 1] * m[i + 2];
	for (int i = 0; i < n - 1; i++)
		for (int j = i+1; j < n; j++)
		{
			for (int k = i; k < j; k++)
				F[i][j] = min(F[i][j], F[i][k] + F[k + 1][j] + m[i] * m[k + 1] * m[j + 1]);
		}
	*/


	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
		{
			if (i == j)
				F[i][i] = 0;
			else F[i][j] = 9999;
		}
	for (int len = 2; len <= n; len++)
	{
		for (int i = 1; i <= n - len + 1; i++)
		{
			int j = i + len - 1;
			for (int k = i; k <= j - 1; k++)
				F[i][j] = min(F[i][j], F[i][k] + F[k + 1][j] + m[i] * m[k + 1] * m[j + 1]);
		}
	}
}

void output()
{
	//cout << F[0][n - 1];
	cout << F[1][n];
}

int main()
{
	input();
	solve();
	output();
	return 0;
}