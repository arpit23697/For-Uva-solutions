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

int main ()
{
	freopen ("in.txt" , "r" , stdin);
	freopen ("out.txt" , "w" , stdout);

	int n;
	while (scanf("%d" , &n) == 1)
	{

	int sum[n+10][n+10];
	for (int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < n ; j++)
		{
			scanf ("%d",&sum[i][j]);
			if (i > 0) sum[i][j] += sum[i-1][j];
			if (j > 0) sum[i][j] += sum[i][j-1];
			if (i > 0 && j > 0) sum[i][j] -= sum[i-1][j-1];
		}

	int ans = -1000000000;
	for (int i =0 ; i < n ; i++)
		for (int j = 0 ; j < n ; j++)
			for (int k = i ; k < n ; k++)
				for (int l = j ; l < n ; l++)
				{
					int temp = 0;
					temp += sum[k][l];
					if (i > 0 ) temp -= sum[i-1][l];
					if (j > 0 ) temp -= sum[k][j-1];
					if (i > 0 && j > 0) temp += sum[i-1][j-1];
					ans = max (ans , temp);
				}

	cout << ans << endl;
	}
	fclose (stdin);
	fclose(stdout);
	return 0;
}