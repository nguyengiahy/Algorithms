#include<iostream>
using namespace std;

bool a[100][100];
bool visited[100];
int n;

void input()
{
	// Initialisation
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = false;
	for (int i = 1; i <= n; i++)
		visited[i] = false;

	// Get input
	int m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u][v] = true;
		a[v][u] = true;
	}
}

void BFS(int u)
{
	int queue[100] = { 0 };
	int front = 1, rear = 1;
	queue[1] = u;
	visited[u] = true;
	while (front <= rear)		// While queue is not empty
	{
		int i = queue[front++];	// Dequeue
		for (int j = 1; j <= n; j++)
		{
			if (!visited[j] && a[i][j])		// If j hasn't been visited and there is an edge between i,j
			{
				queue[++rear] = j;			// Enqueue
				visited[j] = true;			
				cout << "(" << i << "," << j << ")" << endl;
			}
		}
	}
}

int main()
{
	input();
	BFS(1);		// Start from vertex 1
	return 0;
}