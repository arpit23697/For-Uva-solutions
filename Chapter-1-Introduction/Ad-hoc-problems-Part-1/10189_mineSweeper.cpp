#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

bool exist (int i , int j , int rows , int cols)
{
	if (i >= 0 && i < rows && j >= 0 && j < cols)
		return true ;
	else
		return false;
}
int main ()
{
	int rows , cols;
	cin >> rows >> cols ;

	int m = 0;
	while (1)
	{
		m++;
		char a[rows][cols];
		string str;

		for (int i =0 ; i < rows ; i++)
		{
			cin >> str;

			for (int j =0; j < cols ; j++)
				a[i][j] = str[j];
		}

		char ans[rows][cols];



		for (int i =0 ; i < rows ; i++)
			for (int j  =0 ; j < cols ; j++)
			{
				if (a[i][j] == '*')
					ans[i][j] = '*';
				else
					ans[i][j] = '0';
			}

		for (int i =0 ; i < rows ; i++)
			for (int j = 0; j < cols ; j++)
			{
				if (a[i][j] == '.')
					continue;

				else 
				{
					if (exist (i-1 , j -1 , rows , cols ) && ans[i-1][j-1] != '*')
						ans[i-1][j-1]++;

					if (exist (i-1 , j , rows , cols ) && ans[i-1][j] != '*')
						ans[i-1][j]++;

					if (exist (i-1 , j+1 , rows , cols ) && ans[i-1][j+1] != '*')
						ans[i-1][j+1]++;

					if (exist (i , j -1 , rows , cols ) && ans[i][j-1] != '*')
						ans[i][j-1]++;
					if (exist (i , j +1  , rows , cols ) && ans[i][j+1] != '*')
						ans[i][j+1]++;

					if (exist (i+1 , j -1 , rows , cols ) && ans[i+1][j-1] != '*')
						ans[i+1][j-1]++;

					if (exist (i+1 , j , rows , cols ) && ans[i+1][j] != '*')
						ans[i+1][j]++;

					if (exist (i+1 , j+1 , rows , cols ) && ans[i+1][j+1] != '*')
						ans[i+1][j+1]++;

				}
			}

			cout << "Field #" << m <<":" <<endl;
			for (int i =0 ; i < rows ; i++)
			{
				for (int j = 0 ; j < cols ; j++)
				{
					cout << ans[i][j];
				}
				cout << endl;
			}



		cin >> rows >> cols;
		if (rows == 0 && cols == 0)
			break;
		else
			cout << endl;
	}

	return 0;
}