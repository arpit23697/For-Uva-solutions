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

bool yesItsTrue (bool a[][5] )
{
	//checking the diagonal
	int flag = 0;
	for (int i =0 ; i < 5 ; i++)
		if (a[i][i] == true)
			flag++;

	if (flag == 5)
		return true;

	flag = 0;
	for (int i =0 ; i < 5 ; i++)
		if (a[4-i][i] == true)
			flag++;

	if (flag == 5)
		return true;

	for (int i =0 ; i < 5 ; i++)
	{
		flag = 0;
		for (int j =0 ; j < 5 ; j++)
			if (a[i][j] == true)
				flag++;

		if (flag == 5)
			return true;
	}

	for (int i =0 ; i < 5 ; i++)
	{
		flag = 0;
		for (int j =0 ; j < 5 ; j++)
			if (a[j][i] == true)
				flag++;

		if (flag == 5)
			return true;
	}

	return false;
}

void update (int a[][5] , bool check[][5] , int value)
{
	int flag = 0;
	for (int i = 0 ; i < 5 ; i++)
	{
		for (int j =0 ; j < 5 ; j++)
		{
			if (a[i][j] == value)
			{
				check[i][j] = true;
				flag = 1;
				break;
			}
		}	
		if (flag == 1)
			break;
	}


}

int main ()
{
	int test;
	cin >> test;

	while (test--)
	{
		int array[5][5];
		array[2][2] = 0;

		for (int i =0 ; i < 2 ; i++)
			for (int j =0 ; j < 5 ; j++)
				scanf("%d",&array[i][j]);

		scanf("%d %d %d %d",&array[2][0] , &array[2][1] , &array[2][3] , &array[2][4]);

		for (int i =3 ; i < 5 ; i++)
			for (int j =0 ; j < 5 ; j++)
				scanf("%d",&array[i][j]);
	
		bool check [5][5];
		for (int i = 0 ; i < 5 ; i++)
			for (int j =0 ; j < 5 ; j++)
				check[i][j] = false;

		check[2][2] = true;

		int takeIt = 75;
		int ans = 0;
		while (takeIt--)
		{
			int value;
			scanf("%d",&value);
			update (array , check , value);
			ans++;
			if (yesItsTrue(check))
				break;
		}

		int temp;

		while (takeIt--)
			scanf("%d",&temp);

		cout << "BINGO after "  << ans << " numbers announced"<<endl;

	}

	return 0;


}