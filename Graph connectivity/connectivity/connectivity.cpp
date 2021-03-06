// Use BFS to check the connectivity of graph
#include <iostream>
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

// Use BFS(i) to visit all reachable vertices from i
void BFS(int i)
{
	int queue[100];
	int front = 1, rear = 1;
	queue[front] = i;				// Push first item to the queue
	
	while (front <= rear)
	{
		int u = queue[front++];		// Pop queue
		visited[u] = true;			// Mark as visited
		cout << u << ", ";			// Print
		for (int v = 1; v <= n; v++)
		{
			if (a[u][v] && !visited[v])
			{
				queue[++rear] = v;	// Push v to queue
			}
		}
	}
}

// Print all connected components
void solve()
{
	int count = 0;		// Number of connected components
	for (int u = 1; u <= n; u++)
	{
		if (!visited[u])
		{
			count++;
			cout << "Connected component " << count << ": " << endl;
			BFS(u);
			cout << endl;
		}
	}
}

int main()
{
	input();
	solve();
	return 0;
}