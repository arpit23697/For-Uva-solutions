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

	int cases ;
	scanf ("%d",&cases);
	while (cases--)
	{
		int m , n , o;
		scanf ("%d %d %d",&m , &n , &o);
		long long int sum[m][n][o];

		for (int i = 0; i < m ; i++)
			for (int j = 0 ; j < n ; j++)
				for (int k = 0 ; k < o ; k++)
				{
					scanf ("%lld",&sum[i][j][k]);
					if (i > 0) sum[i][j][k] += sum[i-1][j][k];
					if (j > 0) sum[i][j][k] += sum[i][j-1][k];
					if (k > 0) sum[i][j][k] += sum[i][j][k-1];
					if (i > 0 && j > 0) sum[i][j][k] -= sum[i-1][j-1][k];
					if (i > 0 && k > 0) sum[i][j][k] -= sum[i-1][j][k-1];
					if (j > 0 && k > 0 )sum[i][j][k] -= sum[i][j-1][k-1];
					if (i > 0 && j > 0 && k > 0) sum[i][j][k] += sum[i-1][j-1][k-1];
				}

		long long int ans = sum[0][0][0];
		for (int i = 0 ; i < m ; i++)
			for (int j = 0 ; j < n ; j++)
				for (int k = 0 ; k < o ; k++)
					for (int x = i ; x < m ; x++)
						for (int y = j ; y < n ; y++)
							for (int z = k ; z < o ; z++)
							{
								long long int temp;
								temp = sum[x][y][z];
								if (i > 0 )temp -= sum[i-1][y][z];
								if (j > 0) temp -= sum[x][j-1][z];
								if (k > 0) temp -= sum[x][y][k-1];
								if (i > 0 && j > 0) temp += sum[i-1][j-1][z];
								if (i > 0 && k > 0) temp += sum[i-1][y][k-1];
								if (j > 0 && k > 0 )temp += sum[x][j-1][k-1];
								if (i > 0 && j > 0 && k > 0 )temp -= sum[i-1][j-1][k-1];
								ans = max (temp , ans);
							}

		cout <<ans << endl;
		if (cases > 0)
			cout << endl;
	}


	fclose (stdin);
	fclose (stdout);
	return 0;
}