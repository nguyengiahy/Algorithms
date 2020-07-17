#include<iostream>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int n;
	int arr[100];
	bool flag = true;
	cin >> n;
	
	//Initialise
	for (int i = 0; i < n; i++)
		arr[i] = i+1;
		
	//Generation algorithm
	while (flag)
	{
		//Print current set
		for (int i = 0; i < n; i++)
			cout << arr[i];
		cout << endl;
		
		//Find the first element from bottom up, which is not in increasing order
		int i = n - 2;
		while (i>=0 && arr[i] > arr[i+1])
			i--;
		//If found
		if (i >= 0)
		{
		    //Find the first element in the decreasing sequence which is greater than arr[i]
		    int k = n-1;
		    while (arr[k] < arr[i] && k>i) 
		        k--;
		    if (k>i)
		    {
    		    swap(arr[k], arr[i]);
    		    int a = i+1; 
    		    int b = n-1;
    		    while (a<b)
    		    {
    		        swap(arr[a], arr[b]);
    		        a++;
    		        b--;
    		    }
		    }
		}
		else
		{
			flag = false;
		}
	}
	return 0;
}
