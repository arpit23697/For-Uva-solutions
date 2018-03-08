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
	//freopen ("1.txt" , "r" , stdin);
	//freopen ("ans.txt" , "w" , stdout);

	int n;
	while (scanf ("%d",&n) != EOF)
	{
		vector <int> vec;
		vec.assign (n , 0);
		for (int i =0 ; i < n ; i++)
			cin >> vec[i];

		int sum;
		cin >> sum;
		int a , b;
		sort (vec.begin () , vec.end());
		int mini = INT_MAX;

		int ans1 , ans2 ;
		for (int i = 0 ;i < n ; i++)
		{
			a = vec[i];
			b = sum - vec[i];
			vec[i] = -1;
			if (binary_search (vec.begin () , vec.end () , b) && a - b < mini)
			{
				ans1 = min (a , b);
				ans2 = max (a , b);
				mini = ans2 - ans1;
			}

			vec[i] = a;
		}
		cout << "Peter should buy books whose prices are " << ans1 << " and " << ans2 << "."<< endl;
		cout << endl;
	}

	//fclose (stdin);
	//fclose (stdout);
	return 0;
}