#include<iostream>
using namespace std;

string st1, st2;
int n, m, l[1000][1000];

void input()
{
	cin >> st1 >> st2;
	// Initialisation
	n = st1.length();
	m = st2.length();
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			l[i][j] = 0;
}

int max(int a, int b)
{
	if (a > b) return a;
	return b;
}

void solve()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (st1[i - 1] == st2[j - 1])
				l[i][j] = l[i - 1][j - 1] + 1;
			else
				l[i][j] = max(l[i - 1][j], l[i][j - 1]);
		}
}

void output()
{
	cout << l[n][m];
}

int main()
{
	input();
	solve();
	output();
	return 0;
}