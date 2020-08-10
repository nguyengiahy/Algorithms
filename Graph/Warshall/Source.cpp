#include <stdio.h>
#include <iostream>

using namespace std;

int const maxIndex = 20;

int a[maxIndex][maxIndex];
bool Free[maxIndex];

int VNumber;
int ENumber;






int main()
{
	int start;
	int end;
	// Initilisation
	VNumber = 12;
	ENumber = 9;

	for (int i = 0; i < VNumber; i++)
	{
		for (int j = 0; j < VNumber; j++)
		{
			if (i == j)
			{
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = 0;
			}

		}
	}
	// Existing edges
	a[1][3] = 1;
	a[1][5] = 1;
	a[1][4] = 1;
	a[2][4] = 1;
	a[6][7] = 1;
	a[6][8] = 1;
	a[9][10] = 1;
	a[9][11] = 1;
	a[11][12] = 1;

	a[3][1] = 1;
	a[5][1] = 1;
	a[4][1] = 1;
	a[4][2] = 1;
	a[7][6] = 1;
	a[8][6] = 1;
	a[10][9] = 1;
	a[11][9] = 1;
	a[12][11] = 1;


	// Warshall to find bao dong
	for (int k = 1; k <= VNumber; k++)
	{
		for (int u = 1; u <= VNumber; u++)
		{
			for (int v = 1; v <= VNumber; v++)
			{
				a[u][v] = a[u][v] or a[u][k] and a[k][v];
			}
		}
	}

	// Set all the vertices are free

	for (int f = 1; f <= VNumber; f++)
	{
		Free[f] = true;
	}
	
	// Print the result of groups which is connected.

	int counter = 0;

	for (int g = 1; g <= VNumber; g++)
	{
		if (Free[g])
		{
			counter++;
			cout << "The group number " << counter << " is:" << g << " ";
			Free[g] = false;
			for (int p = 1; p <= VNumber; p++)
			{
				if ((Free[p]) && (a[g][p]))
				{
					cout << p << " ";
					Free[p] = false;
				}
			}
			cout << endl;
		}

	}

	
	return 0;
}