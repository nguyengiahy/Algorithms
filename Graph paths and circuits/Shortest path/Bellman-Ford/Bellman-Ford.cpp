#include<iostream>
using namespace std;

const int INF = 99999;

int n, s, f;			// Number of vertices, source vertex, destination vertex
int c[1000][1000];		// c[u][v]: weight of the edge connecting u and v
int d[1000];			// d[u]: distance from s to u
int trace[1000];	


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
		d[i] = INF;
	d[s] = 0;

	// Get input
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		cin >> c[u][v];
	}
}

void Bellman_Ford()
{
	// The algorithm repeats for maximum n-1 times because n-1 is the maximum length of a shortest path. 
	// After i iterations, you will get the shortest path from s to vertices that have i edges far away from s. 
	// For example after the first iteration, you'll only have the shortest path from s to its neighbours. After the second iteration, you'll have the shortest path from s to v 
	// where v are the neighbours of s's neighbours.
	for (int countLoop = 1; countLoop <= n - 1; countLoop++)		
	{
		bool stop = true;
		for (int u = 1; u <= n; u++)
			for (int v = 1; v <= n; v++)
			{
				if (d[v] > d[u] + c[u][v])
				{
					d[v] = d[u] + c[u][v];
					trace[v] = u;
					stop = false;
				}
			}
		if (stop) break;		
	}
	// The algorithm ends when there is no more d[v] to fix or it has already looped for n-1 times
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
	Bellman_Ford();
	output();
	return 0;
}