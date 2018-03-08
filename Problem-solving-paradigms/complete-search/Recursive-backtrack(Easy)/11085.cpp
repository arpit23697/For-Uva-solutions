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

int row[8] , LineCounter , confg[92][8];

bool place (int r , int c)
{
	for (int prev = 0 ; prev < c ; prev++ )
		if (row[prev] == r || (abs (prev - c)) == abs (row[prev] - r))
			return false;

	return true;
}


void backtrack (int c)
{
	if (c == 8 )
	{
		
		for (int i = 0 ; i < 8 ; i++)
			confg[LineCounter][i] = row[i] + 1;
	
		LineCounter++;
	}
	else
	{	
		for (int r = 0 ; r < 8 ; r++)
		if (place (r , c))
		{
			row[c] =r ;
			backtrack(c+1);
		}
	}
}




int main ()
{
	LineCounter = 0;
	memset (row , 0 , sizeof row);
	backtrack(0);

	int a[8];
	int cases = 0;
	while (scanf("%d",&a[0]) == 1 )
	{
		cases++;

		for (int i = 1 ; i < 8 ; i++)
			scanf("%d",&a[i]);
		
		int min = INT_MAX;

		for (int i = 0 ; i < 92 ; i++)
		{	
			int sum = 0;
			for (int j = 0 ; j < 8 ; j++)
				if (confg[i][j] != a[j])
					sum++;

			//cout << sum << endl;
			if (sum < min)	
				min = sum;
		}

		cout << "Case " << cases << ": " << min << endl;
	}

	return 0;
}