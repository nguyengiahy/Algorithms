#include <iostream>
using namespace std;

bool a[100][100];
int Parent[100], Number[100], Low[100];
int n, ordinalNum;

void input()
{
	int m;
	cin >> n >> m;

	// Initialisation
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = false;
	for (int i = 1; i <= n; i++)
	{
		Parent[i] = 0;
		Number[i] = 0;
		Low[i] = 0;
	}

	// Get input
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u][v] = true;
		a[v][u] = true;
	}
}

int min(int a, int b)
{
	if (a < b) return a;
	else return b;
}

void Visit(int u)
{
	Number[u] = ++ordinalNum;		// Mark u
	Low[u] = n + 1;					// Initialise low-link value
	for (int v = 1; v <= n; v++)
	{
		if (a[u][v])
		{
			a[v][u] = false;		// Delete the reverse direction
			if (Parent[v] != 0)		// If v is visited already => (u,v) is a backward edge
				Low[u] = min(Low[u], Number[v]);
			else
			{
				Parent[v] = u;
				Visit(v);
				Low[u] = min(Low[u], Low[v]);
			}
		}
	}
}

void solve()
{
	ordinalNum = 0;
	for (int i = 1; i <= n; i++)
		if (Parent[i] == 0)
		{
			Parent[i] = -1;		// Mark u as a DFS tree root
			Visit(i);
		}
}

void output()
{
	int nChildren[100] = { 0 };			// nChildren[i] = Number of children of vertex i
	for (int i = 1; i <= n; i++)
		if (Parent[i] != -1)			// If i is not a DFS tree root
			nChildren[Parent[i]]++;

	// Find bridges: if (u,v) is a bridge then Low[v] >= Number[v]
	cout << "Bridges:" << endl;
	for (int v = 1; v <= n; v++)
	{
		int u = Parent[v];
		if (u != -1 && Low[v] >= Number[v])
			cout << "(" << u << "," << v << ")" << endl;
	}

	// Find cut vertices: considering edge (u,v), if Low[v] >= Number[u] then u is a cut vertex if either u is not a root of DFS tree or u has more than 2 children.
	bool isCut[100] = { false };
	cout << "Cut vertices:" << endl;
	for (int v = 1; v <= n; v++)
	{
		int u = Parent[v];
		if (u != -1 && Low[v] >= Number[u])
			isCut[u] = isCut[u] || Parent[u] != -1 || nChildren[u] >= 2;
	}
	for (int i = 1; i <= n; i++)
		if (isCut[i])
			cout << i << endl;
}

int main()
{
	input();
	solve();
	output();
	return 0;
}