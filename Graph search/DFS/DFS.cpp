#include<iostream>
using namespace std;

int n, m, s, f;
bool a[100][100];
int trace[100];

void input()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = false;			// Initialising no connection between i and j

	// Read input
	cin >> n >> m >> s >> f;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u][v] = true;
		a[v][u] = true;
	}

	// Initialise trace
	for (int i = 1; i <= n; i++)
		trace[i] = 0;
	trace[s] = -1;
}

void DFS(int u)
{
	for (int i = 1; i <= n; i++)
		if (a[u][i] && trace[i] == 0)		// If there is connection between u,i and i hasn't been visited yet
		{
			trace[i] = u;					// Save the path
			DFS(i);
		}
}

void tracePath(int i)
{
	if (trace[i] == -1)
	{
		cout << i << "->";
		return;
	}
	else
	{
		tracePath(trace[i]);
		cout << i;
		if (i != f)
			cout << "->";
	}
}

void output()
{
	// Print all the vertices that you can visit from s
	cout << "From " << s << " you can visit: " << endl;
	for (int i = 1; i <= n; i++)
	{
		if (trace[i] != 0 && trace[i] != -1)
			cout << i << ", ";
	}

	// Print the path from s to f
	cout << endl << "The path from " << s << " to " << f << ":" << endl;
	if (trace[f] == 0)
		cout << "Path not found";
	else
		tracePath(f);
}

int main()
{
	input();
	DFS(s);
	output();
	return 0;
}