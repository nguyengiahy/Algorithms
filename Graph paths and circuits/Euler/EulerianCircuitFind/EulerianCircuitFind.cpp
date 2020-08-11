#include<iostream>
using namespace std;

int a[100][100];
int n;

void input()
{
	// Initialisation
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = 0;

	// Get input
	int m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, k;
		cin >> u >> v >> k;
		a[u][v] = k;
		a[v][u] = k;
	}
}

void DFS(int u)
{
	for (int v = 1; v <= n; v++)
	{
		if (a[u][v] > 0)
		{
			a[u][v]--; a[v][u]--;		// Eliminate the edge
			cout << v << " ";
			DFS(v);
			break;
		}
	}
}

int main()
{
	input();
	cout << 1 << " ";
	DFS(1);
	return 0;
}