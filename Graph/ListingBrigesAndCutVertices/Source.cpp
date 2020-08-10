#include <stdio.h>
#include <iostream>

using namespace std;

int const maxIndex = 100;

bool a[maxIndex][maxIndex];
bool Free[maxIndex];
int Number[maxIndex];
int Low[maxIndex];
int Parents[maxIndex];

int n, m;
int Count;





void Visit(int u)
{
	Count = Count++;
	Number[u] = Count;
	Low[u] = n+1; // A very big number.
	for (int v = 1; v <= n; v++)
	{
		if ((a[u][v]))
		{
			a[v][u] = 0;
			// Has not visited yet.
			//if (Number[v] != 0)
			if (Parents[v] == 0)
			{
				Parents[v] = u;
				Visit(v);
				if (Low[u] > Low[v])
				{
					Low[u] = Low[v];
				}
			}
			else
			{
				if (Low[u] > Number[v])
				{
					Low[u] = Number[v];
				}
			}
		}
	}
}
void Result() {
	int nChildren[maxIndex];
	bool isCut[maxIndex];
	for (int i = 1; i <= n; i++)
	{
		nChildren[i] = 0;
	}
	for (int v = 1; v <= n; v++)
	{
		if (Parents[v] != -1)
		{
			nChildren[Parents[v]]++;
		}
	}
	cout << "Bridges: " << endl;
	for (int v = 1; v <= n; v++)
	{
		int u = Parents[v];
		if ((u != -1) && (Low[v] >= Number[v]))
		{
			cout << "(" << u << "," << v << ")" << endl;
		}
	}
	cout << "Cut vertices: " << endl;
	for (int v = 1; v <= n; v++)
	{
		isCut[v] = false;
	}
	for (int v = 1; v <= n; v++)
	{
		// v is not a root
		if (Parents[v] != -1)
		{
			int u = Parents[v];
			if (Low[v] >= Number[u])
			{
				isCut[u] = (isCut[u] || (Parents[u] != -1) || (nChildren[u] >= 2));
			}
		}
	}
	for (int u = 1; u <= n; u++)
	{
		if (isCut[u])
		{
			cout << u << " ";
		}
	}

}

int main()
{
	//Enter
	// Initilisation
	n = 12;
	m = 14;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			a[i][j] = 0;
		}
	}
	// Existing edges
	a[1][2] = 1;
	a[2][1] = 1;
	a[1][3] = 1;
	a[3][1] = 1;
	a[2][3] = 1;
	a[3][2] = 1;
	a[2][4] = 1;
	a[4][2] = 1;
	a[2][5] = 1;
	a[5][2] = 1;
	a[2][7] = 1;
	a[7][2] = 1;
	a[3][6] = 1;
	a[6][3] = 1;
	a[4][5] = 1;
	a[5][4] = 1;
	a[4][7] = 1;
	a[7][4] = 1;
	a[5][10] = 1;
	a[10][5] = 1;
	a[6][8] = 1;
	a[8][6] = 1;
	a[6][9] = 1;
	a[9][6] = 1;
	a[8][9] = 1;
	a[9][8] = 1;
	a[11][12] = 1;
	a[12][11] = 1;
	// Initilize free vertice
	for (int k = 1; k <= n; k++)
	{
		Free[k] = true;
	}

	// Sovle and Init
	for (int k = 1; k <= n; k++)
	{
		Number[k] = 0;
	}
	Count = 0;
	for (int k = 1; k <= n; k++)
	{
		Parents[k] = 0;
	}

	for (int k = 1; k <= n; k++)
	{
		// Havent visited yet.
		if (Parents[k] == 0)
		{
			// Let vertice k as a root.
			Parents[k] = -1;
			Visit(k);
		}
	}


	// Instead of adding a fake vertice x and paths between x and all vertices, let call each of them like:
	for (int g = 1; g <= n; g++)
	{
		if (Number[g] == 0)
			Visit(g);
	}
	Result();
	return 0;
}