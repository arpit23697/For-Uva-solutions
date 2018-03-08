
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
	long long int cases;
	cin >>cases;

	long long int m = 0;
	while (cases--)
	{
		m++;
		int n;
		cin >> n;
		long long int width[n];
		long long int height[n];

		for (int i =0 ; i < n ; i++)
			cin >> height[i];

		for (int i = 0 ; i < n ; i++)
			cin >> width[i];

		long long int A[n];
		long long int B[n];

		for (int i = 0; i < n ; i++)
		{
			A[i] = width[i];
			for (int j = 0 ; j < i ; j++)
			{
				if (height[j] < height[i])
					A[i] = max (A[i] , width[i] + A[j]);
			}
		}

		for (int i = 0; i < n ; i++)
		{
			B[i] = width[i];
			for (int j = 0 ; j < i ; j++)
			{
				if (height[j] > height[i])
					B[i] = max (B[i] , width[i] + B[j]);
			}
		}


		long long int increasing = 0 , decreasing = 0;
		for (int i = 0 ; i < n ; i++)
		{
			increasing = max (increasing , A[i]);
			decreasing = max (decreasing , B[i]);
		}

		if (increasing >= decreasing)
			printf ("Case %lld. Increasing (%lld). Decreasing (%lld).\n", m , increasing , decreasing );
		else
			printf ("Case %lld. Decreasing (%lld). Increasing (%lld).\n", m , decreasing , increasing );


	}


	fclose (stdin);
	fclose (stdout);
	return 0;
}