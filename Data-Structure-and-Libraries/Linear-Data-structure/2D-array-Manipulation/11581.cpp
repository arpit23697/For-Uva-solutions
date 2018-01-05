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

long long int a[3][3];


bool check ()
{
	int flag = 0;
	for (int i =0 ; i < 3 ;i++)
		for (int j =0; j <3 ; j++)
			if (a[i][j] == 0)
				flag++;

	if (flag == 9)
		return true;
	else
		return false;

}

bool exist (int i , int j)
{
	if (i >= 0 && i < 3 && j >= 0 && j < 3)
		return true;

	return false;
}

void update ()
{
	int temp[3][3];

	for (int i = 0 ; i < 3 ; i++)
		for (int j =0 ; j < 3 ; j++)
			temp[i][j] = a[i][j];

	for (int i =0 ; i < 3 ; i++)
		for (int j = 0 ; j < 3 ; j++)
		{
			int value = 0;
			if (exist (i-1 , j))
				value += temp[i-1][j];

			if (exist (i , j-1))
				value += temp[i][j-1];

			if (exist (i , j+1))
				value += temp[i][j+1];

			if (exist (i+1 , j))
				value += temp[i+1][j];

			a[i][j] = value%2;
		}

}

int main ()
{
	int test;
	cin >> test;

	while (test--)
	{
		int x;

		

		
		for (int i =0 ; i < 3 ; i++)
		{

			cin >> x;
		
			a[i][0] = x % 10;
			x = x/10;
			a[i][1] = x % 10;
			x = x/10;
			a[i][2] = x % 10; 
		}

		int ans = -1;
		while (1)
		{
			//cout << "hi\n";
		
		if (check() == true)
			break;

		else
				update();
		
			ans ++;
		}

		cout << ans <<endl;

	}
	return 0;	
}