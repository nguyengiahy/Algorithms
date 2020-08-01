// Time complexity: O(n.k)
#include<iostream>
using namespace std;

int n, k;
int a[1000], amod[1000];
int F[1000][1000];

void input() 
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}

int max(int a, int b)
{
	if (a > b) return a;
	return b;
}

void solve()
{
	// F[i][j] is the length of the longest subsequence in a[1..i] whose sum mod k equals j.
	// First, without affecting the nature of the problem, we convert a[i] to a[i] mod k
	for (int i = 1; i <= n; i++)
		amod[i] = a[i] % k;
	// Initialise F
	for (int i = 0; i < k; i++)
		F[1][i] = INT_MIN;
	F[1][amod[1]] = 1;		// Due to the meaning of F[i][j], we initialise F[1][amod[1]] = 1

	// Dynamic programming
	for (int i = 2; i <= n ; i++)
		for (int j = 0; j < k; j++)
			F[i][j] = max(F[i - 1][j], F[i - 1][(j - amod[i] + k) % k] + 1);
}

void trace()
{
	int i = n;
	int j = 0;
	int sum = 0;
	while (i > 0)
	{
		if (F[i][j] == F[i - 1][j])
			i--;
		else
		{
			cout << "a[" << i << "] = " << a[i] << endl;
			sum += a[i];
			j = (j - amod[i] + k) % k;
			i--;
		}
	}
	cout << "Sum: " << sum;
}

void output()
{
	cout << F[n][0] << endl;
	trace();
}

int main()
{
	input();
	solve();
	output();
	return 0;
}