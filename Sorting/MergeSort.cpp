#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include<iostream>
//#include <fstream>

using namespace std;

// Global variables
int const maxIndex = 100;
int z[maxIndex];
int k[maxIndex];
int n;

void merge(int x[], int y[],int a, int b, int c)
{
	int i, j, p;
	i = a; // chay tu a, boi vi a duoc thay doi trong mergeByLength
	j = b +1; // chay tu first element of mach thu 2
	p = a; // chay trong sorted array.
	while ((i <= b) && (j <= c))
	{
		if (x[i] < x[j])
		{
			y[p] = x[i];
			i++;
		}
		else
		{
			y[p] = x[j];
			j++;
		}
		p++;
	}
	// Mach thu 2 da het.
	if (i <= b)
	{
		for (int q = i; q <= b; q++)
		{
			y[p] = x[q];
			p++;
		}
	}
	// Mach thu nhat da het.
	else
	{
		for (int q = j; q <= c; q++)
		{
			y[p] = x[q];
			p++;
		}
	}
}

void mergeByLength(int x[],int y[],int len)
{
	int a, b, c;
	// a starts from the first element.
	a = 1;
	// b will indicate the middle, the actual second half array is started with len + 1.
	b = len;
	// c is the final array element.
	c = len * 2;
	while (c <= n)
	{
		merge(x, y, a, b, c);
		a += len * 2;
		b += len * 2;
		c += len * 2;
	}
	// There is two cases. 2 arrays left, the right one is shorter
	if (b < n)
	{
		merge(x, y, a, b, n);
	}
	else
	{
		// Check there is available 1 left array and that's it. Then copy the firs array into the actual sorted array.
		if (a <= n)
		{
			for (int g = a; g <= n; g++)
			{
				y[g] = x[g];
			}
		}
	}
}

// main function
int main()
{

	//init
	n = 10;
	z[1] = 3;
	z[2] = 6;
	z[3] = 5;
	z[4] = 4;
	z[5] = 9;
	z[6] = 8;
	z[7] = 1;
	z[8] = 0;
	z[9] = 2;
	z[10] = 7;
	
	// length starts with 0.
	int len = 1;
	bool flag = true;
	while (len < n)
	{
		if (flag)
		{
			// The target is array z, and the sorted result will be stored in k;
			mergeByLength(z, k, len);
		}
		else
		{
			mergeByLength(k, z, len);
		}
		flag = not flag;
		len = len * 2;
			
	}
	// Flag has been toggled.
	if (flag)
	{
		for (int o = 1; o <= n; o++)
		{
			k[o] = z[o];
			cout << z[o];
			if (o != n)
				cout << " ";
		}
	}


}