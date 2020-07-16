#include <iostream>
using namespace std;

bool RLdiagonal[300], LRdiagonal[300], col[100];	//for checking conditions
int res[100];		//store results
int n;

bool check(int i, int j)
{
	//Check right-left diagonal
	if (!RLdiagonal[i + j])
		return false;

	//Check left-right diagonal
	if (!LRdiagonal[i - j + n - 1])
		return false;

	//Check column
	if (!col[j])
		return false;

	return true;
}

void print()
{
	for (int i = 0; i < n; i++)
	{
		cout << "(" << i + 1 << ", " << res[i] + 1 << "); ";
	}
	cout << endl;
}

void init()
{
	for (int i = 0; i <= 2 * n; i++)
	{
		RLdiagonal[i] = true;
		LRdiagonal[i] = true;
		if (i <= 100)
			col[i] = true;
	}
}

void attempt(int i)
{
	for (int j = 0; j < n; j++)		//j is the column
	{
		if (check(i, j))
		{
			res[i] = j;
			if (i == n - 1)
			{
				print();
			}
			else
			{
				//Mark the right-left diagonal
				RLdiagonal[i + j] = false;
				//Mark the left-right diagonal
				LRdiagonal[i - j + n - 1] = false;
				//Mark the column
				col[j] = false;

				attempt(i + 1);

				//Unmark the right-left diagonal
				RLdiagonal[i + j] = true;
				//Unmark the left-right diagonal
				LRdiagonal[i - j + n - 1] = true;
				//Unmark the column
				col[j] = true;
			}
		}
	}
}

int main()
{
	cin >> n;
	init();
	attempt(0);
	return 0;
}