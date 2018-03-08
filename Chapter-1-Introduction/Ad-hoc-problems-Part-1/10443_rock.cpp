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

bool exist (int i , int j , int row , int col)
{
	if (i >= 0 && i < row && j >= 0 && j < col)
		return true;

	return false;
}


int main ()
{
	int test;
	cin >> test;
	for (int m = 0 ; m< test ; m++)
	{
		int row , col;
		int n;

		cin >> row >> col >> n;
		char array[row][col];
		string str;

		for (int i =0 ; i < row ; i++)
		{
			cin >> str;
			for (int j =0 ; j < col ; j++)
			{
				array[i][j] = str[j];
			}
		}

		char ans[row][col];
		for (int c = 0 ; c < n ; c++)
		{
			for (int i =0 ; i < row ; i++)
			{	
				for (int j =0 ; j < col ; j++)
				{
					if (array[i][j]  == 'R')
					{
							
							if (exist (i-1  , j , row , col) && array[i-1][j] == 'P')
								ans[i][j] = 'P';
							
							else if (exist (i  , j-1 , row , col) && array[i][j-1] == 'P')
								ans[i][j] = 'P';
							else if (exist (i  , j+1 , row , col) && array[i][j+1] == 'P')
								ans[i][j] = 'P';
			
							else if (exist (i+1  , j , row , col) && array[i+1][j] == 'P')
								ans[i][j] = 'P';
							
							else
								ans[i][j] = 'R';

					}

					else if (array[i][j]  == 'P')
					{
							
							if (exist (i-1  , j , row , col) && array[i-1][j] == 'S')
								ans[i][j] = 'S';
							
							else if (exist (i  , j-1 , row , col) && array[i][j-1] == 'S')
								ans[i][j] = 'S';
							else if (exist (i  , j+1 , row , col) && array[i][j+1] == 'S')
								ans[i][j] = 'S';
							
							else if (exist (i+1  , j , row , col) && array[i+1][j] == 'S')
								ans[i][j] = 'S';
							
							else
								ans[i][j] = 'P';

					}

					if (array[i][j]  == 'S')
					{
					
							if (exist (i-1  , j , row , col) && array[i-1][j] == 'R')
								ans[i][j] = 'R';
				
							else if (exist (i  , j-1 , row , col) && array[i][j-1] == 'R')
								ans[i][j] = 'R';
							else if (exist (i  , j+1 , row , col) && array[i][j+1] == 'R')
								ans[i][j] = 'R';
						
							else if (exist (i+1  , j , row , col) && array[i+1][j] == 'R')
								ans[i][j] = 'R';

							else
								ans[i][j] = 'S';

					}
				}
			}
			for (int i =0 ; i < row ; i++)
				for (int j = 0; j < col ; j++)
					array[i][j] = ans[i][j];
		}

		for (int i =0 ; i < row ; i++)
		{
			for (int j =0 ; j < col ; j++)
			{
				cout << ans[i][j];
			}
			cout << "\n";
		}

		if (m < test-1)
			cout << "\n";


	}

	return 0;
}