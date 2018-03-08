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

	int m = 0;
	while (cases--)
	{
		m++;
		long long int n;
		cin >> n;

		bool a[n];
		for (int i = 0; i < n ; i++)
		{
			char temp;
			cin >> temp;
			if (temp == '.')
				a[i] = true;
			else
				a[i] = false;
		}

		long long int ans = 0;
		for (int i =0 ; i < n ; i++)
		{
			if (a[i] == true)
			{
				ans++;
				a[i] = false;
				if (i+1 < n)
				a[i+1] = false;

				if (i+2 < n)
				a[i+2] = false;
			}
		}
		cout << "Case " << m << ": " << ans << endl;

	}

	fclose (stdin);
	fclose (stdout);
	return 0;
}