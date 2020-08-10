#include <stdio.h>
#include <iostream>

using namespace std;

int const maxIndex = 100;

bool a[maxIndex][maxIndex];
bool Free[maxIndex];
int Number[maxIndex];
int Low[maxIndex];
int Stack[maxIndex];

int n,m;
int Count;
int ComponentCount;
int Top;

// Return Smaller
int Smaller(int u, int v)
{
	if (u < v)
		return u;
	else
		return v;
}

// For stack
void Push( int v)
{
	Top++;
	Stack[Top] = v;
}

int Pop()
{
	Top--;
	return Stack[Top + 1];
}

void Visit(int u)
{
	Count = Count++;
	Number[u] = Count;
	Low[u] = Number[u];
	Push(u);
	for (int v = 1; v <= n; v++)
	{
		if ((a[u][v]) && Free[v])
		{
			// Has not visited yet.
			if (Number[v] != 0)
			{
				Low[u] = Smaller(Low[u], Number[v]);
			}
			else
			{
				Visit(v);
				Low[u] = Smaller(Low[u], Low[v]);
			}
		}
	}
	if (Low[u] == Number[u])
	{
		ComponentCount++;
		cout << "Component " << ComponentCount << ": " << endl;
		int output = 0;
		while (output != u)
		{
			output = Pop();
			Free[output] = false;
			cout << output << " ";
		}
		cout << endl;
	}
}

int main()
{
	//Enter
	// Initilisation
	n = 11;
	m = 15;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			a[i][j] = 0;
		}
	}
	// Existing edges
	a[1][2] = 1;
	a[1][8] = 1;
	a[2][3] = 1;
	a[3][4] = 1;
	a[4][2] = 1;
	a[4][5] = 1;
	a[5][6] = 1;
	a[6][7] = 1;
	a[7][5] = 1;
	a[8][9] = 1;
	a[9][4] = 1;
	a[9][10] = 1;
	a[10][8] = 1;
	a[10][11] = 1;
	a[11][8] = 1;

	// Initilize free vertice
	for (int k = 1; k <= n; k++)
	{
		Free[k] = true;
	}

	// Init
	for (int k = 1; k <= n; k++)
	{
		Number[k] = 0;
	}
	Top = 0; // empty stack
	Count = 0;
	ComponentCount = 0;
	
	// Instead of adding a fake vertice x and paths between x and all vertices, let call each of them like:
	for (int g = 1; g <= n ; g++)
	{
		if (Number[g] == 0)
		Visit(g);
	}
	return 0;
}