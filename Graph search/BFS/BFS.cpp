#include<iostream>
using namespace std;

int n, m, s, f;
bool a[100][100];
int trace[100];

void input()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = false;
		}
	}

	cin >> n >> m >> s >> f;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u][v] = true;
		a[v][u] = true;
	}

	for (int i = 1; i <= n; i++)
		trace[i] = 0;
	trace[s] = -1;
}

void BFS()
{
	int queue[100];
	int front = 1, rear = 1;
	queue[1] = s;			// push start vertice to the queue
	while (front <= rear)	// while queue is not empty
	{
		int u = queue[front++];		// pop the queue
		for (int v = 1; v <= n; v++)
		{
			if (a[u][v] && trace[v] == 0)		// if there is connection between u,v and v hasn't been visited yet
			{
				queue[++rear] = v;				// push v to the queue
				trace[v] = u;					
			}
		}
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
	cout << "From " << s << " you can visit:" << endl;
	for (int i = 1; i <= n; i++)
	{
		if (trace[i] != 0 && trace[i] != -1)
			cout << i << ", ";
	}

	cout << endl << "The path from " << s << " to " << f << ":" << endl;
	if (trace[f] == 0)
		cout << "No path found.";
	else
		tracePath(f);
}

int main()
{
	input();
	BFS();
	output();
	return 0;
}