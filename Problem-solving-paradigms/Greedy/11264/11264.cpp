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
	int test;
	cin >> test;

	while (test--)
	{
		long long int n;
		cin >> n;
		long long int a[n];

		for (int i = 0 ; i < n ; i++)
			cin >> a[i];

		int ans = 0;
		long long int total = 0;

		for (int i = 0 ; i < n-1 ; i++)
		{
			if (total + a[i] < a[i+1])
			{
				ans++;
				total += a[i];
			}
		}

		total += a[n-1];
		ans++;

		cout << ans << endl;
	}

	fclose (stdin);
	fclose (stdout);
	return 0;
}