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

int a[110000];
int n;

bool climbPossible (int k)
{
	for (int i = 0 ; i < n ; i++)
	{

		if (i == 0 && a[i] == k)
			k--;

		else if (i == 0 && a[i] > k)
			return false;

		else if (a[i] - a[i-1] == k)
			k--;

		else if (a[i] - a[i-1] > k)
			return false;

	}
	return true;
}


int main ()
{
	int test;
	int cases = 0;

	//freopen ("1.txt" , "r" , stdin);
	//freopen ("ans.txt" , "w" , stdout);
	cin >> test;

	while (test--)
	{
		cases++;

		scanf ("%d",&n);
		for (int i = 0 ; i < n ; i++)
			cin >> a[i];

		long long int low = 1;
		long long int high = 10000000;

		long long int ans = 10000000;
		long long int k;

		while (high - low >= 0)
		{

			k = (low + high)/2;
			//cout << low << " " << high << endl;

			

			if (climbPossible (k))
			{
				high = k-1 ;
				ans = k;
			//	cout << k << endl;
			}

			else
			{
				low = k+1;
			}
	//		cout << ans << endl;

		}
	
		cout << "Case " << cases << ": " << ans << endl;

	}

	//fclose (stdin);
	//fclose (stdout);

	return 0;
}