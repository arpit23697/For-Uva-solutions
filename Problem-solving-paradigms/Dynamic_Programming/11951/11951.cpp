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
	int cases = 0 , t;
	cin >> t;

	while (t--)
	{
		cases++;
		long long int n , m , cost;
		cin >> n >> m >> cost;
		long long int sum[n][m];

		for (int i = 0 ; i < n ; i++)
			for (int j = 0 ; j < m ; j++)
			{
				scanf ("%lld",&sum[i][j]);

				if (i > 0) sum[i][j] += sum[i-1][j];
				if (j > 0) sum[i][j] += sum[i][j-1];
				if (i > 0 && j > 0 ) sum[i][j] -= sum[i-1][j-1];
			}

		long long int maximalArea = 0;
		long long int TotalCost = 0;

		for (int i = 0 ; i < n ; i++)
			for (int j = 0 ; j < m ; j++)
				for (int k = i ; k < n ; k++)
					for (int l = j ; l < m ; l++)
					{

						long long int temp = sum[k][l];
						if (i > 0 )temp -= sum[i-1][l];
						if (j > 0 )temp -= sum[k][j-1];
						if (i > 0 && j > 0) temp += sum[i-1][j-1];
					


						long long int tempArea = (k - i + 1)*(l - j + 1);
						
						
						if (tempArea > maximalArea)
						{

							if (temp <= cost)
							{
								maximalArea = tempArea;
								TotalCost = temp;
							}
						}
						else if (tempArea == maximalArea)
						{
							if (temp <= cost)
							{
								maximalArea = tempArea;
								TotalCost = min (TotalCost , temp);
							}
						}

					}


		cout << "Case #" << cases << ": "  << maximalArea << " " << TotalCost << endl;
	}


	fclose (stdin);
	fclose (stdout);
	return 0;
}