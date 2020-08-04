// Use BFS to check the connectivity of graph
#include <iostream>
using namespace std;

int n, m;
bool a[100][100];
bool visited[100];

void input()
{
	cin >> n >> m;
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
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u][v] = a[v][u] = true;
	}
}

void BFS(int i)
{
	int queue[100];
	int front = 1, rear = 1;
	queue[front] = i;
	
	while (front <= rear)
	{
		int u = queue[front++];
		visited[u] = true;
		cout << u << ", ";
		for (int v = 1; v <= n; v++)
		{
			if (a[u][v] && !visited[v])
			{
				queue[++rear] = v;
			}
		}
	}
}

void solve()
{
	int count = 0;
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