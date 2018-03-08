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
#include <stack>
#include <tuple>
#include <deque>
#include <map>
#include <set>
#include <queue>

using namespace std;

int matrix[210][210];
int row , col;
int current ;
int counter ;
vector <char> ans;

int check (int r1 , int c1 , int r2 , int c2)
{
	bool ones = false;
	bool zeros = false;
	for (int i =r1 ; i < r2 ; i++)
		for (int j = c1; j < c2 ; j++)
		{	
			if (matrix[i][j] == 1)
				ones = true;
			else if (matrix[i][j] == 0)
				zeros = true;

			if (ones && zeros)
				return -1;	
		}
	if (ones && zeros)
		return -1;
	else if (ones == true)
		return 1;
	else if (zeros == true)
		return 0;
}


void solve_B (int r1 , int c1 , int r2 , int c2)
//r2 and c2 are exclusive
{

	if (r1 == r2 || c1 == c2)
		return ;

	else
	{


		int x = check(r1 , c1 , r2 , c2);
		if (x == 0)
			ans.push_back ('0');
		else if (x ==1 )
			ans.push_back ('1');
		else if (x == -1)
		{
			ans.push_back ('D');
			int mid_x = r1 + (r2 - r1 + 1)/2;
			int mid_y = c1 + (c2 - c1 + 1)/2;


			solve_B (r1 , c1 , mid_x , mid_y);
			solve_B (r1 , mid_y , mid_x , c2);
			solve_B (mid_x , c1 , r2 , mid_y );
			solve_B (mid_x , mid_y , r2 , c2);
 		}

 		
	}
}

void solve_D (int r1 , int c1 , int r2 , int c2 )
{
	if (r1 == r2 || c1 == c2)
		return;

	else
	{
		char temp;
		cin >> temp;
		if (temp == 'D')
		{

			int mid_x = r1 + (r2 - r1 + 1)/2;
			int mid_y = c1 + (c2 - c1 + 1)/2;


			solve_D (r1 , c1 , mid_x , mid_y  );
			solve_D (r1 , mid_y , mid_x , c2);
			solve_D (mid_x , c1 , r2 , mid_y );
			solve_D (mid_x , mid_y , r2 , c2);
		}

		else if (temp == '1')
		{
			for (int i =r1 ; i < r2 ; i++ )
				for (int j = c1 ; j < c2 ; j++)
					matrix[i][j] = 1;
		}

		else if (temp == '0')
		{
			for (int i =r1 ; i < r2 ; i++ )
				for (int j = c1 ; j < c2 ; j++)
					matrix[i][j] = 0;
		}
	}
}

int main ()
{
	//freopen ("ans.txt" , "w" , stdout);
	char c;
	while (1)
	{
		cin >> c;
		if (c == '#')
			break;
		cin >> row >> col ;
		
		
		counter = 0;
		ans.clear();

		if (c == 'B')
		{
			
			
			printf("D%4d%4d\n",row , col);
			for (int i = 0; i < row ; i++)
				for (int j = 0; j < col ; j++)
					{
						char temp;
						cin >> temp;
						matrix[i][j] = temp - '0';
					}

			solve_B (0 , 0 ,row , col);


			int size = ans.size();
			for (int i =0 ; i <  size; i++)
			{
				cout << ans[i];
				counter++;
				if (counter >= 50)
				{
					cout << endl;
					counter = 0;
				}
			}
			if (size % 50 != 0)
			cout << endl;
		}

		else if (c == 'D')
		{
			printf("B%4d%4d\n",row , col);
			current = -1;
			solve_D ( 0 , 0 , row , col );
			for (int i =0 ; i < row ; i++)
				for (int j = 0 ; j < col ; j++)
				{	
					cout << matrix[i][j] ;
					counter++;
					if (counter >= 50)
					{
						cout << endl;
						counter = 0;
					}
				}
			if ((row * col) % 50 != 0)
			cout << endl;

		}
	}

	//fclose (stdout);

	return 0;
}