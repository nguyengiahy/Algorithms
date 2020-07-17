/*
Xuat tat ca cac day nhi phan co do dai N
*/
#include <iostream>
using namespace std;

int main()
{
	int n; 		//length of binary sequence
	int result[100];	//store elements of a binary sequence
	bool flag = true;
	cin >> n;
	//Initialise
	for (int i = 0; i < n ; i++)
		result[i] = 0;
		
	//generation algorithm
	while (flag)
	{
		//Print the current set
		for (int i = 0; i < n ; i++)
			cout << result[i];
		cout<<endl;
		
		int i = n-1;		//current index
		//Find the first zero in the sequence
		while (i>=0 && result[i] == 1)
			i--;
		//If the first zero is found
		if (i >= 0)
		{
			result[i] = 1;
			for (int j = i+1; j < n; j++)
				result[j] = 0;
		}
		//If the first zero is not found -> completed
		else
		{
			flag = false;		//stop the program
		}
	} 
	return 0;
}
