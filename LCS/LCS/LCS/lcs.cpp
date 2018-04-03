#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1  
#define _CRT_SECURE_NO_DEPRECATE 
#include<iostream>
#include<string.h>
#include<string>

using namespace std;
int main()
{
	string aa, bb;
	getline(cin, aa);
	getline(cin, bb);
	_int64 m = aa.length();
	_int64 n = bb.length();
	int c[100][100];
	for (int i = 0; i < m; i++)
	{
		c[i][0] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		c[0][i] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (aa[i-1] == bb[j-1])
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				if (c[i - 1][j] >= c[i][j - 1])
					c[i][j] = c[i - 1][j];
				else
					c[i][j] = c[i][j - 1];
		}
	}
	cout << c[m][n];
	return 0;

}