#include<iostream>
using namespace std;

const int MAXINT = INT_MAX;
const int maxNum = 101;
int n, m;				// n: number of cities, m: number of connections between cities
int C[maxNum][maxNum];	// cost to go from city i to city j
int bestConfig = MAXINT;// lowest cost to travel all cities
int x[maxNum], result[maxNum], sum[maxNum];	//x : test vector, result: final path with lowest cost, sum: cost to go from city 1 to city i.
bool visit[maxNum];		// track if a city has been visited

void readInput()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		cin >> C[x][y];
		C[y][x] = C[x][y];
	}
}

void init()
{
	for (int i = 1; i <= n; i++)
	{
		visit[i] = false;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				C[i][j] = 0;
			else if (C[i][j] == 0)
				C[i][j] = MAXINT;
		}
	}

	x[1] = 1;
	visit[1] = true;
	sum[1] = 0;
}

void updateResult()
{
	for (int i = 1; i <= n; i++)
	{
		result[i] = x[i];
	}
}

void attempt(int i)
{
	for (int j = 2; j <= n; j++)
	{
		if (C[x[i - 1]][j] != MAXINT && x[i - 1] != j && !visit[j])
		{
			x[i] = j;
			sum[i] = sum[i - 1] + C[x[i - 1]][j];
			if (sum[i] < bestConfig)
			{
				if (i == n && sum[i] + C[x[n]][1] < bestConfig)
				{
					bestConfig = sum[i] + C[x[n]][1];
					updateResult();
				}
				else
				{
					visit[j] = true;
					attempt(i + 1);
					visit[j] = false;
				}
			}
		}
	}
}

void printResult()
{
	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << "->";
	}
	cout << 1 << endl;
	cout << "Cost: " << bestConfig;
}

int main()
{
	readInput();
	init();
	attempt(2);
	printResult();
	return 0;
}