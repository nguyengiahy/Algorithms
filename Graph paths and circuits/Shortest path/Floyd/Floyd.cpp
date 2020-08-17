#include <iostream>
using namespace std;

const int MAXV = 1000, INF = 1000;
int c[MAXV][MAXV];
int trace[MAXV][MAXV];		// trace[u][v]: vertex after u on the shortest path from u->v
int n, s, f;

void input()
{
	int m;
	cin >> n >> m >> s >> f;

	// Initialisation
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				c[i][j] = 0;
			else
				c[i][j] = INF;		// Infinity cost if there is no edge between i,j
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			trace[i][j] = j;		// Assume shortest path from i->j is the direct edge connecting i to j

	// Get input
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		cin >> c[u][v];
	}
}

void Floyd()
{
	for (int k = 1; k <= n; k++)
		for (int u = 1; u <= n; u++)
			for (int v = 1; v <= n; v++)
			{
				if (c[u][v] > c[u][k] + c[k][v])
				{
					c[u][v] = c[u][k] + c[k][v];
					trace[u][v] = trace[u][k];
				}
			}
}

void output()
{
	if (c[s][f] == INF)
		cout << "There is no path from " << s << " to " << f << endl;
	else
	{
		cout << "Distance from " << s << " to " << f << ": " << c[s][f] << endl;
		while (s != f)
		{
			cout << s << "->";
			s = trace[s][f];
		}
		cout << f;
	}
}

int main()
{
	input();
	Floyd();
	output();
	return 0;
}