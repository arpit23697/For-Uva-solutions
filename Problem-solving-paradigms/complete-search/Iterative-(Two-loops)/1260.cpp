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
	int test;
	cin >> test;
	
	while (test--)
	{
		long long int n;
		cin >> n;
		long long int a[n];
		for (long long int i =0 ; i < n ; i++)
			cin >> a[i];

		long long int ans = 0;
		for (int i = 1 ; i< n ; i++)
		{
			for (int j = 0 ; j < i ; j++ )
				if (a[j] <= a[i])
					ans++;
		}

		cout << ans << endl;

	}

	return 0;
}