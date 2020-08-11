#include<iostream>
using namespace std;

bool a[100][100];
bool visited[100];
int n;

void input()
{
	// Initialisation
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = false;

	// Get input
	int m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u][v] = true;
		a[v][u] = true;
	}
}

void visit(int u)
{
	visited[u] = true;		// Mark u
	for (int v = 1; v <= n; v++)
	{
		if (!visited[v] && a[u][v])		// If v hasn't been visited and there is an edge between u,v
		{
			cout << "(" << u << "," << v << ")" << endl;
			visit(v);
		}
	}
}

void solve()
{
	cout << "Edges of the spanning tree:" << endl;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])	// If i hasn't been visited
			visit(i);
	}
}

int main()
{
	input();
	solve();
	return 0;
}