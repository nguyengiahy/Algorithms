#include<iostream>
using namespace std;

const int INF = 99999;
int c[1000][1000];			// c[u][v]: weight of the edge connecting u and v
int d[1000];				// d[u]: distance from s to u
int trace[1000];
bool isFree[1000];
int n, s, f;				// Number of vertices, source vertex, destination vertex

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
	{
		d[i] = INF;
		isFree[i] = true;
	}
	d[s] = 0;

	// Get input
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		cin >> c[u][v];
	}
}

void Dijkstra()
{
	while (true)
	{
		// Find u that has smallest value for d[u]
		int min = INF, u = 0;
		for (int i = 1; i <= n; i++)
			if (isFree[i] && d[i] < min)
			{
				min = d[i];
				u = i;
			}
		// Stop the algorithm if shortest path to destination is found or there is no more path to go (all of d[i] equal to INF)
		if (u == f || min == INF)
			break;
		// Mark u
		isFree[u] = false;
		// Use u to set d[v] 
		for (int v = 1; v <= n; v++)
			if (isFree[v] && d[v] > d[u] + c[u][v])
			{
				d[v] = d[u] + c[u][v];
				trace[v] = u;
			}
	}
}

void output()
{
	if (d[f] == INF)	// If no path found from s->f
	{
		cout << "There is no path from " << s << " to " << f << endl;
	}
	else
	{
		cout << "Distance from " << s << " to " << f << ": " << d[f] << endl;
		while (f != s)
		{
			cout << f << "<-";
			f = trace[f];
		}
		cout << s;
	}
}

int main()
{
	input();
	Dijkstra();
	output();
	return 0;
}