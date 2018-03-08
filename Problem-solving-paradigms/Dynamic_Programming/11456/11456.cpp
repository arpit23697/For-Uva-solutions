//time limit exceeded
//LIS tells you longest possible sequence in we include that point

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

	int cases;
	cin >> cases;

	while (cases--)
	{
		long long int n;
		cin >> n;

		long long int a[n] , Max[n] , Min[n];
		for (int i =0 ; i < n ; i++)
			cin >> a[i];

		for (int i = n-1 ; i >= 0 ; i--)
		{
			Max[i] = 1;
			for (int j = i + 1 ; j < n ; j++)
			{
				if (a[j] > a[i])
					Max[i] = max (Max[j] + 1 , Max[i]);
			}
		}

		for (int i = n-1 ; i >= 0 ; i--)
		{
			Min[i] = 1;
			for (int j = i+1 ; j < n ; j++)
			{
				if (a[j] < a[i])
					Min[i] = max (Min[j] + 1 , Min[i]);
			}
		}

		long long int ans = 0;
		for (int i = 0 ; i < n ;i++)
			ans = max (ans , Max[i] + Min[i] - 1);

		cout << ans << endl;
	}
	fclose (stdin);
	fclose (stdout);
}