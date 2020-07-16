#include<iostream>
using namespace std;

int main()
{
	int n, k;
	int result[100];
	bool flag = true;
	
	cin >> n >> k;
	
	//Initialise
	for (int i = 0; i < k; i++)
	{
		result[i] = i+1;
	}
	
	//Generation algorithm
	while (flag)
	{
		//Print the current set
		for (int i = 0; i < k; i++)
		{
			cout << result[i];
		}
		cout << endl;
		
		int i = k - 1;		//index at the last element
		//Find the first element whose value is not at the upper limit
		while (i>=0 && result[i] == n-k+i+1)
			i--;
		//If found
		if (i>=0)
		{
			result[i]++;
			for (int j = i+1; j < n; j++)
				result[j] = result[j-1] + 1;
		}
		//If not found
		else
			flag = false;
	}
	return 0;
}
