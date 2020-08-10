#include <stdio.h>
#include <iostream>

using namespace std;

int const maxIndex = 20;

int a[maxIndex][maxIndex];
int Trace[maxIndex];

int VNumber;
int ENumber;


void BFS(int u)
{
	int queue[maxIndex];
	int front;
	int rear;
	front = rear = 1;

	// enqueue
	queue[1] = u;
	int current;
	while (!(front > rear))
	{
		// dequeue
		current = queue[front];
		front++;

		for (int v = 1; v < VNumber; v++)
		{
			if ((Trace[v] == 0) && (a[current][v]))
			{
				Trace[v] = current;
				// enqueue
				queue[++rear] = v;
			}
		}
	}
	
}



int main()
{
	int start;
	int end;
	// Initilisation
	VNumber = 8;
	ENumber = 7;
	start = 1;
	end = 5;

	for (int i = 0; i < VNumber; i++)
	{
		for (int j = 0; j < VNumber; j++)
		{
			a[i][j] = 0;
		}
	}
	// Existing edges
	a[1][2] = 1;
	a[1][3] = 1;
	a[2][3] = 1;
	a[2][4] = 1;
	a[3][5] = 1;
	a[4][6] = 1;
	a[7][8] = 1;

	a[2][1] = 1;
	a[3][1] = 1;
	a[3][2] = 1;
	a[4][2] = 1;
	a[5][3] = 1;
	a[6][4] = 1;
	a[8][7] = 1;


	// Initialize trace
	for (int k = 0; k < maxIndex; k++)
	{
		Trace[k] = 0;
	}
	Trace[start] = -1;
	BFS(start);


	cout << "From " << start << " can visit: ";
	for (int k = 1; k <= VNumber; k++)
	{
		if (Trace[k] != 0)
		{
			cout << " " << k << " ";
		}
	}
	if (Trace[end] == 0)
	{
		cout << " There is no path to go from S to F" << endl;
	}
	else
	{
		cout << "The path from " << start << " to " << end << " :";
		int tracker = end;
		do
		{
			cout << tracker << "<-";
			tracker = Trace[tracker];
		} while (tracker != start);
		cout << start << endl;
	}


	return 0;
}