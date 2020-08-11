// Fleury algorithm to find Eulerian circuit
#include<iostream>
using namespace std;

int a[100][100];
int n;

void input()
{
	// Initialisation
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = 0;

	// Get input
	int m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, k;
		cin >> u >> v >> k;
		a[u][v] = k;
		a[v][u] = k;
	}
}

// Determine whether v can go back to u when edge (u,v) is eliminated
// We can use either DFS or BFS to check, but we choose BFS over DFS because BFS goes with shorter path
bool canGoBack(int u, int v)
{
	int queue[100] = { 0 };
	int front = 1, rear = 1;		// Queue's pointers
	bool visited[100] = { false };	// Checking visited vertices
	a[u][v]--;	a[v][u]--;			// Eliminate the edge
	queue[1] = v;					// Enqueue v
	while (front <= rear)
	{
		int i = queue[front++];		// Dequeue
		visited[i] = true;
		for (int j = 1; j <= n; j++)
		{
			if (!visited[j] && a[i][j] > 0)	// If j hasn't been visited and there is an edge between i,j
			{
				queue[++rear] = j;	// Enqueue j
				visited[j] = true;	// Mark j
				if (visited[u]) break;	// If already comeback to u, break
			}
		}
	}
	a[u][v]++;	a[v][u]++;			// Return the edge eliminated before
	return visited[u];
}

void solve()
{
	int current = 1;	// Start at vertex 1
	int next;
	cout << 1 << " ";
	do
	{
		next = 0;
		for (int i = 1; i <= n; i++)	// Go with any direction the current vertex can go, edges that can go back is the first priority
		{
			if (a[current][i] > 0)
			{
				next = i;
				if (canGoBack(current, next)) break;	// If this edge is a "can go back" edge, pick it
			}
		}
		if (next != 0)					
		{
			cout << next << " ";
			a[current][next]--;	a[next][current]--;		// Eliminate the edge
			current = next;
		}
	} while (next != 0);	// Until no more vertices to visit
}

int main()
{
	input();
	solve();
	return 0;
}