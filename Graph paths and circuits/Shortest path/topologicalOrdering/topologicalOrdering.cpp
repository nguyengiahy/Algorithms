// This algorithms only works when the graph is DAG - directed acyclic graph (directed graph that contains no cycle)
#include <iostream>
using namespace std;

const int MAXV = 1000, INF = 99999;
int n, s, f, topoCount;	// Number of vertices, source vertex, destination vertex, topological numbering
int c[MAXV][MAXV];		// c[u][v]: weight of the edge connecting u and v
int d[MAXV];			// d[u]: distance from s to u
int list[MAXV];			// vertices in topological order
int trace[MAXV];
bool visited[MAXV];

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
	

	// Get input
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		cin >> c[u][v];
	}
}

void init()
{
	for (int i = 1; i <= n; i++)
	{
		d[i] = INF;
		visited[i] = false;
	}
	d[s] = 0;
}

void visit(int i)
{
	visited[i] = true;
	for (int j = 1; j <= n; j++)
		if (!visited[j] && c[i][j] != INF)
			visit(j);
	list[topoCount] = i;
	topoCount--;
}

void topologicalOrdering()
{
	topoCount = n;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
			visit(i);
	}
}

void findPath()
{
	// Find position of source vertex and destination vertex in topo list
	int start = 0, end = 0;
	for (int i = 1; i <= n; i++)
	{
		if (list[i] == s)
			start = i;
		if (list[i] == f)
			end = i;
	}

	// Find shortest path from s->f
	for (int i = start; i <= end - 1; i++)
	{
		for (int j = i + 1; j <= end; j++)		// For all the vertices that i can go to, we update d[j]
		{
			int u = list[i];
			int v = list[j];
			if (d[v] > d[u] + c[u][v])
			{
				d[v] = d[u] + c[u][v];
				trace[v] = u;
			}
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
	init();
	topologicalOrdering();
	findPath();
	output();
	return 0;
}