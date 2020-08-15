#include<iostream>
using namespace std;

bool a[100][100];
bool visited[100];
int result[100], n;

void input()
{
	int m;
	cin >> n >> m;

	// Initilisation
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = false;
	for (int i = 1; i <= n; i++)
		visited[i] = false;

	// Get input
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u][v] = true;
		a[v][u] = true;
	}
}

void printResult()
{
	for (int i = 1; i <= n; i++)
		cout << result[i] << " ";
	cout << result[1] << endl;
}

void attempt(int i)		// Try to find the i-th vertex in Hamilton circuit
{
	for (int j = 1; j <= n; j++)
	{
		if (a[result[i - 1]][j] && !visited[j])		// If j hasn't been visited and there is a path to j
		{
			result[i] = j;		// Try j to be the i-th vertex
			if (i == n)			// If we have reached to result[n]
			{
				if (a[result[i]][1])
					printResult();
			}
			else
			{
				visited[j] = true;		// Mark j
				attempt(i + 1);			// So that later attempts won't try with j again
				visited[j] = false;		// Try another vertex for result[i] therefore we have to unmark j
			}
		}
	}
}

int main()
{
	input();
	result[1] = 1; visited[1] = true;	// Start with vertex 1
	attempt(2);		// Try to select the second vertex on the path
	return 0;
}