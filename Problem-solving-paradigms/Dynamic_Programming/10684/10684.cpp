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
	while (scanf ("%d",&n) == 1 && n != 0)
	{
		long long int a[n];
		for (int i = 0 ; i < n ; i++)
			cin >> a[i];

		long long int ans= -9999999;
		long long int sum= 0;
		for (int i = 0 ; i < n ; i++)
		{
			sum += a[i];
			ans = max (sum , ans);

			if (sum < 0)
				sum = 0;
		}

		if (ans <= 0)
			cout << "Losing streak." << endl;
		else
			cout << "The maximum winning streak is "<< ans <<"." << endl;
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}