#include<iostream>
using namespace std;

int n;
int arr[100];
int F[100];					// Table of dynamic programming
int Trace[100] = { 0 };		// Table for tracing

// Get input
void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

// Tracing to get elements of the longest increasing subsequence
void traceBack(int pos)
{
	if (Trace[pos] == -1)
		return;
	traceBack(Trace[pos]);
	cout << arr[pos] << " ";
}

void solve()
{
	// F[i] is the length of the longest increasing subsequence from a[1] to a[i]
	for (int i = 1; i <= n; i++)	// Initialise F and Trace
	{
		F[i] = 1;
		Trace[i] = 0;
	}
	Trace[0] = -1;

	// Dynamic programming solution
	for (int i = 1; i <= n - 1; i++)
		for (int j = i + 1; j <= n; j++)
			if (arr[j] > arr[i] && F[i] + 1 > F[j])
			{
				F[j] = F[i] + 1;
				Trace[j] = i;
			}
}

void output()
{
	// Find and print result
	int res = F[1];		// Result
	int pos = 1;		// Position to call tracing
	for (int i = 2; i <= n; i++)
		if (F[i] > res)
		{
			res = F[i];
			pos = i;
		}
	cout << res << endl;		// Length of the longest increasing subsequence
	traceBack(pos);
}

int main()
{
	input();
	solve();
	output();
	return 0;
}