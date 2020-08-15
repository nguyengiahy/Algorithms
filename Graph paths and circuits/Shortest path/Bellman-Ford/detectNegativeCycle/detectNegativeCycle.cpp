#include<iostream>
using namespace std;

const int INF = 99999;

int n;					// Number of vertices, source vertex, destination vertex
int c[1000][1000];		// c[u][v]: weight of the edge connecting u and v
int d[1000];			// d[u]: distance from s to u


void input()
{
	int m;
	cin >> n >> m;

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
		d[i] = INF;
	d[1] = 0;

	// Get input
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		cin >> c[u][v];
	}
}

int min(int a, int b)
{
	if (a < b) return a;
	else return b;
}

bool detectNegativeCycle()
{
	bool result = false;
	// Bellman-Ford algorithm
	for (int countLoop = 1; countLoop <= n - 1; countLoop++)
		for (int u = 1; u <= n; u++)
			for (int v = 1; v <= n; v++)
				d[v] = min(d[u] + c[u][v], d[v]);

	// Detect negative cycle
	for (int u = 1; u <= n; u++)
		for (int v=1;v<=n;v++)
			if (d[v] > d[u] + c[u][v])
			{
				result = true;
				break;
			}
	return result;
}

int main()
{
	input();
	if (detectNegativeCycle())
		cout << "Yes";
	else
		cout << "No";
	return 0;
}