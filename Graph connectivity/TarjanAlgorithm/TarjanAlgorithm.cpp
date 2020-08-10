#include<iostream>
using namespace std;

const int MAX = 100;

bool a[MAX][MAX];				// Adjacent matrix
bool isEliminated[MAX];			// isEliminated[i] = true if vertice i is no longer exists in the graph
int stack[MAX];					// Stack
int Number[MAX];				// Order of vertices when visit by DFS
int Low[MAX];					// Low-link value
int n;							// Number of vertices
int top = 0;					// Top of stack
int ordinalNum = 0;				// Ordinal number of vertices
int componentCount = 0;			// Number of strongly connected components

void input()
{
	// Initialisation
	// Initialise adjacent matrix
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = false;
	// Initialise elimination array
	for (int i = 1; i <= n; i++)
		isEliminated[i] = false;
	// Initialise Number array
	for (int i = 1; i <= n; i++)
		Number[i] = 0;

	// Get input
	int m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u][v] = true;
	}
}

int min(int a, int b)
{
	if (a < b) return a;
	else return b;
}

void Visit(int u)
{
	ordinalNum++;	Number[u] = ordinalNum;			// Mark u
	Low[u] = Number[u];								// Initialise low-link value
	stack[++top] = u;								// Push u to stack
	for (int v = 1; v <= n; v++)
	{
		if (!isEliminated[v] && a[u][v])			// If v hasn't been eliminated and there is an edge between u and v
		{
			if (Number[v] != 0)						// If v is visited already
				Low[u] = min(Low[u], Number[v]);
			else									// If v hasn't been visited
			{
				Visit(v);							// Visit v
				Low[u] = min(Low[u], Low[v]);
			}
		}
	}

	// Now, u is completely visited
	if (Number[u] == Low[u])		// If u is the cut point, we will print the elements in u's strongly connected component
	{
		componentCount++;
		cout << "Component " << componentCount << ":" << endl;
		while (stack[top + 1] != u)	// Repeat until reach u
		{
			int v = stack[top--];	// Pop stack
			cout << v << ", ";
			isEliminated[v] = true;	// Eliminate v from the graph
		}
		cout << endl;
	}
}

void solve()
{
	for (int i = 1; i <= n; i++)
		if (Number[i] == 0)			// If i hasn't been visited
			Visit(i);
}

int main()
{
	input();
	solve();
	return 0;
}