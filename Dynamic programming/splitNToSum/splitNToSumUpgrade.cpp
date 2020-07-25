#include<iostream>
using namespace std;

int main()
{
	int n;
	int res[101] = { 0 };
	cin >> n;

	res[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
			res[j] = res[j] + res[j - i];
	}
	cout << res[n];

	return 0;
}