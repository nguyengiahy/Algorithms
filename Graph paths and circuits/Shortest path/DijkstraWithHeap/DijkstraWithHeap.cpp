// Time complexity: O(max(n,m).logn), faster than normal Dijkstra which is O(n^2)
#include <iostream>
#include <fstream>
using namespace std;

const int MAXV = 10000, MAXE=100000, MAXEC=100000, INF = 999999;
int adjCost[MAXEC];		// Weight of edges
int adj[MAXE];			// Adjacent list
int head[MAXV + 1];		// Header in adjacent list
int d[MAXV];			// d[u]: distance from s to u
int pos[MAXV];			// pos[u]: position of u in heap
int heap[MAXV];			
int trace[MAXV];
bool isFree[MAXV];
int n, s, f, nHeap;		// Number of vertices in graph, source vertex, destinations vertex, number of vertices in heap

void input()
{
	fstream file;
	int m;

	// Read file first time: set up head array
	file.open("input.txt", ios::in);
	file >> n >> m >> s >> f;
	// Distribution counting: to set up head array
	for (int i = 1; i <= m; i++)
	{
		int u, v, c;
		file >> u >> v >> c;
		head[u]++;		
	}
	for (int i = 2; i <= n; i++)
		head[i] = head[i - 1] + head[i];
	// Now we have head[u] is the position in adjacent list which contains the last neighbour of u
	file.close();


	// Read file second time: set up adjacent list
	file.open("input.txt", ios::in);
	file.ignore(100, '\n');			// ignore the first line
	for (int i = 1; i <= m; i++)
	{
		int u, v, c;
		file >> u >> v >> c;
		adj[head[u]] = v;
		adjCost[head[u]] = c;
		head[u]--;
	}
	head[n + 1] = m;
	file.close();
}

void init()
{
	for (int i = 1; i <= n; i++)
	{
		d[i] = INF;
		isFree[i] = true;
	}
	d[s] = 0;
	nHeap = 0;		// Heap is initialised empty
}

void upHeap(int i)		// Move i to its correct position in the heap
{
	int child = pos[i];		// child is the position of i in heap
	if (child == 0)			// If i is not in heap => add i to heap
		child = ++nHeap;
	int parent = child / 2;

	// we are building min heap therefore d[heap[parent]] must be less than d[i]
	while (parent > 0 && d[heap[parent]] > d[i])	
	{
		heap[child] = heap[parent];		// parent node is pushed down to child node
		pos[heap[child]] = child;		// update position
		child = parent;					// keep going upward
		parent = child / 2;
	}
	// Now we've found the position of vertex i in the heap, put i in that position
	heap[child] = i;
	pos[i] = child;
}

int popHeap()		// Return root, swap root with the last node in heap and do heapify
{
	int result = heap[1];
	int v = heap[nHeap--];		// take the last node in heap and reduce nHeap
	int root = 1;
	while (root * 2 <= nHeap)	// while root is not leaf node
	{
		int child = root * 2;
		if (child + 1 <= nHeap && d[heap[child + 1]] < d[heap[child]])	// Find children has smaller d
			child++;
		if (d[heap[child]] >= d[v]) break;		// If found the position of v, exit
		heap[root] = heap[child];				// else move child to parent and update new position
		pos[heap[root]] = root;
		root = child;			// keep going downward
	}
	// Now we've done heapify, finish it by putting v in its correct position
	heap[root] = v;
	pos[v] = root;

	return result;
}

void Dijkstra()
{
	upHeap(s);		// Move s to its correct position in heap
	while (nHeap != 0)		// While heap is not empty
	{
		int u = popHeap();	// Take the vertex that has smallest d[u]
		if (u == f) break;	// If shortest path to destination is found => exit
		isFree[u] = false;	// Mark u
		for (int i = head[u] + 1; i <= head[u + 1]; i++)	// Run for u's neighbours stored in the adjacent list
		{
			int v = adj[i];
			if (isFree[v] && d[v] > d[u] + adjCost[i])		// If v is free and d[v] can be updated
			{
				d[v] = d[u] + adjCost[i];
				trace[v] = u;
				upHeap(v);		// Because d[v] has just been updated so position of v in the heap may changed
			}
		}
	}
}

void output()
{
	if (d[f] == INF)	// If no path found from s->f
	{
		cout << "There is no path from " << s << " to " << f << endl;
	}
	else
	{
		cout << "Distance from " << s << " to " << f << ": " << d[f] << endl;
		while (f != s)
		{
			cout << f << "<-";
			f = trace[f];
		}
		cout << s;
	}
}

int main()
{
	input();
	init();
	Dijkstra();
	output();
	return 0;
}