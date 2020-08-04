#include<iostream>
using namespace std;

int n, m;			// n: number of vertices, m: number of edges
bool a[100][100];	// adjacent matrix for storing the graph
bool visited[100];	// checking if a vertice has been visited or not

// Get input
void input()
{
	cin >> n >> m;
	// Initialise the adjacent matrix
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
				a[i][j] = false;
			else
				a[i][j] = true;
		}
	}
	// Initialise visited
	for (int i = 1; i <= n; i++)
		visited[i] = false;

	// Get input
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u][v] = a[v][u] = true;
	}
}

void Warshall()
{
	// Warshall algorithm
	for (int k = 1; k <= n; k++)
		for (int u = 1; u <= n; u++)
			for (int v = 1; v <= n; v++)
				if (a[u][k] && a[k][v])
					a[u][v] = true;

	// Print all connected components
	int count = 0;		// Number of connected components
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			count++;
			cout << "Connected component " << count << ":" << endl;
			for (int j = 1; j <= n; j++)
				if (a[i][j])
				{
					cout << j << ", ";
					visited[j] = true;
				}
			cout << endl;
		}
	}
}

int main()
{
	input();
	Warshall();
	return 0;
}